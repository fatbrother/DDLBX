#include "ir/expression.hpp"

#include "ir/statement.hpp"
#include "ir/function.hpp"
#include "ir/object.hpp"
#include "parser/parser.hpp"

using namespace ddlbx::ir;

Value NInteger::codeGen(CodeGenContext& context) {
    return Value::create(DDLBX_TYPE_INT, llvm::ConstantInt::get(context.getType(DDLBX_TYPE_INT).type, value));
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
    return Value::create(DDLBX_TYPE_BOO, llvm::ConstantInt::get(context.getType(DDLBX_TYPE_BOO).type, value));
}

Value NFloat::codeGen(CodeGenContext& context) {
    return Value::create(DDLBX_TYPE_FLT, llvm::ConstantFP::get(context.getType(DDLBX_TYPE_FLT).type, value));
}

Value NString::codeGen(CodeGenContext& context) {
    llvm::Constant* strConstant = llvm::ConstantDataArray::getString(context.getContext(), value);
    llvm::GlobalVariable* strGlobal = new llvm::GlobalVariable(context.getModule(), strConstant->getType(),
                                                               true, llvm::GlobalValue::PrivateLinkage, strConstant);
    return Value::create(
        DDLBX_TYPE_STR,
        context.getBuilder().CreatePointerCast(strGlobal, context.getType(DDLBX_TYPE_STR).type));
}

Value NIdentifier::codeGen(CodeGenContext& context) {
    Variable& variable = context.getVariable(name);
    llvm::Type* type = nullptr;

    if (variable.ptr == nullptr) {
        LOG_ERROR("Variable \"" + name + "\" is not defined");
        return Value::null();
    }

    type = context.getType(variable.ddlbxTypeName).type;
    if (type == nullptr) {
        LOG_ERROR("Type \"" + variable.ddlbxTypeName + "\" is not defined");
        return Value::null();
    }
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

    type = context.getType(value.ddlbxTypeName).type;
    if (type == nullptr) {
        LOG_ERROR("Type \"" + value.ddlbxTypeName + "\" is not defined");
        return Value::null();
    }

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
        if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT && rvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
            rvalue.llvmValue = context.getBuilder().CreateSIToFP(rvalue.llvmValue, context.getType(DDLBX_TYPE_FLT).type);
        } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT && rvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
            lvalue.llvmValue = context.getBuilder().CreateSIToFP(lvalue.llvmValue, context.getType(DDLBX_TYPE_FLT).type);
        } else {
            // TODO: Implement custom operator overloading
            LOG_ERROR("Binary operator type mismatch");
            return Value::null();
        }
    }

    switch (op) {
        case OP_PLUS:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateAdd(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFAdd(lvalue.llvmValue, rvalue.llvmValue);
            }
            break;
        case OP_MINUS:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateSub(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFSub(lvalue.llvmValue, rvalue.llvmValue);
            }
            break;
        case OP_MULT:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateMul(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFMul(lvalue.llvmValue, rvalue.llvmValue);
            }
            break;
        case OP_DIV:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateSDiv(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFDiv(lvalue.llvmValue, rvalue.llvmValue);
            }
            break;
        case OP_AND:
            result = context.getBuilder().CreateAnd(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case OP_OR:
            result = context.getBuilder().CreateOr(lvalue.llvmValue, rvalue.llvmValue);
            break;
        case COM_EQ:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateICmpEQ(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFCmpOEQ(lvalue.llvmValue, rvalue.llvmValue);
            }
            break;
        case COM_NE:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateICmpNE(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFCmpONE(lvalue.llvmValue, rvalue.llvmValue);
            }
            break;
        case COM_LE:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateICmpSLE(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFCmpOLE(lvalue.llvmValue, rvalue.llvmValue);
            }
            break;
        case COM_GE:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateICmpSGE(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFCmpOGE(lvalue.llvmValue, rvalue.llvmValue);
            }
            break;
        case COM_LT:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateICmpSLT(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFCmpOLT(lvalue.llvmValue, rvalue.llvmValue);
            }
            break;
        case COM_GT:
            if (lvalue.ddlbxTypeName == DDLBX_TYPE_INT) {
                result = context.getBuilder().CreateICmpSGT(lvalue.llvmValue, rvalue.llvmValue);
            } else if (lvalue.ddlbxTypeName == DDLBX_TYPE_FLT) {
                result = context.getBuilder().CreateFCmpOGT(lvalue.llvmValue, rvalue.llvmValue);
            }
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

    parentType = context.getType(parentTypeName).type;
    if (parentType == nullptr) {
        LOG_ERROR("Type \"" + parentTypeName + "\" is not defined");
        return Value::null();
    }

    for (const auto& id : ids) {
        llvm::StructType* structType = llvm::cast<llvm::StructType>(parentType);
        int memberIndex = context.getTypeMemberIndex(parentTypeName, id->name);
        if (memberIndex == -1) {
            LOG_ERROR("Member " + id->name + " not found in type " + parentTypeName);
            return Value::null();
        }
        parentValue = context.getBuilder().CreateExtractValue(parentValue, memberIndex);
        parentTypeName = context.getType(parentTypeName).nameTypeMap[id->name];
    }

    return Value::create(parentTypeName, parentValue);
}
