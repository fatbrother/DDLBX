#include "ir/node.hpp"

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>

#include "parser/parser.hpp"

using namespace ddlbx::ir;

llvm::Value* NProgram::codeGen(CodeGenContext& context) {
    for (auto& statement : statements) {
        statement->codeGen(context);
    }
    return nullptr;
}

llvm::Type* NType::codeGen(CodeGenContext& context) {
    return context.getType(name);
}

llvm::Value* NBlock::codeGen(CodeGenContext& context) {
    for (auto& statement : statements) {
        statement->codeGen(context);
    }
    return nullptr;
}

llvm::Value* NInteger::codeGen(CodeGenContext& context) {
    return llvm::ConstantInt::get(context.getType("Int"), value, true);
}

NBoolean::NBoolean(std::string value) {
    if (value == "true") {
        this->value = true;
    }
    else if (value == "false") {
        this->value = false;
    }
    else if (value == "maybe") {
        this->value = rand() % 2;
    }
}

llvm::Value* NBoolean::codeGen(CodeGenContext& context) {
    return llvm::ConstantInt::get(context.getType("Boo"), value, true);
}

llvm::Value* NFloat::codeGen(CodeGenContext& context) {
    return llvm::ConstantFP::get(context.getType("Flt"), value);
}

llvm::Value* NString::codeGen(CodeGenContext& context) {
    llvm::Constant* strConstant = llvm::ConstantDataArray::getString(context.getContext(), value);
    llvm::GlobalVariable* strGlobal = new llvm::GlobalVariable(context.getModule(), strConstant->getType(),
                                                               true, llvm::GlobalValue::PrivateLinkage, strConstant);
    return context.getBuilder().CreatePointerCast(strGlobal, context.getType("Str"));
}

llvm::Value* NIdentifier::codeGen(CodeGenContext& context) {
    Variable& variable = context.getVariable(name);
    return context.getBuilder().CreateLoad(variable.type, variable.ptr, name.c_str());
}

llvm::Value* NAssignment::codeGen(CodeGenContext& context) {
    llvm::Value* value = rhs->codeGen(context);
    std::string name = lhs->name;
    llvm::Value* ptr = context.getBuilder().CreateStore(value, context.getVariable(name).ptr);
    return value;
}

llvm::Value* NVariableDeclarationList::codeGen(CodeGenContext& context) {
    for (auto& declaration : declarations) {
        declaration->codeGen(context);
    }
    return nullptr;
}

llvm::Value* NVariableDeclaration::codeGen(CodeGenContext& context) {
    llvm::Value* value = assignmentExpr->codeGen(context);
    llvm::Type* type = value->getType();
    std::string name = id->name;
    llvm::Value* ptr = context.getBuilder().CreateAlloca(type, nullptr, name.c_str());
    context.setVariable(name, {type, ptr});
    return value;
}

llvm::Value* NBinaryOperator::codeGen(CodeGenContext& context) {
    llvm::Value* lvalue = lhs->codeGen(context);
    llvm::Value* rvalue = rhs->codeGen(context);
    llvm::Value* result = nullptr;

    if (lvalue->getType() != rvalue->getType()) {
        // TODO: Implement type coercion
        throw std::runtime_error("Type mismatch");
    }

    switch (op) {
        case OP_PLUS:
            result = context.getBuilder().CreateAdd(lvalue, rvalue);
        case OP_MINUS:
            result = context.getBuilder().CreateSub(lvalue, rvalue);
        case OP_MULT:
            result = context.getBuilder().CreateMul(lvalue, rvalue);
        case OP_DIV:
            result = context.getBuilder().CreateSDiv(lvalue, rvalue);
        case COM_EQ:
            result = context.getBuilder().CreateICmpEQ(lvalue, rvalue);
        case COM_NE:
            result = context.getBuilder().CreateICmpNE(lvalue, rvalue);
        case COM_LE:
            result = context.getBuilder().CreateICmpSLE(lvalue, rvalue);
        case COM_GE:
            result = context.getBuilder().CreateICmpSGE(lvalue, rvalue);
        case COM_LT:
            result = context.getBuilder().CreateICmpSLT(lvalue, rvalue);
        case COM_GT:
            result = context.getBuilder().CreateICmpSGT(lvalue, rvalue);
        default:
            throw std::runtime_error("Invalid binary operator");
    }

    return result;
}

llvm::Value* NFunctionDefinition::codeGen(CodeGenContext& context) {
    std::vector<llvm::Type*> argTypes;

    for (auto arg : arguments) {
        argTypes.push_back(arg->type->codeGen(context));
    }

    llvm::FunctionType* functionType = llvm::FunctionType::get(retType->codeGen(context), argTypes, false);
    llvm::Function* function = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, id->name.c_str(), context.getModule());

    return nullptr;
}

llvm::Value* NFunctionDeclaration::codeGen(CodeGenContext& context) {
    llvm::Function* function = context.getModule().getFunction(this->definition->id->name.c_str());

    if (!function) {
        this->definition->codeGen(context);
        function = context.getModule().getFunction(this->definition->id->name.c_str());

        if (!function) {
            throw std::runtime_error("Function not found");
        }
    }

    llvm::BasicBlock* block = llvm::BasicBlock::Create(context.getContext(), "entry", function, 0);
    context.getBuilder().SetInsertPoint(block);

    auto argIt = this->definition->arguments.begin();
    for (auto it = function->arg_begin(); it != function->arg_end(); it++) {
        it->setName((*argIt)->id->name.c_str());
        llvm::AllocaInst* inst = context.getBuilder().CreateAlloca((*argIt)->type->codeGen(context), nullptr, (*argIt)->id->name.c_str());
        context.getBuilder().CreateStore(&*it, inst);
        context.setVariable((*argIt)->id->name, {(*argIt)->type->codeGen(context), inst});
        argIt++;
    }

    this->block->codeGen(context);

    if (block->getTerminator() == nullptr) {
        if (function->getReturnType()->isVoidTy()) {
            context.getBuilder().CreateRetVoid();
        } else {
            throw std::runtime_error("Function must return a value");
        }
    }

    return function;
}

llvm::Value* NReturnStatement::codeGen(CodeGenContext& context) {
    if (expression) {
        return context.getBuilder().CreateRet(expression->codeGen(context));
    } else {
        return context.getBuilder().CreateRetVoid();
    }
}

llvm::Value* NMemberAccess::codeGen(CodeGenContext& context) {
    llvm::Value* parentValue = parent->codeGen(context);
    llvm::Type* parentType = parentValue->getType();

    for (const auto& id : ids) {
        llvm::StructType* structType = llvm::cast<llvm::StructType>(parentValue->getType());
        std::string typeName = context.getTypeName(parentType);
        int memberIndex = context.getTypeMemberIndex(typeName, id->name);
        if (memberIndex == -1) {
            throw std::runtime_error(id->name + " is not a member of " + structType->getName().str());
        }
        parentValue = context.getBuilder().CreateExtractValue(parentValue, memberIndex);
    }

    return parentValue;
}

llvm::Value* NFunctionCall::codeGen(CodeGenContext& context) {
    if (id->name == "sizeof" && !parent) {
        if (arguments.size() != 1) {
            throw std::runtime_error("sizeof function takes exactly one argument");
        }
        llvm::Value* value = arguments[0]->codeGen(context);
        llvm::Type* type = value->getType();
        return llvm::ConstantInt::get(type, type->getPrimitiveSizeInBits() / 8);
    }

    std::string fullName = id->name;
    llvm::Value* parentValue = nullptr;
    if (parent) {
        parentValue = parent->codeGen(context);
        llvm::Type* parentType = parentValue->getType();
        std::string parentTypeName = context.getTypeName(parentType);
        std::string name = id->name;
        
        fullName = parentTypeName == "" ? name : parentTypeName + "_" + name;
    }

    llvm::Function* targetFunction = context.getModule().getFunction(fullName);
    if (!targetFunction) {
        // TODO: Implement template functions
        // if (functionMap.find(name) != functionMap.end()) {
        //     for (const auto& funcHandler : functionMap[name]) {
        //         FunctionHandler& targetFuncHandler = *funcHandler;
        //         try {
        //             generateFunctionDeclaration(targetFuncHandler, parentTypeName);
        //             targetFunction = context.getModule().getFunction(fullName);
        //         } catch (std::exception& e) {
        //             continue;
        //         }
        //         break;
        //     }
        //     if (!targetFunction) {
        //         throw std::runtime_error("There is no function comforming to " + fullName);
        //     }
        // } else {
        //     throw std::runtime_error(fullName + " is not defined");
        // }
        throw std::runtime_error(fullName + " is not defined");
    }

    std::vector<llvm::Value*> argValues;
    for (const auto& arg : arguments) {
        argValues.push_back(arg->codeGen(context));
    }

    if (parentValue) {
        argValues.push_back(parentValue);
    }

    if (targetFunction->arg_size() != argValues.size()) {
        throw std::runtime_error("Function " + fullName + " expects " + std::to_string(targetFunction->arg_size()) + " arguments, but " + std::to_string(argValues.size()) + " were provided");
    }

    return context.getBuilder().CreateCall(targetFunction, argValues);
}

llvm::Value* NOptStatement::codeGen(CodeGenContext& context) {
    llvm::Value* conditionValue = condition->codeGen(context);
    llvm::Function* function = context.getBuilder().GetInsertBlock()->getParent();
    llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(context.getContext(), "then", function);
    llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(context.getContext(), "ifcont");

    context.getBuilder().CreateCondBr(conditionValue, thenBlock, mergeBlock);

    context.getBuilder().SetInsertPoint(thenBlock);
    thenBlock = then->codeGen(context) ? thenBlock : context.getBuilder().GetInsertBlock();
    context.getBuilder().CreateBr(mergeBlock);

    return nullptr;
}

llvm::Value* NForStatement::codeGen(CodeGenContext& context) {
    llvm::Function* function = context.getBuilder().GetInsertBlock()->getParent();
    llvm::BasicBlock* loopBlock = llvm::BasicBlock::Create(context.getContext(), "loop", function);
    llvm::BasicBlock* afterBlock = llvm::BasicBlock::Create(context.getContext(), "afterloop");

    if (init) {
        init->codeGen(context);
    }

    context.getBuilder().CreateBr(loopBlock);
    context.getBuilder().SetInsertPoint(loopBlock);

    llvm::Value* conditionValue = condition->codeGen(context);
    context.getBuilder().CreateCondBr(conditionValue, loopBlock, afterBlock);

    context.getBuilder().SetInsertPoint(afterBlock);

    return nullptr;
}