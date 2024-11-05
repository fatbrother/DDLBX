#include "ir/statement.hpp"

#include "utils/logger.hpp"
#include "utils/scope_guard.hpp"
#include "ir/function.hpp"
#include "parser/parser.hpp"
#include "parser/parse_file.hpp"

using namespace ddlbx::ir;
using namespace ddlbx::utility;

Value NReturnStatement::codeGenValue(CodeGenContext& context) {
    if (expression) {
        Value value = expression->codeGenValue(context);
        if (value.llvmValue == nullptr) {
            LOG_ERROR("Return statement failed");
            return Value::null();
        }

        context.getBuilder().CreateRet(value.llvmValue);
    } else {
        context.getBuilder().CreateRetVoid();
    }

    return Value::null();
}

Value NBlock::codeGenValue(CodeGenContext& context) {
    for (auto& statement : statements) {
        statement->codeGenValue(context);
    }
    return Value::null();
}

Value NOptStatement::codeGenValue(CodeGenContext& context) {
    llvm::Value* conditionValue = condition->codeGenValue(context).llvmValue;
    llvm::Function* function = context.getBuilder().GetInsertBlock()->getParent();
    llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(context.getContext(), "then", function);
    llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(context.getContext(), "ifcont", function);

    if (nullptr == conditionValue) {
        LOG_ERROR("Opt statement condition error");
        return Value::null();
    }

    context.getBuilder().CreateCondBr(conditionValue, thenBlock, mergeBlock);

    context.getBuilder().SetInsertPoint(thenBlock);
    auto scopeGuard = makeGuard([&]() {
        context.getBuilder().SetInsertPoint(mergeBlock);
    });

    then->codeGenValue(context);

    return Value::null();
}

Value NForStatement::codeGenValue(CodeGenContext& context) {
    llvm::Function* function = context.getBuilder().GetInsertBlock()->getParent();
    llvm::BasicBlock* loopBlock = llvm::BasicBlock::Create(context.getContext(), "loop", function);
    llvm::BasicBlock* conditionBlock = llvm::BasicBlock::Create(context.getContext(), "condition", function);
    llvm::BasicBlock* afterBlock = llvm::BasicBlock::Create(context.getContext(), "afterloop", function);

    if (nullptr != iterator) {
        if (nullptr == init) {
            init = std::make_shared<NInteger>(0);
        }

        bool isIteratorDeclared = context.getVariable(iterator->name).ptr != nullptr;
        if (false == isIteratorDeclared) {
            std::shared_ptr<NVariableDeclaration> declaration = std::make_shared<NVariableDeclaration>(iterator, init);
            declaration->codeGenValue(context);
        }

        if (nullptr == increment) {
            increment = std::make_shared<NBinaryOperator>(iterator, OP_PLUS, std::make_shared<NInteger>(1));
        } else {
            increment = std::make_shared<NBinaryOperator>(iterator, OP_PLUS, increment);
        }
    }

    context.getBuilder().CreateBr(conditionBlock);
    context.getBuilder().SetInsertPoint(conditionBlock);
    auto conditionScopeGuard = makeGuard([&]() {
        context.getBuilder().CreateBr(conditionBlock);
        context.getBuilder().SetInsertPoint(afterBlock);
    });

    llvm::Value* conditionValue = condition->codeGenValue(context).llvmValue;
    if (nullptr == conditionValue) {
        LOG_ERROR("Loop statement condition error");
        return Value::null();
    }

    llvm::Value* condition = nullptr;
    if (nullptr != iterator) {
        llvm::Value* iterationValue = nullptr;
        Variable iteratorVariable = context.getVariable(iterator->name);
        iterationValue = context.getBuilder().CreateLoad(context.getType(iteratorVariable.ddlbxTypeName).type, iteratorVariable.ptr);
        condition = context.getBuilder().CreateICmpNE(conditionValue, iterationValue);
    } else {
        condition = context.getBuilder().CreateICmpNE(conditionValue, llvm::ConstantInt::get(llvm::Type::getInt1Ty(context.getContext()), 0, true));
    }

    context.getBuilder().CreateCondBr(condition, loopBlock, afterBlock);

    conditionScopeGuard.dismiss();

    context.getBuilder().SetInsertPoint(loopBlock);
    auto loopScopeGuard = makeGuard([&]() {
        context.getBuilder().SetInsertPoint(afterBlock);
    });

    block->codeGenValue(context);

    if (nullptr != increment) {
        context.getBuilder().CreateStore(increment->codeGenValue(context).llvmValue, context.getVariable(iterator->name).ptr);
    }

    context.getBuilder().CreateBr(conditionBlock);

    return Value::null();
}

Value NGetModule::codeGenValue(CodeGenContext& context) {
    if (parser::parseFile(file) == false) {
        LOG_ERROR("Failed to parse file: " + file);
        return Value::null();
    }

    if (1 > programs.size() || nullptr == programs.back()) {
        LOG_ERROR("Failed to parse file: " + file);
        return Value::null();
    }

    auto currPos = context.getBuilder().saveIP();
    auto scopeGuard = makeGuard([&]() {
        context.getBuilder().restoreIP(currPos);
    });

    programs.back()->codeGenValue(context);

    return Value::null();
}