#include "ir/statement.hpp"

#include "utils/logger.hpp"
#include "utils/scope_guard.hpp"
#include "ir/function.hpp"
#include "parser/parser.hpp"
#include "parser/parse_file.hpp"

using namespace ddlbx::ir;
using namespace ddlbx::utility;

Value NReturnStatement::codeGen(CodeGenContext& context) {
    if (expression) {
        Value value = expression->codeGen(context);
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

Value NBlock::codeGen(CodeGenContext& context) {
    for (auto& statement : statements) {
        statement->codeGen(context);
    }
    return Value::null();
}

Value NOptStatement::codeGen(CodeGenContext& context) {
    llvm::Value* conditionValue = condition->codeGen(context).llvmValue;
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

    then->codeGen(context);

    return Value::null();
}

Value NForStatement::codeGen(CodeGenContext& context) {
    llvm::Function* function = context.getBuilder().GetInsertBlock()->getParent();
    llvm::BasicBlock* loopBlock = llvm::BasicBlock::Create(context.getContext(), "loop", function);
    llvm::BasicBlock* afterBlock = llvm::BasicBlock::Create(context.getContext(), "afterloop", function);

    if (nullptr != iterator) {
        if (nullptr == init) {
            init = std::make_shared<NInteger>(0);
        }

        bool isIteratorDeclared = context.getVariable(iterator->name).ptr != nullptr;
        if (false == isIteratorDeclared) {
            std::shared_ptr<NVariableDeclaration> declaration = std::make_shared<NVariableDeclaration>(iterator, init);
            declaration->codeGen(context);
        }

        if (nullptr == increment) {
            increment = std::make_shared<NBinaryOperator>(iterator, OP_PLUS, std::make_shared<NInteger>(1));
        } else {
            increment = std::make_shared<NBinaryOperator>(iterator, OP_PLUS, increment);
        }
    }

    context.getBuilder().CreateBr(loopBlock);
    context.getBuilder().SetInsertPoint(loopBlock);
    auto scopeGuard = makeGuard([&]() {
        context.getBuilder().CreateBr(loopBlock);
        context.getBuilder().SetInsertPoint(afterBlock);
    });

    llvm::Value* conditionValue = condition->codeGen(context).llvmValue;
    if (nullptr == conditionValue) {
        LOG_ERROR("Loop statement condition error");
        return Value::null();
    }

    llvm::Value* condition = context.getBuilder().CreateICmpNE(conditionValue, llvm::ConstantInt::get(llvm::Type::getInt1Ty(context.getContext()), 0, true));

    context.getBuilder().CreateCondBr(condition, loopBlock, afterBlock);

    block->codeGen(context);

    if (nullptr != increment) {
        increment->codeGen(context);
    }

    return Value::null();
}

Value NGetModule::codeGen(CodeGenContext& context) {
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

    programs.back()->codeGen(context);

    return Value::null();
}