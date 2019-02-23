
////////////////////////////////////////////////////////////////////////////////
// File autogenerated by clastgen
//  Clang - clang version 8.0.0 
//
// Warning. Changes made here will be overwritten.
////////////////////////////////////////////////////////////////////////////////
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "internal.h"

#include <clang/AST/AST.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>


namespace py = pybind11;

void autogenerated_classes_4(pybind11::module& m)
{

    py::class_<clang::FunctionParmPackExpr, stmt_deleter<clang::FunctionParmPackExpr>::type>(m, "FunctionParmPackExpr" , py::base<clang::Expr>())

        .def("getParameterPack", (clang::ParmVarDecl * (clang::FunctionParmPackExpr::*)() const)&clang::FunctionParmPackExpr::getParameterPack , py::return_value_policy::reference_internal )
        .def("getParameterPackLocation", (clang::SourceLocation (clang::FunctionParmPackExpr::*)() const)&clang::FunctionParmPackExpr::getParameterPackLocation  )
        .def("getNumExpansions", (unsigned int (clang::FunctionParmPackExpr::*)() const)&clang::FunctionParmPackExpr::getNumExpansions  )
        .def("getExpansion", (clang::ParmVarDecl * (clang::FunctionParmPackExpr::*)(unsigned int) const)&clang::FunctionParmPackExpr::getExpansion , py::return_value_policy::reference_internal )
        .def("getBeginLoc", (clang::SourceLocation (clang::FunctionParmPackExpr::*)() const)&clang::FunctionParmPackExpr::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::FunctionParmPackExpr::*)() const)&clang::FunctionParmPackExpr::getEndLoc  )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::FunctionParmPackExpr::*)())&clang::FunctionParmPackExpr::children  )
    ;

    py::class_<clang::MaterializeTemporaryExpr, stmt_deleter<clang::MaterializeTemporaryExpr>::type>(m, "MaterializeTemporaryExpr" , py::base<clang::Expr>())

        .def("getTemporary", (clang::Stmt * (clang::MaterializeTemporaryExpr::*)() const)&clang::MaterializeTemporaryExpr::getTemporary , py::return_value_policy::reference_internal )
        .def("GetTemporaryExpr", (clang::Expr * (clang::MaterializeTemporaryExpr::*)() const)&clang::MaterializeTemporaryExpr::GetTemporaryExpr , py::return_value_policy::reference_internal )
        .def("getStorageDuration", (clang::StorageDuration (clang::MaterializeTemporaryExpr::*)() const)&clang::MaterializeTemporaryExpr::getStorageDuration  )
        .def("getExtendingDecl", (const clang::ValueDecl * (clang::MaterializeTemporaryExpr::*)() const)&clang::MaterializeTemporaryExpr::getExtendingDecl , py::return_value_policy::reference_internal )
        .def("setExtendingDecl", (void (clang::MaterializeTemporaryExpr::*)(const clang::ValueDecl *, unsigned int))&clang::MaterializeTemporaryExpr::setExtendingDecl  )
        .def("getManglingNumber", (unsigned int (clang::MaterializeTemporaryExpr::*)() const)&clang::MaterializeTemporaryExpr::getManglingNumber  )
        .def("isBoundToLvalueReference", (bool (clang::MaterializeTemporaryExpr::*)() const)&clang::MaterializeTemporaryExpr::isBoundToLvalueReference  )
        .def("getBeginLoc", (clang::SourceLocation (clang::MaterializeTemporaryExpr::*)() const)&clang::MaterializeTemporaryExpr::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::MaterializeTemporaryExpr::*)() const)&clang::MaterializeTemporaryExpr::getEndLoc  )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::MaterializeTemporaryExpr::*)())&clang::MaterializeTemporaryExpr::children  )
    ;

    py::class_<clang::CXXFoldExpr, stmt_deleter<clang::CXXFoldExpr>::type>(m, "CXXFoldExpr" , py::base<clang::Expr>())

        .def("getLHS", (clang::Expr * (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::getLHS , py::return_value_policy::reference_internal )
        .def("getRHS", (clang::Expr * (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::getRHS , py::return_value_policy::reference_internal )
        .def("isRightFold", (bool (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::isRightFold  )
        .def("isLeftFold", (bool (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::isLeftFold  )
        .def("getPattern", (clang::Expr * (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::getPattern , py::return_value_policy::reference_internal )
        .def("getInit", (clang::Expr * (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::getInit , py::return_value_policy::reference_internal )
        .def("getEllipsisLoc", (clang::SourceLocation (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::getEllipsisLoc  )
        .def("getOperator", (clang::BinaryOperatorKind (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::getOperator  )
        .def("getBeginLoc", (clang::SourceLocation (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::CXXFoldExpr::*)() const)&clang::CXXFoldExpr::getEndLoc  )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::CXXFoldExpr::*)())&clang::CXXFoldExpr::children  )
    ;

    py::class_<clang::CoroutineSuspendExpr, stmt_deleter<clang::CoroutineSuspendExpr>::type>(m, "CoroutineSuspendExpr" , py::base<clang::Expr>())

        .def("getKeywordLoc", (clang::SourceLocation (clang::CoroutineSuspendExpr::*)() const)&clang::CoroutineSuspendExpr::getKeywordLoc  )
        .def("getCommonExpr", (clang::Expr * (clang::CoroutineSuspendExpr::*)() const)&clang::CoroutineSuspendExpr::getCommonExpr , py::return_value_policy::reference_internal )
        .def("getOpaqueValue", (clang::OpaqueValueExpr * (clang::CoroutineSuspendExpr::*)() const)&clang::CoroutineSuspendExpr::getOpaqueValue , py::return_value_policy::reference_internal )
        .def("getReadyExpr", (clang::Expr * (clang::CoroutineSuspendExpr::*)() const)&clang::CoroutineSuspendExpr::getReadyExpr , py::return_value_policy::reference_internal )
        .def("getSuspendExpr", (clang::Expr * (clang::CoroutineSuspendExpr::*)() const)&clang::CoroutineSuspendExpr::getSuspendExpr , py::return_value_policy::reference_internal )
        .def("getResumeExpr", (clang::Expr * (clang::CoroutineSuspendExpr::*)() const)&clang::CoroutineSuspendExpr::getResumeExpr , py::return_value_policy::reference_internal )
        .def("getBeginLoc", (clang::SourceLocation (clang::CoroutineSuspendExpr::*)() const)&clang::CoroutineSuspendExpr::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::CoroutineSuspendExpr::*)() const)&clang::CoroutineSuspendExpr::getEndLoc  )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::CoroutineSuspendExpr::*)())&clang::CoroutineSuspendExpr::children  )
    ;

    py::class_<clang::CoawaitExpr, stmt_deleter<clang::CoawaitExpr>::type>(m, "CoawaitExpr" , py::base<clang::CoroutineSuspendExpr>())

        .def("getOperand", (clang::Expr * (clang::CoawaitExpr::*)() const)&clang::CoawaitExpr::getOperand , py::return_value_policy::reference_internal )
        .def("isImplicit", (bool (clang::CoawaitExpr::*)() const)&clang::CoawaitExpr::isImplicit  )
        .def("setIsImplicit", (void (clang::CoawaitExpr::*)(bool))&clang::CoawaitExpr::setIsImplicit  )
    ;

    py::class_<clang::DependentCoawaitExpr, stmt_deleter<clang::DependentCoawaitExpr>::type>(m, "DependentCoawaitExpr" , py::base<clang::Expr>())

        .def("getOperand", (clang::Expr * (clang::DependentCoawaitExpr::*)() const)&clang::DependentCoawaitExpr::getOperand , py::return_value_policy::reference_internal )
        .def("getOperatorCoawaitLookup", (clang::UnresolvedLookupExpr * (clang::DependentCoawaitExpr::*)() const)&clang::DependentCoawaitExpr::getOperatorCoawaitLookup , py::return_value_policy::reference_internal )
        .def("getKeywordLoc", (clang::SourceLocation (clang::DependentCoawaitExpr::*)() const)&clang::DependentCoawaitExpr::getKeywordLoc  )
        .def("getBeginLoc", (clang::SourceLocation (clang::DependentCoawaitExpr::*)() const)&clang::DependentCoawaitExpr::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::DependentCoawaitExpr::*)() const)&clang::DependentCoawaitExpr::getEndLoc  )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::DependentCoawaitExpr::*)())&clang::DependentCoawaitExpr::children  )
    ;

    py::class_<clang::CoyieldExpr, stmt_deleter<clang::CoyieldExpr>::type>(m, "CoyieldExpr" , py::base<clang::CoroutineSuspendExpr>())

        .def("getOperand", (clang::Expr * (clang::CoyieldExpr::*)() const)&clang::CoyieldExpr::getOperand , py::return_value_policy::reference_internal )
    ;

    py::class_<clang::CXXCatchStmt, stmt_deleter<clang::CXXCatchStmt>::type>(m, "CXXCatchStmt" , py::base<clang::Stmt>())

        .def("getBeginLoc", (clang::SourceLocation (clang::CXXCatchStmt::*)() const)&clang::CXXCatchStmt::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::CXXCatchStmt::*)() const)&clang::CXXCatchStmt::getEndLoc  )
        .def("getCatchLoc", (clang::SourceLocation (clang::CXXCatchStmt::*)() const)&clang::CXXCatchStmt::getCatchLoc  )
        .def("getExceptionDecl", (clang::VarDecl * (clang::CXXCatchStmt::*)() const)&clang::CXXCatchStmt::getExceptionDecl , py::return_value_policy::reference_internal )
        .def("getCaughtType", (clang::QualType (clang::CXXCatchStmt::*)() const)&clang::CXXCatchStmt::getCaughtType  )
        .def("getHandlerBlock", (clang::Stmt * (clang::CXXCatchStmt::*)() const)&clang::CXXCatchStmt::getHandlerBlock , py::return_value_policy::reference_internal )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::CXXCatchStmt::*)())&clang::CXXCatchStmt::children  )
    ;

    py::class_<clang::CXXTryStmt, stmt_deleter<clang::CXXTryStmt>::type>(m, "CXXTryStmt" , py::base<clang::Stmt>())

        .def("getBeginLoc", (clang::SourceLocation (clang::CXXTryStmt::*)() const)&clang::CXXTryStmt::getBeginLoc  )
        .def("getTryLoc", (clang::SourceLocation (clang::CXXTryStmt::*)() const)&clang::CXXTryStmt::getTryLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::CXXTryStmt::*)() const)&clang::CXXTryStmt::getEndLoc  )
        .def("getTryBlock", []( clang::CXXTryStmt& self) -> clang::CompoundStmt * {
         return self.getTryBlock();
        } , py::return_value_policy::reference_internal)
        .def("getTryBlock", [](const clang::CXXTryStmt& self) -> const clang::CompoundStmt * {
         return self.getTryBlock();
        } , py::return_value_policy::reference_internal)
        .def("getNumHandlers", (unsigned int (clang::CXXTryStmt::*)() const)&clang::CXXTryStmt::getNumHandlers  )
        .def("getHandler", []( clang::CXXTryStmt& self, unsigned int i) -> clang::CXXCatchStmt * {
         return self.getHandler(i);
        } , py::return_value_policy::reference_internal)
        .def("getHandler", [](const clang::CXXTryStmt& self, unsigned int i) -> const clang::CXXCatchStmt * {
         return self.getHandler(i);
        } , py::return_value_policy::reference_internal)
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::CXXTryStmt::*)())&clang::CXXTryStmt::children  )
    ;

    py::class_<clang::CXXForRangeStmt, stmt_deleter<clang::CXXForRangeStmt>::type>(m, "CXXForRangeStmt" , py::base<clang::Stmt>())

        .def("getInit", []( clang::CXXForRangeStmt& self) -> clang::Stmt * {
         return self.getInit();
        } , py::return_value_policy::reference_internal)
        .def("getLoopVariable", []( clang::CXXForRangeStmt& self) -> clang::VarDecl * {
         return self.getLoopVariable();
        } , py::return_value_policy::reference_internal)
        .def("getRangeInit", []( clang::CXXForRangeStmt& self) -> clang::Expr * {
         return self.getRangeInit();
        } , py::return_value_policy::reference_internal)
        .def("getInit", [](const clang::CXXForRangeStmt& self) -> const clang::Stmt * {
         return self.getInit();
        } , py::return_value_policy::reference_internal)
        .def("getLoopVariable", [](const clang::CXXForRangeStmt& self) -> const clang::VarDecl * {
         return self.getLoopVariable();
        } , py::return_value_policy::reference_internal)
        .def("getRangeInit", [](const clang::CXXForRangeStmt& self) -> const clang::Expr * {
         return self.getRangeInit();
        } , py::return_value_policy::reference_internal)
        .def("getRangeStmt", []( clang::CXXForRangeStmt& self) -> clang::DeclStmt * {
         return self.getRangeStmt();
        } , py::return_value_policy::reference_internal)
        .def("getBeginStmt", []( clang::CXXForRangeStmt& self) -> clang::DeclStmt * {
         return self.getBeginStmt();
        } , py::return_value_policy::reference_internal)
        .def("getEndStmt", []( clang::CXXForRangeStmt& self) -> clang::DeclStmt * {
         return self.getEndStmt();
        } , py::return_value_policy::reference_internal)
        .def("getCond", []( clang::CXXForRangeStmt& self) -> clang::Expr * {
         return self.getCond();
        } , py::return_value_policy::reference_internal)
        .def("getInc", []( clang::CXXForRangeStmt& self) -> clang::Expr * {
         return self.getInc();
        } , py::return_value_policy::reference_internal)
        .def("getLoopVarStmt", []( clang::CXXForRangeStmt& self) -> clang::DeclStmt * {
         return self.getLoopVarStmt();
        } , py::return_value_policy::reference_internal)
        .def("getBody", []( clang::CXXForRangeStmt& self) -> clang::Stmt * {
         return self.getBody();
        } , py::return_value_policy::reference_internal)
        .def("getRangeStmt", [](const clang::CXXForRangeStmt& self) -> const clang::DeclStmt * {
         return self.getRangeStmt();
        } , py::return_value_policy::reference_internal)
        .def("getBeginStmt", [](const clang::CXXForRangeStmt& self) -> const clang::DeclStmt * {
         return self.getBeginStmt();
        } , py::return_value_policy::reference_internal)
        .def("getEndStmt", [](const clang::CXXForRangeStmt& self) -> const clang::DeclStmt * {
         return self.getEndStmt();
        } , py::return_value_policy::reference_internal)
        .def("getCond", [](const clang::CXXForRangeStmt& self) -> const clang::Expr * {
         return self.getCond();
        } , py::return_value_policy::reference_internal)
        .def("getInc", [](const clang::CXXForRangeStmt& self) -> const clang::Expr * {
         return self.getInc();
        } , py::return_value_policy::reference_internal)
        .def("getLoopVarStmt", [](const clang::CXXForRangeStmt& self) -> const clang::DeclStmt * {
         return self.getLoopVarStmt();
        } , py::return_value_policy::reference_internal)
        .def("getBody", [](const clang::CXXForRangeStmt& self) -> const clang::Stmt * {
         return self.getBody();
        } , py::return_value_policy::reference_internal)
        .def("setInit", (void (clang::CXXForRangeStmt::*)(clang::Stmt *))&clang::CXXForRangeStmt::setInit  )
        .def("setRangeInit", (void (clang::CXXForRangeStmt::*)(clang::Expr *))&clang::CXXForRangeStmt::setRangeInit  )
        .def("setRangeStmt", (void (clang::CXXForRangeStmt::*)(clang::Stmt *))&clang::CXXForRangeStmt::setRangeStmt  )
        .def("setBeginStmt", (void (clang::CXXForRangeStmt::*)(clang::Stmt *))&clang::CXXForRangeStmt::setBeginStmt  )
        .def("setEndStmt", (void (clang::CXXForRangeStmt::*)(clang::Stmt *))&clang::CXXForRangeStmt::setEndStmt  )
        .def("setCond", (void (clang::CXXForRangeStmt::*)(clang::Expr *))&clang::CXXForRangeStmt::setCond  )
        .def("setInc", (void (clang::CXXForRangeStmt::*)(clang::Expr *))&clang::CXXForRangeStmt::setInc  )
        .def("setLoopVarStmt", (void (clang::CXXForRangeStmt::*)(clang::Stmt *))&clang::CXXForRangeStmt::setLoopVarStmt  )
        .def("setBody", (void (clang::CXXForRangeStmt::*)(clang::Stmt *))&clang::CXXForRangeStmt::setBody  )
        .def("getForLoc", (clang::SourceLocation (clang::CXXForRangeStmt::*)() const)&clang::CXXForRangeStmt::getForLoc  )
        .def("getCoawaitLoc", (clang::SourceLocation (clang::CXXForRangeStmt::*)() const)&clang::CXXForRangeStmt::getCoawaitLoc  )
        .def("getColonLoc", (clang::SourceLocation (clang::CXXForRangeStmt::*)() const)&clang::CXXForRangeStmt::getColonLoc  )
        .def("getRParenLoc", (clang::SourceLocation (clang::CXXForRangeStmt::*)() const)&clang::CXXForRangeStmt::getRParenLoc  )
        .def("getBeginLoc", (clang::SourceLocation (clang::CXXForRangeStmt::*)() const)&clang::CXXForRangeStmt::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::CXXForRangeStmt::*)() const)&clang::CXXForRangeStmt::getEndLoc  )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::CXXForRangeStmt::*)())&clang::CXXForRangeStmt::children  )
    ;

    py::class_<clang::MSDependentExistsStmt, stmt_deleter<clang::MSDependentExistsStmt>::type>(m, "MSDependentExistsStmt" , py::base<clang::Stmt>())

        .def("getKeywordLoc", (clang::SourceLocation (clang::MSDependentExistsStmt::*)() const)&clang::MSDependentExistsStmt::getKeywordLoc  )
        .def("isIfExists", (bool (clang::MSDependentExistsStmt::*)() const)&clang::MSDependentExistsStmt::isIfExists  )
        .def("isIfNotExists", (bool (clang::MSDependentExistsStmt::*)() const)&clang::MSDependentExistsStmt::isIfNotExists  )
        //.def("getQualifierLoc", (clang::NestedNameSpecifierLoc (clang::MSDependentExistsStmt::*)() const)&clang::MSDependentExistsStmt::getQualifierLoc  )
        .def("getNameInfo", (clang::DeclarationNameInfo (clang::MSDependentExistsStmt::*)() const)&clang::MSDependentExistsStmt::getNameInfo  )
        .def("getSubStmt", (clang::CompoundStmt * (clang::MSDependentExistsStmt::*)() const)&clang::MSDependentExistsStmt::getSubStmt , py::return_value_policy::reference_internal )
        .def("getBeginLoc", (clang::SourceLocation (clang::MSDependentExistsStmt::*)() const)&clang::MSDependentExistsStmt::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::MSDependentExistsStmt::*)() const)&clang::MSDependentExistsStmt::getEndLoc  )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::MSDependentExistsStmt::*)())&clang::MSDependentExistsStmt::children  )
    ;

    py::class_<clang::CoroutineBodyStmt, stmt_deleter<clang::CoroutineBodyStmt>::type>(m, "CoroutineBodyStmt" , py::base<clang::Stmt>())

        .def("hasDependentPromiseType", (bool (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::hasDependentPromiseType  )
        .def("getBody", (clang::Stmt * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getBody , py::return_value_policy::reference_internal )
        .def("getPromiseDeclStmt", (clang::Stmt * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getPromiseDeclStmt , py::return_value_policy::reference_internal )
        .def("getPromiseDecl", (clang::VarDecl * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getPromiseDecl , py::return_value_policy::reference_internal )
        .def("getInitSuspendStmt", (clang::Stmt * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getInitSuspendStmt , py::return_value_policy::reference_internal )
        .def("getFinalSuspendStmt", (clang::Stmt * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getFinalSuspendStmt , py::return_value_policy::reference_internal )
        .def("getExceptionHandler", (clang::Stmt * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getExceptionHandler , py::return_value_policy::reference_internal )
        .def("getFallthroughHandler", (clang::Stmt * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getFallthroughHandler , py::return_value_policy::reference_internal )
        .def("getAllocate", (clang::Expr * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getAllocate , py::return_value_policy::reference_internal )
        .def("getDeallocate", (clang::Expr * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getDeallocate , py::return_value_policy::reference_internal )
        .def("getReturnValueInit", (clang::Expr * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getReturnValueInit , py::return_value_policy::reference_internal )
        .def("getResultDecl", (clang::Stmt * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getResultDecl , py::return_value_policy::reference_internal )
        .def("getReturnStmt", (clang::Stmt * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getReturnStmt , py::return_value_policy::reference_internal )
        .def("getReturnStmtOnAllocFailure", (clang::Stmt * (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getReturnStmtOnAllocFailure , py::return_value_policy::reference_internal )
        //.def("getParamMoves", (llvm::ArrayRef<const clang::Stmt *> (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getParamMoves  )
        .def("getBeginLoc", (clang::SourceLocation (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::CoroutineBodyStmt::*)() const)&clang::CoroutineBodyStmt::getEndLoc  )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::CoroutineBodyStmt::*)())&clang::CoroutineBodyStmt::children  )
    ;

    py::class_<clang::CoreturnStmt, stmt_deleter<clang::CoreturnStmt>::type>(m, "CoreturnStmt" , py::base<clang::Stmt>())

        .def("getKeywordLoc", (clang::SourceLocation (clang::CoreturnStmt::*)() const)&clang::CoreturnStmt::getKeywordLoc  )
        .def("getOperand", (clang::Expr * (clang::CoreturnStmt::*)() const)&clang::CoreturnStmt::getOperand , py::return_value_policy::reference_internal )
        .def("getPromiseCall", (clang::Expr * (clang::CoreturnStmt::*)() const)&clang::CoreturnStmt::getPromiseCall , py::return_value_policy::reference_internal )
        .def("isImplicit", (bool (clang::CoreturnStmt::*)() const)&clang::CoreturnStmt::isImplicit  )
        .def("setIsImplicit", (void (clang::CoreturnStmt::*)(bool))&clang::CoreturnStmt::setIsImplicit  )
        .def("getBeginLoc", (clang::SourceLocation (clang::CoreturnStmt::*)() const)&clang::CoreturnStmt::getBeginLoc  )
        .def("getEndLoc", (clang::SourceLocation (clang::CoreturnStmt::*)() const)&clang::CoreturnStmt::getEndLoc  )
        //.def("children", (llvm::iterator_range<clang::StmtIterator> (clang::CoreturnStmt::*)())&clang::CoreturnStmt::children  )
    ;

    py::class_<clang::FriendDecl, decl_deleter<clang::FriendDecl>::type>(m, "FriendDecl" , py::base<clang::Decl>())

        .def("getFriendType", (clang::TypeSourceInfo * (clang::FriendDecl::*)() const)&clang::FriendDecl::getFriendType , py::return_value_policy::reference_internal )
        .def("getFriendTypeNumTemplateParameterLists", (unsigned int (clang::FriendDecl::*)() const)&clang::FriendDecl::getFriendTypeNumTemplateParameterLists  )
        //.def("getFriendTypeTemplateParameterList", (clang::TemplateParameterList * (clang::FriendDecl::*)(unsigned int) const)&clang::FriendDecl::getFriendTypeTemplateParameterList , py::return_value_policy::reference_internal )
        .def("getFriendDecl", (clang::NamedDecl * (clang::FriendDecl::*)() const)&clang::FriendDecl::getFriendDecl , py::return_value_policy::reference_internal )
        .def("getFriendLoc", (clang::SourceLocation (clang::FriendDecl::*)() const)&clang::FriendDecl::getFriendLoc  )
        .def("getSourceRange", (clang::SourceRange (clang::FriendDecl::*)() const)&clang::FriendDecl::getSourceRange  )
    ;
}