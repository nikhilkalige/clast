#!/usr/bin/env python
import glud
from glud import *
from clastgen.tools import clang_version, llvm_config
from clastgen.utils import *
from clastgen.clangext import *
from clastgen.context import *
from clastgen.filters import *
from clastgen.intermediate import *
from clastgen.templates import *
from clastgen.pagination import *
import ccsyspath
import os
import sys
import subprocess
import io
import json



def parse(src):
    """Parse a string of source code and return the translation unit
    """

    # Find the clang compiler 
    clang = os.path.join(os.environ['LLVM_HOME'], 'bin', 'clang++')

    # Find the system paths for the compiler
    syspath = ccsyspath.system_include_paths(clang)
    syspath = [ p.decode('utf-8') for p in syspath ]

    # Build up an appropriate set of compiler flags
    args = '-x c++ --std=c++11'.split()
    args += llvm_config('--cppflags')
    args += [ '-I' + inc for inc in syspath ]

    # Parse the source passed in
    return glud.parse_string(src, name='input.cpp', args=args)


def find_typedefs(tu, ctx):
    """Find interesting typedefs in a translation unit
    """
    matcher = typedefDecl(
        hasName('string'), 
        hasAncestor(
            namespaceDecl(
                hasName('std'))))

    for n in walk(matcher, tu.cursor):
        ctx.add_typedef(n)


def find_classes(tu, ctx):
    matcher = recordDecl(
        anyOf(isClass(), isStruct()),
        isDefinition(),
        anyOf(
            hasTypename('llvm::StringRef'),
            hasTypename('clang::TypeSourceInfo'),
            hasTypename('clang::Type'),
            hasTypename('clang::QualType'),
            hasTypename('clang::Qualifiers'),
            hasTypename('clang::DeclContext'),
            hasTypename('clang::DeclarationName'),
            hasTypename('clang::DeclarationNameInfo'),
            hasTypename('clang::SourceLocation'),
            hasTypename('clang::SourceRange'),
            hasTypename('clang::SourceManager'),
            hasTypename('clang::ASTContext'),
            isSameOrDerivedFrom('clang::Decl'),
            isSameOrDerivedFrom('clang::Stmt')),
        unless(hasName('clang::FriendDecl')),
        unless(hasTypename('clang::ConstructorUsingShadowDecl')),
        unless(hasName('.*ObjC.*')),
        unless(hasName('.*OMP.*')))

    for n in walk(matcher, tu.cursor):
        ctx.add_class(n)


def find_methods(ctx):
    matcher = cxxMethodDecl(
        isPublic(),

        # don't bind static methods
        unless(hasStaticStorageDuration()),

        # foo* is ok, foo& is ok, foo*& is not
        unless(hasAnyParameter(hasType(is_ref_to_ptr))),

        # foo* is ok, foo** is not
        unless(hasAnyParameter(hasType(limit_indirections(1)))),
        unless(hasReturnType(limit_indirections(1))),
        unless(
            anyOf(
                hasName('Allocate'),
                hasName('.*begin'),
                hasName('begin.*'),
                hasName('.*end'),
                hasName('end.*'),
                hasName('operator.*')
            ))
        )
    for c in ctx.classes:
        for n in iter_child_nodes(matcher, c):
            ndecl = n.get_definition()
            ctx.add_method(c, n)


def find_enums(ctx):
    """Identify enums used in the methods in the Context
    """
    res = {}
    for c, ms in iter(ctx.methods.items()):
        for m in ms:
            for t in dependent_types(m):
                ut = underlying_type(t)
                decl = ut.get_declaration()
                if ut.kind == TypeKind.ENUM and decl is not None:
                    if not (isProtected()(decl) or isPrivate()(decl)):
                        res[decl.hash] = decl
    for decl in res.values():
        parent = decl.semantic_parent
        if parent.kind != CursorKind.CLASS_DECL:
            ctx.add_enum(decl)
        elif parent.kind == CursorKind.CLASS_DECL and (parent in ctx.classes):
            ctx.add_enum(decl)


def resolve_deleters(ctx):
    decl_subclass  = isSameOrDerivedFrom('clang::Decl')
    stmt_subclass  = isSameOrDerivedFrom('clang::Stmt')

    for c in ctx.classes:
        assert c is not None
        assert type(c) == Cursor
        if decl_subclass(c):
            ctx.set_attr(c, deleter='decl_deleter<%s>::type' % c.type.spelling)
            ctx.set_attr(c, node=True)
        elif stmt_subclass(c):
            ctx.set_attr(c, deleter='stmt_deleter<%s>::type' % c.type.spelling)
            ctx.set_attr(c, node=True)
        else:
            ctx.set_attr(c, node=False)


def resolve_methods(ctx):
    void_ptr_arg_matcher = cxxMethodDecl(
            hasAnyParameter(hasType(
                    pointerType(pointee(
                        hasName('void'))))))

    def bool_ptr_arg_matcher(m):
        args = list(m.get_arguments())
        return (len(args) > 1) and is_bool_ptr(args[-1]) and (args[-1].spelling == 'Invalid')

    resolved = ctx.classes + ctx.enums + ctx.typedefs
    for c in ctx.classes:
        for m in ctx.class_methods(c):
            disabled = False
            mode = 'short'
            policy = None

            if not is_resolved_method(m, resolved):
                disabled = True
            if void_ptr_arg_matcher(m):
                disabled = True
            if not disabled:
                if is_overload(m):
                    mode = 'long'
                if bool_ptr_arg_matcher(m):
                    mode = 'aux'
            if m.result_type.kind == TypeKind.POINTER and m.result_type.get_pointee().kind == TypeKind.RECORD:
                policy = 'py::return_value_policy::reference_internal'
            
            ctx.set_attr(m, is_disabled=disabled)
            ctx.set_attr(m, mode=mode)
            ctx.set_attr(m, policy=policy)

            # # TODO - methods that need to change types (llvm::StringRef must be long)
            # # TODO - methods that return iterator_ranges must be custom
            # # TODO - methods that take in/out parameters must be custom


def resolve_disabled_classes(ctx):
    exclusions = set([
        'llvm::StringRef'
    ])
    for c in ctx.classes:
        disabled = c.type.spelling in exclusions
        ctx.set_attr(c, is_disabled=disabled)


def render_result(template, **kwargs):
    import jinja2
    from jinja2 import Environment, StrictUndefined
    
    loader = jinja2.DictLoader(clast_templates())
    env = Environment(trim_blocks = True, lstrip_blocks = True,
                      undefined = StrictUndefined, 
                      loader=loader)
    env.filters.update(clast_jinja_filters())
    return env.get_template(template).render(**kwargs)


def build_context(tu):
    ctx = Context()
    ctx.set_clang_version(clang_version())
    find_typedefs(tu, ctx)
    find_classes(tu, ctx)
    find_methods(ctx)
    find_enums(ctx)
    resolve_deleters(ctx)
    resolve_methods(ctx)
    resolve_disabled_classes(ctx)
    return ctx

c_src = '''
#include <clang/AST/AST.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>
'''

def codegen(ctx, path):
    intermediate = render_intermediate(ctx)

    def output_dir(fname, **kwargs):
        outfolder = os.path.join(path, 'generated')
        if not os.path.exists(outfolder):
            os.makedirs(outfolder)
        outfile = os.path.join(outfolder, fname)
        return open(outfile, 'w')

    with output_dir('intermediate.json') as fh:
        fh.write(json.dumps(intermediate, indent=4))

    with output_dir('00_autogen_enums.cpp') as fh:
        fh.write(render_result(template='enum_module.j2', model=intermediate)) 

    with output_dir('autogen_dyntypednode.cpp') as fh:
        fh.write(render_result(template='dyntyped_node_template.j2', model=intermediate)) 

    # in cases where optimisation is required, clast is so slow (and memory hungry)
    # to build, that you really want to divide the build process into smaller pieces
    pages = list(pagination(intermediate['classes'], chunksize=50))
    with output_dir('autogen_classes.cpp') as fh:
        fh.write(render_result(template='allclass_template.j2', model=intermediate, pagecnt=len(pages))) 

    for page in pages:
        with output_dir('%02d_autogen_classes.cpp' % (page.idx+1)) as fh:
            fh.write(render_result(template='class_module.j2', model=intermediate, page=page)) 

if __name__ == "__main__":
    if 'LLVM_HOME' not in os.environ:
        print('LLVM_HOME is undefined, giving up on code generation')
        sys.exit(1)

    import argparse

    default_output_dir = llvm_config('--version')[0].replace('.', '')
    default_output_dir = os.path.join('src', default_output_dir)
    parser = argparse.ArgumentParser('Generate clast code')
    parser.add_argument('-o', '--output',
                        default = default_output_dir,
                        help    = 'output directory');

    args = parser.parse_args(sys.argv[1:])
    tu = parse(c_src)
    ctx = build_context(tu)
    ctx.set_prelude(c_src)
    codegen(ctx, args.output)
    
