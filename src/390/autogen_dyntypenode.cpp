
////////////////////////////////////////////////////////////////////////////////
// File autogenerated by clastgen
//
//  Changes made here will be overwritten.
////////////////////////////////////////////////////////////////////////////////
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "internal.h"

#include <clang/AST/AST.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>


namespace py = pybind11;

namespace clatt = clang::ast_type_traits;

template<typename T>
const T* dyn_node_convert(const clatt::DynTypedNode& self)
{
    return self.get<T>();
}

void install_dyntypednode(pybind11::module& m) 
{
    py::class_<clatt::DynTypedNode>(m, "DynTypedNode")
        .def("getNodeKind", &clang::ast_type_traits::DynTypedNode::getNodeKind)
        .def("getSourceRange", &clang::ast_type_traits::DynTypedNode::getSourceRange)
        .def("__eq__", [](const clatt::DynTypedNode& self, const clatt::DynTypedNode& other) {
            return self == other;
        })
        .def("__ne__", [](const clatt::DynTypedNode& self, const clatt::DynTypedNode& other) {
            return self != other;
        })
        .def("_get_Decl", &clatt::DynTypedNode::get<clang::Decl>, py::return_value_policy::reference)
        .def("_get_TranslationUnitDecl", &clatt::DynTypedNode::get<clang::TranslationUnitDecl>, py::return_value_policy::reference)
        .def("_get_PragmaCommentDecl", &clatt::DynTypedNode::get<clang::PragmaCommentDecl>, py::return_value_policy::reference)
        .def("_get_PragmaDetectMismatchDecl", &clatt::DynTypedNode::get<clang::PragmaDetectMismatchDecl>, py::return_value_policy::reference)
        .def("_get_ExternCContextDecl", &clatt::DynTypedNode::get<clang::ExternCContextDecl>, py::return_value_policy::reference)
        .def("_get_NamedDecl", &clatt::DynTypedNode::get<clang::NamedDecl>, py::return_value_policy::reference)
        .def("_get_LabelDecl", &clatt::DynTypedNode::get<clang::LabelDecl>, py::return_value_policy::reference)
        .def("_get_NamespaceDecl", &clatt::DynTypedNode::get<clang::NamespaceDecl>, py::return_value_policy::reference)
        .def("_get_ValueDecl", &clatt::DynTypedNode::get<clang::ValueDecl>, py::return_value_policy::reference)
        .def("_get_DeclaratorDecl", &clatt::DynTypedNode::get<clang::DeclaratorDecl>, py::return_value_policy::reference)
        .def("_get_VarDecl", &clatt::DynTypedNode::get<clang::VarDecl>, py::return_value_policy::reference)
        .def("_get_ImplicitParamDecl", &clatt::DynTypedNode::get<clang::ImplicitParamDecl>, py::return_value_policy::reference)
        .def("_get_ParmVarDecl", &clatt::DynTypedNode::get<clang::ParmVarDecl>, py::return_value_policy::reference)
        .def("_get_FunctionDecl", &clatt::DynTypedNode::get<clang::FunctionDecl>, py::return_value_policy::reference)
        .def("_get_FieldDecl", &clatt::DynTypedNode::get<clang::FieldDecl>, py::return_value_policy::reference)
        .def("_get_EnumConstantDecl", &clatt::DynTypedNode::get<clang::EnumConstantDecl>, py::return_value_policy::reference)
        .def("_get_IndirectFieldDecl", &clatt::DynTypedNode::get<clang::IndirectFieldDecl>, py::return_value_policy::reference)
        .def("_get_TypeDecl", &clatt::DynTypedNode::get<clang::TypeDecl>, py::return_value_policy::reference)
        .def("_get_TypedefNameDecl", &clatt::DynTypedNode::get<clang::TypedefNameDecl>, py::return_value_policy::reference)
        .def("_get_TypedefDecl", &clatt::DynTypedNode::get<clang::TypedefDecl>, py::return_value_policy::reference)
        .def("_get_TypeAliasDecl", &clatt::DynTypedNode::get<clang::TypeAliasDecl>, py::return_value_policy::reference)
        .def("_get_TagDecl", &clatt::DynTypedNode::get<clang::TagDecl>, py::return_value_policy::reference)
        .def("_get_EnumDecl", &clatt::DynTypedNode::get<clang::EnumDecl>, py::return_value_policy::reference)
        .def("_get_RecordDecl", &clatt::DynTypedNode::get<clang::RecordDecl>, py::return_value_policy::reference)
        .def("_get_FileScopeAsmDecl", &clatt::DynTypedNode::get<clang::FileScopeAsmDecl>, py::return_value_policy::reference)
        .def("_get_BlockDecl", &clatt::DynTypedNode::get<clang::BlockDecl>, py::return_value_policy::reference)
        .def("_get_CapturedDecl", &clatt::DynTypedNode::get<clang::CapturedDecl>, py::return_value_policy::reference)
        .def("_get_ImportDecl", &clatt::DynTypedNode::get<clang::ImportDecl>, py::return_value_policy::reference)
        .def("_get_EmptyDecl", &clatt::DynTypedNode::get<clang::EmptyDecl>, py::return_value_policy::reference)
        .def("_get_Stmt", &clatt::DynTypedNode::get<clang::Stmt>, py::return_value_policy::reference)
        .def("_get_DeclStmt", &clatt::DynTypedNode::get<clang::DeclStmt>, py::return_value_policy::reference)
        .def("_get_NullStmt", &clatt::DynTypedNode::get<clang::NullStmt>, py::return_value_policy::reference)
        .def("_get_CompoundStmt", &clatt::DynTypedNode::get<clang::CompoundStmt>, py::return_value_policy::reference)
        .def("_get_SwitchCase", &clatt::DynTypedNode::get<clang::SwitchCase>, py::return_value_policy::reference)
        .def("_get_CaseStmt", &clatt::DynTypedNode::get<clang::CaseStmt>, py::return_value_policy::reference)
        .def("_get_DefaultStmt", &clatt::DynTypedNode::get<clang::DefaultStmt>, py::return_value_policy::reference)
        .def("_get_LabelStmt", &clatt::DynTypedNode::get<clang::LabelStmt>, py::return_value_policy::reference)
        .def("_get_AttributedStmt", &clatt::DynTypedNode::get<clang::AttributedStmt>, py::return_value_policy::reference)
        .def("_get_IfStmt", &clatt::DynTypedNode::get<clang::IfStmt>, py::return_value_policy::reference)
        .def("_get_SwitchStmt", &clatt::DynTypedNode::get<clang::SwitchStmt>, py::return_value_policy::reference)
        .def("_get_WhileStmt", &clatt::DynTypedNode::get<clang::WhileStmt>, py::return_value_policy::reference)
        .def("_get_DoStmt", &clatt::DynTypedNode::get<clang::DoStmt>, py::return_value_policy::reference)
        .def("_get_ForStmt", &clatt::DynTypedNode::get<clang::ForStmt>, py::return_value_policy::reference)
        .def("_get_GotoStmt", &clatt::DynTypedNode::get<clang::GotoStmt>, py::return_value_policy::reference)
        .def("_get_IndirectGotoStmt", &clatt::DynTypedNode::get<clang::IndirectGotoStmt>, py::return_value_policy::reference)
        .def("_get_ContinueStmt", &clatt::DynTypedNode::get<clang::ContinueStmt>, py::return_value_policy::reference)
        .def("_get_BreakStmt", &clatt::DynTypedNode::get<clang::BreakStmt>, py::return_value_policy::reference)
        .def("_get_ReturnStmt", &clatt::DynTypedNode::get<clang::ReturnStmt>, py::return_value_policy::reference)
        .def("_get_AsmStmt", &clatt::DynTypedNode::get<clang::AsmStmt>, py::return_value_policy::reference)
        .def("_get_GCCAsmStmt", &clatt::DynTypedNode::get<clang::GCCAsmStmt>, py::return_value_policy::reference)
        .def("_get_MSAsmStmt", &clatt::DynTypedNode::get<clang::MSAsmStmt>, py::return_value_policy::reference)
        .def("_get_SEHExceptStmt", &clatt::DynTypedNode::get<clang::SEHExceptStmt>, py::return_value_policy::reference)
        .def("_get_SEHFinallyStmt", &clatt::DynTypedNode::get<clang::SEHFinallyStmt>, py::return_value_policy::reference)
        .def("_get_SEHTryStmt", &clatt::DynTypedNode::get<clang::SEHTryStmt>, py::return_value_policy::reference)
        .def("_get_SEHLeaveStmt", &clatt::DynTypedNode::get<clang::SEHLeaveStmt>, py::return_value_policy::reference)
        .def("_get_CapturedStmt", &clatt::DynTypedNode::get<clang::CapturedStmt>, py::return_value_policy::reference)
        .def("_get_Expr", &clatt::DynTypedNode::get<clang::Expr>, py::return_value_policy::reference)
        .def("_get_OpaqueValueExpr", &clatt::DynTypedNode::get<clang::OpaqueValueExpr>, py::return_value_policy::reference)
        .def("_get_DeclRefExpr", &clatt::DynTypedNode::get<clang::DeclRefExpr>, py::return_value_policy::reference)
        .def("_get_PredefinedExpr", &clatt::DynTypedNode::get<clang::PredefinedExpr>, py::return_value_policy::reference)
        .def("_get_IntegerLiteral", &clatt::DynTypedNode::get<clang::IntegerLiteral>, py::return_value_policy::reference)
        .def("_get_CharacterLiteral", &clatt::DynTypedNode::get<clang::CharacterLiteral>, py::return_value_policy::reference)
        .def("_get_FloatingLiteral", &clatt::DynTypedNode::get<clang::FloatingLiteral>, py::return_value_policy::reference)
        .def("_get_ImaginaryLiteral", &clatt::DynTypedNode::get<clang::ImaginaryLiteral>, py::return_value_policy::reference)
        .def("_get_StringLiteral", &clatt::DynTypedNode::get<clang::StringLiteral>, py::return_value_policy::reference)
        .def("_get_ParenExpr", &clatt::DynTypedNode::get<clang::ParenExpr>, py::return_value_policy::reference)
        .def("_get_UnaryOperator", &clatt::DynTypedNode::get<clang::UnaryOperator>, py::return_value_policy::reference)
        .def("_get_OffsetOfExpr", &clatt::DynTypedNode::get<clang::OffsetOfExpr>, py::return_value_policy::reference)
        .def("_get_UnaryExprOrTypeTraitExpr", &clatt::DynTypedNode::get<clang::UnaryExprOrTypeTraitExpr>, py::return_value_policy::reference)
        .def("_get_ArraySubscriptExpr", &clatt::DynTypedNode::get<clang::ArraySubscriptExpr>, py::return_value_policy::reference)
        .def("_get_CallExpr", &clatt::DynTypedNode::get<clang::CallExpr>, py::return_value_policy::reference)
        .def("_get_MemberExpr", &clatt::DynTypedNode::get<clang::MemberExpr>, py::return_value_policy::reference)
        .def("_get_CompoundLiteralExpr", &clatt::DynTypedNode::get<clang::CompoundLiteralExpr>, py::return_value_policy::reference)
        .def("_get_CastExpr", &clatt::DynTypedNode::get<clang::CastExpr>, py::return_value_policy::reference)
        .def("_get_ImplicitCastExpr", &clatt::DynTypedNode::get<clang::ImplicitCastExpr>, py::return_value_policy::reference)
        .def("_get_ExplicitCastExpr", &clatt::DynTypedNode::get<clang::ExplicitCastExpr>, py::return_value_policy::reference)
        .def("_get_CStyleCastExpr", &clatt::DynTypedNode::get<clang::CStyleCastExpr>, py::return_value_policy::reference)
        .def("_get_BinaryOperator", &clatt::DynTypedNode::get<clang::BinaryOperator>, py::return_value_policy::reference)
        .def("_get_CompoundAssignOperator", &clatt::DynTypedNode::get<clang::CompoundAssignOperator>, py::return_value_policy::reference)
        .def("_get_AbstractConditionalOperator", &clatt::DynTypedNode::get<clang::AbstractConditionalOperator>, py::return_value_policy::reference)
        .def("_get_ConditionalOperator", &clatt::DynTypedNode::get<clang::ConditionalOperator>, py::return_value_policy::reference)
        .def("_get_BinaryConditionalOperator", &clatt::DynTypedNode::get<clang::BinaryConditionalOperator>, py::return_value_policy::reference)
        .def("_get_AddrLabelExpr", &clatt::DynTypedNode::get<clang::AddrLabelExpr>, py::return_value_policy::reference)
        .def("_get_StmtExpr", &clatt::DynTypedNode::get<clang::StmtExpr>, py::return_value_policy::reference)
        .def("_get_ShuffleVectorExpr", &clatt::DynTypedNode::get<clang::ShuffleVectorExpr>, py::return_value_policy::reference)
        .def("_get_ConvertVectorExpr", &clatt::DynTypedNode::get<clang::ConvertVectorExpr>, py::return_value_policy::reference)
        .def("_get_ChooseExpr", &clatt::DynTypedNode::get<clang::ChooseExpr>, py::return_value_policy::reference)
        .def("_get_GNUNullExpr", &clatt::DynTypedNode::get<clang::GNUNullExpr>, py::return_value_policy::reference)
        .def("_get_VAArgExpr", &clatt::DynTypedNode::get<clang::VAArgExpr>, py::return_value_policy::reference)
        .def("_get_InitListExpr", &clatt::DynTypedNode::get<clang::InitListExpr>, py::return_value_policy::reference)
        .def("_get_DesignatedInitExpr", &clatt::DynTypedNode::get<clang::DesignatedInitExpr>, py::return_value_policy::reference)
        .def("_get_NoInitExpr", &clatt::DynTypedNode::get<clang::NoInitExpr>, py::return_value_policy::reference)
        .def("_get_DesignatedInitUpdateExpr", &clatt::DynTypedNode::get<clang::DesignatedInitUpdateExpr>, py::return_value_policy::reference)
        .def("_get_ImplicitValueInitExpr", &clatt::DynTypedNode::get<clang::ImplicitValueInitExpr>, py::return_value_policy::reference)
        .def("_get_ParenListExpr", &clatt::DynTypedNode::get<clang::ParenListExpr>, py::return_value_policy::reference)
        .def("_get_GenericSelectionExpr", &clatt::DynTypedNode::get<clang::GenericSelectionExpr>, py::return_value_policy::reference)
        .def("_get_ExtVectorElementExpr", &clatt::DynTypedNode::get<clang::ExtVectorElementExpr>, py::return_value_policy::reference)
        .def("_get_BlockExpr", &clatt::DynTypedNode::get<clang::BlockExpr>, py::return_value_policy::reference)
        .def("_get_AsTypeExpr", &clatt::DynTypedNode::get<clang::AsTypeExpr>, py::return_value_policy::reference)
        .def("_get_PseudoObjectExpr", &clatt::DynTypedNode::get<clang::PseudoObjectExpr>, py::return_value_policy::reference)
        .def("_get_AtomicExpr", &clatt::DynTypedNode::get<clang::AtomicExpr>, py::return_value_policy::reference)
        .def("_get_TypoExpr", &clatt::DynTypedNode::get<clang::TypoExpr>, py::return_value_policy::reference)
        .def("_get_AccessSpecDecl", &clatt::DynTypedNode::get<clang::AccessSpecDecl>, py::return_value_policy::reference)
        .def("_get_CXXRecordDecl", &clatt::DynTypedNode::get<clang::CXXRecordDecl>, py::return_value_policy::reference)
        .def("_get_CXXMethodDecl", &clatt::DynTypedNode::get<clang::CXXMethodDecl>, py::return_value_policy::reference)
        .def("_get_CXXConstructorDecl", &clatt::DynTypedNode::get<clang::CXXConstructorDecl>, py::return_value_policy::reference)
        .def("_get_CXXDestructorDecl", &clatt::DynTypedNode::get<clang::CXXDestructorDecl>, py::return_value_policy::reference)
        .def("_get_CXXConversionDecl", &clatt::DynTypedNode::get<clang::CXXConversionDecl>, py::return_value_policy::reference)
        .def("_get_LinkageSpecDecl", &clatt::DynTypedNode::get<clang::LinkageSpecDecl>, py::return_value_policy::reference)
        .def("_get_UsingDirectiveDecl", &clatt::DynTypedNode::get<clang::UsingDirectiveDecl>, py::return_value_policy::reference)
        .def("_get_NamespaceAliasDecl", &clatt::DynTypedNode::get<clang::NamespaceAliasDecl>, py::return_value_policy::reference)
        .def("_get_UsingShadowDecl", &clatt::DynTypedNode::get<clang::UsingShadowDecl>, py::return_value_policy::reference)
        .def("_get_UsingDecl", &clatt::DynTypedNode::get<clang::UsingDecl>, py::return_value_policy::reference)
        .def("_get_UnresolvedUsingValueDecl", &clatt::DynTypedNode::get<clang::UnresolvedUsingValueDecl>, py::return_value_policy::reference)
        .def("_get_UnresolvedUsingTypenameDecl", &clatt::DynTypedNode::get<clang::UnresolvedUsingTypenameDecl>, py::return_value_policy::reference)
        .def("_get_StaticAssertDecl", &clatt::DynTypedNode::get<clang::StaticAssertDecl>, py::return_value_policy::reference)
        .def("_get_MSPropertyDecl", &clatt::DynTypedNode::get<clang::MSPropertyDecl>, py::return_value_policy::reference)
        .def("_get_TemplateDecl", &clatt::DynTypedNode::get<clang::TemplateDecl>, py::return_value_policy::reference)
        .def("_get_RedeclarableTemplateDecl", &clatt::DynTypedNode::get<clang::RedeclarableTemplateDecl>, py::return_value_policy::reference)
        .def("_get_FunctionTemplateDecl", &clatt::DynTypedNode::get<clang::FunctionTemplateDecl>, py::return_value_policy::reference)
        .def("_get_TemplateTypeParmDecl", &clatt::DynTypedNode::get<clang::TemplateTypeParmDecl>, py::return_value_policy::reference)
        .def("_get_NonTypeTemplateParmDecl", &clatt::DynTypedNode::get<clang::NonTypeTemplateParmDecl>, py::return_value_policy::reference)
        .def("_get_TemplateTemplateParmDecl", &clatt::DynTypedNode::get<clang::TemplateTemplateParmDecl>, py::return_value_policy::reference)
        .def("_get_BuiltinTemplateDecl", &clatt::DynTypedNode::get<clang::BuiltinTemplateDecl>, py::return_value_policy::reference)
        .def("_get_ClassTemplateSpecializationDecl", &clatt::DynTypedNode::get<clang::ClassTemplateSpecializationDecl>, py::return_value_policy::reference)
        .def("_get_ClassTemplatePartialSpecializationDecl", &clatt::DynTypedNode::get<clang::ClassTemplatePartialSpecializationDecl>, py::return_value_policy::reference)
        .def("_get_ClassTemplateDecl", &clatt::DynTypedNode::get<clang::ClassTemplateDecl>, py::return_value_policy::reference)
        .def("_get_FriendTemplateDecl", &clatt::DynTypedNode::get<clang::FriendTemplateDecl>, py::return_value_policy::reference)
        .def("_get_TypeAliasTemplateDecl", &clatt::DynTypedNode::get<clang::TypeAliasTemplateDecl>, py::return_value_policy::reference)
        .def("_get_ClassScopeFunctionSpecializationDecl", &clatt::DynTypedNode::get<clang::ClassScopeFunctionSpecializationDecl>, py::return_value_policy::reference)
        .def("_get_VarTemplateSpecializationDecl", &clatt::DynTypedNode::get<clang::VarTemplateSpecializationDecl>, py::return_value_policy::reference)
        .def("_get_VarTemplatePartialSpecializationDecl", &clatt::DynTypedNode::get<clang::VarTemplatePartialSpecializationDecl>, py::return_value_policy::reference)
        .def("_get_VarTemplateDecl", &clatt::DynTypedNode::get<clang::VarTemplateDecl>, py::return_value_policy::reference)
        .def("_get_CXXOperatorCallExpr", &clatt::DynTypedNode::get<clang::CXXOperatorCallExpr>, py::return_value_policy::reference)
        .def("_get_CXXMemberCallExpr", &clatt::DynTypedNode::get<clang::CXXMemberCallExpr>, py::return_value_policy::reference)
        .def("_get_CUDAKernelCallExpr", &clatt::DynTypedNode::get<clang::CUDAKernelCallExpr>, py::return_value_policy::reference)
        .def("_get_CXXNamedCastExpr", &clatt::DynTypedNode::get<clang::CXXNamedCastExpr>, py::return_value_policy::reference)
        .def("_get_CXXStaticCastExpr", &clatt::DynTypedNode::get<clang::CXXStaticCastExpr>, py::return_value_policy::reference)
        .def("_get_CXXDynamicCastExpr", &clatt::DynTypedNode::get<clang::CXXDynamicCastExpr>, py::return_value_policy::reference)
        .def("_get_CXXReinterpretCastExpr", &clatt::DynTypedNode::get<clang::CXXReinterpretCastExpr>, py::return_value_policy::reference)
        .def("_get_CXXConstCastExpr", &clatt::DynTypedNode::get<clang::CXXConstCastExpr>, py::return_value_policy::reference)
        .def("_get_UserDefinedLiteral", &clatt::DynTypedNode::get<clang::UserDefinedLiteral>, py::return_value_policy::reference)
        .def("_get_CXXBoolLiteralExpr", &clatt::DynTypedNode::get<clang::CXXBoolLiteralExpr>, py::return_value_policy::reference)
        .def("_get_CXXNullPtrLiteralExpr", &clatt::DynTypedNode::get<clang::CXXNullPtrLiteralExpr>, py::return_value_policy::reference)
        .def("_get_CXXStdInitializerListExpr", &clatt::DynTypedNode::get<clang::CXXStdInitializerListExpr>, py::return_value_policy::reference)
        .def("_get_CXXTypeidExpr", &clatt::DynTypedNode::get<clang::CXXTypeidExpr>, py::return_value_policy::reference)
        .def("_get_MSPropertyRefExpr", &clatt::DynTypedNode::get<clang::MSPropertyRefExpr>, py::return_value_policy::reference)
        .def("_get_MSPropertySubscriptExpr", &clatt::DynTypedNode::get<clang::MSPropertySubscriptExpr>, py::return_value_policy::reference)
        .def("_get_CXXUuidofExpr", &clatt::DynTypedNode::get<clang::CXXUuidofExpr>, py::return_value_policy::reference)
        .def("_get_CXXThisExpr", &clatt::DynTypedNode::get<clang::CXXThisExpr>, py::return_value_policy::reference)
        .def("_get_CXXThrowExpr", &clatt::DynTypedNode::get<clang::CXXThrowExpr>, py::return_value_policy::reference)
        .def("_get_CXXDefaultArgExpr", &clatt::DynTypedNode::get<clang::CXXDefaultArgExpr>, py::return_value_policy::reference)
        .def("_get_CXXDefaultInitExpr", &clatt::DynTypedNode::get<clang::CXXDefaultInitExpr>, py::return_value_policy::reference)
        .def("_get_CXXBindTemporaryExpr", &clatt::DynTypedNode::get<clang::CXXBindTemporaryExpr>, py::return_value_policy::reference)
        .def("_get_CXXConstructExpr", &clatt::DynTypedNode::get<clang::CXXConstructExpr>, py::return_value_policy::reference)
        .def("_get_CXXFunctionalCastExpr", &clatt::DynTypedNode::get<clang::CXXFunctionalCastExpr>, py::return_value_policy::reference)
        .def("_get_CXXTemporaryObjectExpr", &clatt::DynTypedNode::get<clang::CXXTemporaryObjectExpr>, py::return_value_policy::reference)
        .def("_get_LambdaExpr", &clatt::DynTypedNode::get<clang::LambdaExpr>, py::return_value_policy::reference)
        .def("_get_CXXScalarValueInitExpr", &clatt::DynTypedNode::get<clang::CXXScalarValueInitExpr>, py::return_value_policy::reference)
        .def("_get_CXXNewExpr", &clatt::DynTypedNode::get<clang::CXXNewExpr>, py::return_value_policy::reference)
        .def("_get_CXXDeleteExpr", &clatt::DynTypedNode::get<clang::CXXDeleteExpr>, py::return_value_policy::reference)
        .def("_get_CXXPseudoDestructorExpr", &clatt::DynTypedNode::get<clang::CXXPseudoDestructorExpr>, py::return_value_policy::reference)
        .def("_get_TypeTraitExpr", &clatt::DynTypedNode::get<clang::TypeTraitExpr>, py::return_value_policy::reference)
        .def("_get_ArrayTypeTraitExpr", &clatt::DynTypedNode::get<clang::ArrayTypeTraitExpr>, py::return_value_policy::reference)
        .def("_get_ExpressionTraitExpr", &clatt::DynTypedNode::get<clang::ExpressionTraitExpr>, py::return_value_policy::reference)
        .def("_get_OverloadExpr", &clatt::DynTypedNode::get<clang::OverloadExpr>, py::return_value_policy::reference)
        .def("_get_UnresolvedLookupExpr", &clatt::DynTypedNode::get<clang::UnresolvedLookupExpr>, py::return_value_policy::reference)
        .def("_get_DependentScopeDeclRefExpr", &clatt::DynTypedNode::get<clang::DependentScopeDeclRefExpr>, py::return_value_policy::reference)
        .def("_get_ExprWithCleanups", &clatt::DynTypedNode::get<clang::ExprWithCleanups>, py::return_value_policy::reference)
        .def("_get_CXXUnresolvedConstructExpr", &clatt::DynTypedNode::get<clang::CXXUnresolvedConstructExpr>, py::return_value_policy::reference)
        .def("_get_CXXDependentScopeMemberExpr", &clatt::DynTypedNode::get<clang::CXXDependentScopeMemberExpr>, py::return_value_policy::reference)
        .def("_get_UnresolvedMemberExpr", &clatt::DynTypedNode::get<clang::UnresolvedMemberExpr>, py::return_value_policy::reference)
        .def("_get_CXXNoexceptExpr", &clatt::DynTypedNode::get<clang::CXXNoexceptExpr>, py::return_value_policy::reference)
        .def("_get_PackExpansionExpr", &clatt::DynTypedNode::get<clang::PackExpansionExpr>, py::return_value_policy::reference)
        .def("_get_SizeOfPackExpr", &clatt::DynTypedNode::get<clang::SizeOfPackExpr>, py::return_value_policy::reference)
        .def("_get_SubstNonTypeTemplateParmExpr", &clatt::DynTypedNode::get<clang::SubstNonTypeTemplateParmExpr>, py::return_value_policy::reference)
        .def("_get_SubstNonTypeTemplateParmPackExpr", &clatt::DynTypedNode::get<clang::SubstNonTypeTemplateParmPackExpr>, py::return_value_policy::reference)
        .def("_get_FunctionParmPackExpr", &clatt::DynTypedNode::get<clang::FunctionParmPackExpr>, py::return_value_policy::reference)
        .def("_get_MaterializeTemporaryExpr", &clatt::DynTypedNode::get<clang::MaterializeTemporaryExpr>, py::return_value_policy::reference)
        .def("_get_CXXFoldExpr", &clatt::DynTypedNode::get<clang::CXXFoldExpr>, py::return_value_policy::reference)
        .def("_get_CoroutineSuspendExpr", &clatt::DynTypedNode::get<clang::CoroutineSuspendExpr>, py::return_value_policy::reference)
        .def("_get_CoawaitExpr", &clatt::DynTypedNode::get<clang::CoawaitExpr>, py::return_value_policy::reference)
        .def("_get_CoyieldExpr", &clatt::DynTypedNode::get<clang::CoyieldExpr>, py::return_value_policy::reference)
        .def("_get_CXXCatchStmt", &clatt::DynTypedNode::get<clang::CXXCatchStmt>, py::return_value_policy::reference)
        .def("_get_CXXTryStmt", &clatt::DynTypedNode::get<clang::CXXTryStmt>, py::return_value_policy::reference)
        .def("_get_CXXForRangeStmt", &clatt::DynTypedNode::get<clang::CXXForRangeStmt>, py::return_value_policy::reference)
        .def("_get_MSDependentExistsStmt", &clatt::DynTypedNode::get<clang::MSDependentExistsStmt>, py::return_value_policy::reference)
        .def("_get_CoroutineBodyStmt", &clatt::DynTypedNode::get<clang::CoroutineBodyStmt>, py::return_value_policy::reference)
        .def("_get_CoreturnStmt", &clatt::DynTypedNode::get<clang::CoreturnStmt>, py::return_value_policy::reference)
        .def("_get_FriendDecl", &clatt::DynTypedNode::get<clang::FriendDecl>, py::return_value_policy::reference)
    ;
}