#!/usr/bin/env python
import glud
from glud import *
from clastgen.utils import *
from clastgen.clangext import *
from clastgen.context import *
from clastgen.filters import *
from clastgen.intermediate import *
from clastgen.templates import *
from clastgen.pagination import *
import ccsyspath
import collections
import os
import sys
import subprocess
import io
import json


def clang_version():
    llvm_home = os.environ['LLVM_HOME']
    binary = os.path.join(llvm_home, 'bin', 'clang')
    res = subprocess.check_output([binary, '--version']).splitlines()[0]
    if sys.version_info.major >= 3:
        return res.decode('utf-8')
    return res


def llvm_config(arg):
    llvm_home = os.environ['LLVM_HOME']
    llvm_config = os.path.join(llvm_home, 'bin', 'llvm-config')
    res = subprocess.check_output([llvm_config, arg]).split()
    if sys.version_info.major >= 3:
        return [p.decode('utf-8') for p in res]
    return res


def parse(src):
    syspath = ccsyspath.system_include_paths(os.path.join(os.environ['LLVM_HOME'], 'bin', 'clang++'))
    syspath = [ p.decode('utf-8') for p in syspath ]
    args = '-x c++ --std=c++11'.split()
    args += llvm_config('--cppflags')
    args += [ '-I' + inc for inc in syspath ]
    tu = glud.parse_string(src, name='input.cpp', args=args)
    return tu


def cxxRecordDeclEx(*args):
    return allOf(
                anyOf(
                    is_kind(CursorKind.STRUCT_DECL),
                    is_kind(CursorKind.CLASS_DECL)),
                *args)

def find_typedefs(tu, ctx):
    matcher = typedefDecl(
        hasName('string'), 
        hasAncestor(
            namespaceDecl(
                hasName('std'))))

    for n in walk(matcher, tu.cursor):
        ctx.add_typedef(n)

def find_classes(tu, ctx):
    matcher = cxxRecordDeclEx(
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
        is_public,

        # don't bind static methods
        unless(hasStaticStorageDuration()),

        # foo* is ok, foo& is ok, foo*& is not
        unless(anyArgument(hasType(is_ref_to_ptr))),

        # foo* is ok, foo** is not
        unless(anyArgument(hasType(limit_indirections(1)))),
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
    res = {}
    for c, ms in iter(ctx.methods.items()):
        for m in ms:
            for t in dependent_types(m):
                ut = underlying_type(t)
                decl = ut.get_declaration()
                if ut.kind == TypeKind.ENUM and decl is not None:
                    if not (is_protected(decl) or is_private(decl)):
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
        #print type(c), c.type.spelling, decl_subclass(c), stmt_subclass(c)
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
    resolved = ctx.classes + ctx.enums + ctx.typedefs
    for c in ctx.classes:
        for m in ctx.class_methods(c):
            disabled = not is_resolved_method(m, resolved)
            ctx.set_attr(m, is_disabled=disabled)
            if has_any_anonymous_arguments(m):
                ctx.set_attr(m, mode='short')
            #if any(is_bool_ptr(a) for a in m.get_arguments()):
            #    ctx.set_attr(m, mode='boolinvalid')


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

def codegen(path):
    tu = parse(c_src)
    ctx = build_context(tu)
    ctx.set_prelude(c_src)

    intermediate = render_intermediate(ctx)

    with open(os.path.join(path, 'intermediate.json'), 'w') as fh:
        fh.write(json.dumps(intermediate, indent=4))

    with open(os.path.join(path, '00_autogen_enums.cpp'), 'w') as fh:
        fh.write(render_result(template='enum_module.j2', model=intermediate)) 

    # in cases where optimisation is required, clast is so slow (and memory hungry)
    # to build, that you really want to divide the build process into smaller pieces
    pages = list(pagination(intermediate['classes'], chunksize=50))

    with open(os.path.join(path, 'autogen_classes.cpp'), 'w') as fh:
        fh.write(render_result(template='allclass_template.j2', model=intermediate, pagecnt=len(pages))) 

    with open(os.path.join(path, 'autogen_dyntypenode.cpp'), 'w') as fh:
        fh.write(render_result(template='dyntyped_node_template.j2', model=intermediate)) 

    for page in pages:
        with open(os.path.join(path, '%02d_autogen_classes.cpp' % (page.idx+1)), 'w') as fh:
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
    codegen(args.output)
