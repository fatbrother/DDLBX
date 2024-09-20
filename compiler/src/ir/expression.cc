#include "ir/expression.hpp"

#include "ir/statement.hpp"
#include "ir/function.hpp"
#include "ir/object.hpp"
#include "parser/parser.hpp"

using namespace ddlbx::ir;

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
        LOG_ERROR("Variable \"" + name + "\" is not defined");
        return nullptr;
    }
    return context.getBuilder().CreateLoad(variable.type, variable.ptr, name.c_str());
}

llvm::Value* NAssignment::codeGen(CodeGenContext& context) {
    llvm::Value* value = rhs->codeGen(context);
    std::string name = lhs->name;

    if (value == nullptr) {
        LOG_ERROR("Assignment failed");
        return nullptr;
    }

    if (context.getVariable(name).ptr == nullptr) {
        LOG_ERROR("Variable \"" + name + "\" is not defined");
        return nullptr;
    }

    context.getBuilder().CreateStore(value, context.getVariable(name).ptr);
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
    llvm::Type* type = nullptr;
    std::string name = id->name;

    if (value == nullptr) {
        LOG_ERROR("Variable declaration failed");
        return nullptr;
    }
    type = value->getType();

    llvm::Value* ptr = context.getBuilder().CreateAlloca(type, nullptr, name.c_str());
    context.getBuilder().CreateStore(value, ptr);
    context.setVariable(name, {type, ptr});

    return value;
}

llvm::Value* NBinaryOperator::codeGen(CodeGenContext& context) {
    llvm::Value* lvalue = lhs->codeGen(context);
    llvm::Value* rvalue = rhs->codeGen(context);
    llvm::Value* result = nullptr;

    if (lvalue == nullptr || rvalue == nullptr) {
        LOG_ERROR("Binary operator failed");
        return nullptr;
    }

    if (lvalue->getType() != rvalue->getType()) {
        // TODO: Implement type coercion
        LOG_ERROR("Type mismatch");
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
            LOG_ERROR("Invalid binary operator");
    }

    return result;
}

llvm::Value* NUnaryOperator::codeGen(CodeGenContext& context) {
    llvm::Value* value = expr->codeGen(context);
    llvm::Value* result = nullptr;

    if (value == nullptr) {
        LOG_ERROR("Unary operator failed");
        return nullptr;
    }

    switch (op) {
        case OP_NOT:
            result = context.getBuilder().CreateNot(value);
            break;
        default:
            LOG_ERROR("Invalid unary operator");
    }

    return result;
}

llvm::Value* NMemberAccess::codeGen(CodeGenContext& context) {
    llvm::Value* parentValue = parent->codeGen(context);
    llvm::Type* parentType = nullptr;

    if (parentValue == nullptr) {
        LOG_ERROR("Parent value error");
        return nullptr;
    }
    parentType = parentValue->getType();

    for (const auto& id : ids) {
        llvm::StructType* structType = llvm::cast<llvm::StructType>(parentValue->getType());
        std::string typeName = context.getTypeName(parentType);
        int memberIndex = context.getTypeMemberIndex(typeName, id->name);
        if (memberIndex == -1) {
            LOG_ERROR("Member " + id->name + " not found in type " + typeName);
            return nullptr;
        }
        parentValue = context.getBuilder().CreateExtractValue(parentValue, memberIndex);
    }

    return parentValue;
}
