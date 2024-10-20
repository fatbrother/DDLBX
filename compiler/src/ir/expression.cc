#include "ir/expression.hpp"

#include "ir/statement.hpp"
#include "ir/function.hpp"
#include "ir/object.hpp"
#include "parser/parser.hpp"

using namespace ddlbx::ir;

Value NInteger::codeGen(CodeGenContext& context) {
    return Value::create(DDLBX_TYPE_INT, llvm::ConstantInt::get(context.getType(DDLBX_TYPE_INT), value));
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

Value NBoolean::codeGen(CodeGenContext& context) {
    return Value::create(DDLBX_TYPE_BOO, llvm::ConstantInt::get(context.getType(DDLBX_TYPE_BOO), value));
}

Value NFloat::codeGen(CodeGenContext& context) {
    return Value::create(DDLBX_TYPE_FLT, llvm::ConstantFP::get(context.getType(DDLBX_TYPE_FLT), value));
}

Value NString::codeGen(CodeGenContext& context) {
    llvm::Constant* strConstant = llvm::ConstantDataArray::getString(context.getContext(), value);
    llvm::GlobalVariable* strGlobal = new llvm::GlobalVariable(context.getModule(), strConstant->getType(),
                                                               true, llvm::GlobalValue::PrivateLinkage, strConstant);
    return Value::create(
        DDLBX_TYPE_STR,
        context.getBuilder().CreatePointerCast(strGlobal, context.getType(DDLBX_TYPE_STR)));
}

Value NIdentifier::codeGen(CodeGenContext& context) {
    Variable& variable = context.getVariable(name);
    llvm::Type* type = nullptr;

    if (variable.ptr == nullptr) {
        LOG_ERROR("Variable \"" + name + "\" is not defined");
        return Value::null();
    }

    type = context.getType(variable.ddlbxTypeName);
    return Value::create(
        variable.ddlbxTypeName,
        context.getBuilder().CreateLoad(type, variable.ptr, name.c_str())
    );
}

Value NAssignment::codeGen(CodeGenContext& context) {
    Value value = rhs->codeGen(context);
    std::string name = lhs->name;

    if (value.llvmValue == nullptr) {
        LOG_ERROR("Assignment failed");
        return value;
    }

    if (context.getVariable(name).ptr == nullptr) {
        LOG_ERROR("Variable \"" + name + "\" is not defined");
        return {
            .ddlbxTypeName = "",
            .llvmValue = nullptr
        };
    }

    context.getBuilder().CreateStore(value.llvmValue, context.getVariable(name).ptr);
    return value;
}

Value NVariableDeclarationList::codeGen(CodeGenContext& context) {
    for (auto& declaration : declarations) {
        declaration->codeGen(context);
    }

    return Value::null();
}

Value NVariableDeclaration::codeGen(CodeGenContext& context) {
    Value value = assignmentExpr->codeGen(context);
    llvm::Type* type = nullptr;
    std::string name = id->name;

    if (value.llvmValue == nullptr) {
        LOG_ERROR("Variable declaration failed");
        return value;
    }
    type = context.getType(value.ddlbxTypeName);

    llvm::Value* ptr = context.getBuilder().CreateAlloca(type, nullptr, name.c_str());
    context.getBuilder().CreateStore(value.llvmValue, ptr);
    context.setVariable(name, {value.ddlbxTypeName, ptr});

    return value;
}

Value NBinaryOperator::codeGen(CodeGenContext& context) {
    Value lvalue = lhs->codeGen(context);
    Value rvalue = rhs->codeGen(context);
    llvm::Value* result = nullptr;

    if (lvalue.llvmValue == nullptr || rvalue.llvmValue == nullptr) {
        LOG_ERROR("Binary operator failed");
        return Value::null();
    }

    if (lvalue.ddlbxTypeName != rvalue.ddlbxTypeName) {
        // TODO: Implement type coercion
        LOG_ERROR("Type mismatch");
        return Value::null();
    }

    switch (op) {
        case OP_PLUS:
            result = context.getBuilder().CreateAdd(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case OP_MINUS:
            result = context.getBuilder().CreateSub(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case OP_MULT:
            result = context.getBuilder().CreateMul(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case OP_DIV:
            result = context.getBuilder().CreateSDiv(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case OP_AND:
            result = context.getBuilder().CreateAnd(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case OP_OR:
            result = context.getBuilder().CreateOr(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case COM_EQ:
            result = context.getBuilder().CreateICmpEQ(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case COM_NE:
            result = context.getBuilder().CreateICmpNE(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case COM_LE:
            result = context.getBuilder().CreateICmpSLE(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case COM_GE:
            result = context.getBuilder().CreateICmpSGE(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case COM_LT:
            result = context.getBuilder().CreateICmpSLT(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case COM_GT:
            result = context.getBuilder().CreateICmpSGT(lvalue.llvmValue, rvalue.llvmValue);
            break;
        default:
            LOG_ERROR("Invalid binary operator");
    }

    return Value::create(lvalue.ddlbxTypeName, result);
}

Value NUnaryOperator::codeGen(CodeGenContext& context) {
    Value value = expr->codeGen(context);
    llvm::Value* result = nullptr;

    if (value.llvmValue == nullptr) {
        LOG_ERROR("Unary operator failed");
        return value;
    }

    switch (op) {
        case OP_NOT:
            result = context.getBuilder().CreateNot(value.llvmValue);
            break;
        default:
            LOG_ERROR("Invalid unary operator");
    }

    return Value::create(value.ddlbxTypeName, result);
}

Value NMemberAccess::codeGen(CodeGenContext& context) {
    auto [parentTypeName, parentValue] = parent->codeGen(context);
    llvm::Type* parentType = nullptr;

    if (parentValue == nullptr) {
        LOG_ERROR("Parent value error");
        return Value::null();
    }

    parentType = context.getType(parentTypeName);

    for (const auto& id : ids) {
        llvm::StructType* structType = llvm::cast<llvm::StructType>(parentType);
        int memberIndex = context.getTypeMemberIndex(parentTypeName, id->name);
        if (memberIndex == -1) {
            LOG_ERROR("Member " + id->name + " not found in type " + parentTypeName);
            return Value::null();
        }
        parentValue = context.getBuilder().CreateExtractValue(parentValue, memberIndex);
    }

    return Value::create(parentTypeName, parentValue);
}
