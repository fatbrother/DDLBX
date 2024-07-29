#include "ir/node.hpp"

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>

#include "parser/parser.hpp"
#include "utils/logger.hpp"

using namespace ddlbx::ir;
using namespace ddlbx::utility;

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
    if (variable.ptr == nullptr) {
        Logger::error("Variable \"" + name + "\" is not defined");
        return nullptr;
    }
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
    context.getBuilder().CreateStore(value, ptr);
    context.setVariable(name, {type, ptr});
    return value;
}

llvm::Value* NBinaryOperator::codeGen(CodeGenContext& context) {
    llvm::Value* lvalue = lhs->codeGen(context);
    llvm::Value* rvalue = rhs->codeGen(context);
    llvm::Value* result = nullptr;

    if (lvalue->getType() != rvalue->getType()) {
        // TODO: Implement type coercion
        Logger::error("Type mismatch");
        return nullptr;
    }

    switch (op) {
        case OP_PLUS:
            result = context.getBuilder().CreateAdd(lvalue, rvalue);
            break;
        case OP_MINUS:
            result = context.getBuilder().CreateSub(lvalue, rvalue);
            break;
        case OP_MULT:
            result = context.getBuilder().CreateMul(lvalue, rvalue);
            break;
        case OP_DIV:
            result = context.getBuilder().CreateSDiv(lvalue, rvalue);
            break;
        case OP_AND:
            result = context.getBuilder().CreateAnd(lvalue, rvalue);
            break;
        case OP_OR:
            result = context.getBuilder().CreateOr(lvalue, rvalue);
            break;
        case OP_NOT:
            result = context.getBuilder().CreateNot(lvalue);
            break;
        case COM_EQ:
            result = context.getBuilder().CreateICmpEQ(lvalue, rvalue);
            break;
        case COM_NE:
            result = context.getBuilder().CreateICmpNE(lvalue, rvalue);
            break;
        case COM_LE:
            result = context.getBuilder().CreateICmpSLE(lvalue, rvalue);
            break;
        case COM_GE:
            result = context.getBuilder().CreateICmpSGE(lvalue, rvalue);
            break;
        case COM_LT:
            result = context.getBuilder().CreateICmpSLT(lvalue, rvalue);
            break;
        case COM_GT:
            result = context.getBuilder().CreateICmpSGT(lvalue, rvalue);
            break;
        default:
            Logger::error("Invalid binary operator");
    }

    return result;
}

llvm::Value* NUnaryOperator::codeGen(CodeGenContext& context) {
    llvm::Value* value = expr->codeGen(context);
    llvm::Value* result = nullptr;

    switch (op) {
        case OP_NOT:
            result = context.getBuilder().CreateNot(value);
            break;
        default:
            Logger::error("Invalid unary operator");
    }

    return result;
}

llvm::Value* NFunctionDefinition::codeGen(CodeGenContext& context) {
    std::vector<llvm::Type*> argTypes;

    for (auto arg : arguments) {
        argTypes.push_back(arg->type->codeGen(context));
    }

    llvm::FunctionType* functionType = llvm::FunctionType::get(retType->codeGen(context), argTypes, false);
    llvm::Function* function = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, name.c_str(), context.getModule());

    return nullptr;
}

llvm::Value* NFunctionDeclaration::codeGen(CodeGenContext& context) {
    llvm::Function* function = context.getModule().getFunction(this->definition->name.c_str());

    if (!function) {
        this->definition->codeGen(context);
        function = context.getModule().getFunction(this->definition->name.c_str());

        if (!function) {
            throw std::runtime_error("Function not found");
        }
    }

    llvm::BasicBlock* block = llvm::BasicBlock::Create(context.getContext(), "entry", function, 0);
    context.getBuilder().SetInsertPoint(block);

    auto argIt = this->definition->arguments.begin();
    for (auto it = function->arg_begin(); it != function->arg_end(); it++) {
        it->setName((*argIt)->name.c_str());
        llvm::AllocaInst* inst = context.getBuilder().CreateAlloca((*argIt)->type->codeGen(context), nullptr, (*argIt)->name.c_str());
        context.getBuilder().CreateStore(&*it, inst);
        context.setVariable((*argIt)->name, {(*argIt)->type->codeGen(context), inst});
        argIt++;
    }

    this->block->codeGen(context);

    if (block->getTerminator() == nullptr) {
        if (function->getReturnType()->isVoidTy()) {
            context.getBuilder().CreateRetVoid();
        } else {
            Logger::error("Function must return a value");
            return nullptr;
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
    if (name == "sizeof" && !parent) {
        if (arguments.size() != 1) {
            Logger::error("Function \"sizeof\" expects 1 argument, but " + std::to_string(arguments.size()) + " were provided");
            return nullptr;
        }
        llvm::Value* value = arguments[0]->codeGen(context);
        llvm::Type* type = value->getType();
        return llvm::ConstantInt::get(type, type->getPrimitiveSizeInBits() / 8);
    }

    std::vector<llvm::Value*> argValues;
    for (const auto& arg : arguments) {
        argValues.push_back(arg->codeGen(context));
    }

    std::string fullName = name;
    llvm::Value* parentValue = nullptr;
    if (parent) {
        parentValue = parent->codeGen(context);
        if (!parentValue) {
            Logger::error("Parent value code generation failed");
            return nullptr;
        }
        llvm::Type* parentType = parentValue->getType();
        std::string parentTypeName = context.getTypeName(parentType);
        
        fullName = parentTypeName + "." + name;
    }

    llvm::Function* targetFunction = context.getModule().getFunction(fullName);
    if (!targetFunction) {
        Logger::error("Function " + fullName + " not found");
        return nullptr;
    }

    if (parentValue) {
        argValues.push_back(parentValue);
    }

    if (targetFunction->arg_size() != argValues.size()) {
        Logger::error("Function " + fullName + " expects " + std::to_string(targetFunction->arg_size()) + " arguments, but " + std::to_string(argValues.size()) + " were provided");
        return nullptr;
    }

    return context.getBuilder().CreateCall(targetFunction, argValues);
}

llvm::Value* NOptStatement::codeGen(CodeGenContext& context) {
    llvm::Value* conditionValue = condition->codeGen(context);
    llvm::Function* function = context.getBuilder().GetInsertBlock()->getParent();
    llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(context.getContext(), "then", function);
    llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(context.getContext(), "ifcont", function);

    context.getBuilder().CreateCondBr(conditionValue, thenBlock, mergeBlock);

    context.getBuilder().SetInsertPoint(thenBlock);
    then->codeGen(context);

    context.getBuilder().SetInsertPoint(mergeBlock);

    return nullptr;
}

llvm::Value* NForStatement::codeGen(CodeGenContext& context) {
    llvm::Function* function = context.getBuilder().GetInsertBlock()->getParent();
    llvm::BasicBlock* loopBlock = llvm::BasicBlock::Create(context.getContext(), "loop", function);
    llvm::BasicBlock* afterBlock = llvm::BasicBlock::Create(context.getContext(), "afterloop", function);

    if (nullptr != iterator) {
        if (nullptr == init) {
            init = std::make_shared<NInteger>(0);
        }

        llvm::Value* value = iterator->codeGen(context);
        if (nullptr == value) {
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

    llvm::Value* conditionValue = condition->codeGen(context);
    llvm::Value* condition = context.getBuilder().CreateICmpNE(conditionValue, llvm::ConstantInt::get(context.getType("Boo"), 0, true));
    
    context.getBuilder().CreateCondBr(condition, loopBlock, afterBlock);

    block->codeGen(context);

    if (nullptr != increment) {
        increment->codeGen(context);
    }

    context.getBuilder().CreateBr(loopBlock);

    context.getBuilder().SetInsertPoint(afterBlock);

    return nullptr;
}

llvm::Value* NObjectDeclaration::codeGen(CodeGenContext& context) {
    llvm::StructType* structType = llvm::StructType::create(context.getContext(), name);
    std::unordered_map<std::string, llvm::Type*> nameTypeMap;
    std::vector<llvm::Type*> memberTypes;

    for (const auto& member : members) {
        memberTypes.push_back(member->type->codeGen(context));
        nameTypeMap[member->name] = memberTypes.back();
    }

    structType->setBody(memberTypes);

    context.addType(name, structType, nameTypeMap);

    // create constructor
    std::vector<llvm::Type*> argTypes;
    for (const auto& member : members) {
        argTypes.push_back(member->type->codeGen(context));
    }

    llvm::FunctionType* constructorType = llvm::FunctionType::get(structType, argTypes, false);
    llvm::Function* constructor = llvm::Function::Create(constructorType, llvm::Function::ExternalLinkage, name, context.getModule());
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context.getContext(), "entry", constructor, 0);
    context.getBuilder().SetInsertPoint(block);
    llvm::Value* structValue = context.getBuilder().CreateAlloca(structType, nullptr, name);

    auto argIt = constructor->arg_begin();
    for (auto it = memberTypes.begin(); it != memberTypes.end(); it++) {
        llvm::Value* value = &*argIt;
        llvm::Value* ptr = context.getBuilder().CreateStructGEP(structType, structValue, std::distance(memberTypes.begin(), it));
        context.getBuilder().CreateStore(value, ptr);
        argIt++;
    }

    context.getBuilder().CreateRet(structValue);

    return nullptr;
}

llvm::Value* NMethodDeclaration::codeGen(CodeGenContext& context) {
    if (nullptr == context.getType(name)) {
        Logger::error("Type \"" + name + "\" is not defined");
        return nullptr;
    }

    llvm::StructType* structType = llvm::cast<llvm::StructType>(context.getType(name));
    declaration->definition->arguments.push_back(std::make_shared<NArgument>(std::make_shared<NType>(name), "this"));
    declaration->definition->name = name + "." + declaration->definition->name;
    declaration->codeGen(context);

    return nullptr;
}