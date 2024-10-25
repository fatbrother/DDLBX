#include "ir/function.hpp"

#include "utils/logger.hpp"
#include "utils/scope_guard.hpp"

using namespace ddlbx::ir;

Value NFunctionDefinition::codeGen(CodeGenContext& context) {
    std::vector<llvm::Type*> argTypes;

    for (auto arg : arguments) {
        argTypes.push_back(arg->type->codeGen(context));
        if (argTypes.back() == nullptr) {
            LOG_ERROR("Function argument type generation failed");
            return Value::null();
        }
    }

    llvm::FunctionType* functionType = llvm::FunctionType::get(retType->codeGen(context), argTypes, false);
    llvm::Function* function = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, name.c_str(), context.getModule());

    return Value::create(DDLBX_TYPE_FUN, function);
}

Value NFunctionDeclaration::codeGen(CodeGenContext& context) {
    llvm::Function* function = context.getModule().getFunction(this->definition->name.c_str());

    if (!function) {
        function = static_cast<llvm::Function*>(this->definition->codeGen(context).llvmValue);

        if (!function) {
            LOG_ERROR("Function " + this->definition->name + " creation failed");
            return Value::null();
        }
    }

    if (!block) {
        LOG_DEBUG("Function " + this->definition->name + " has no block");
        return Value::create(DDLBX_TYPE_FUN, function);
    }

    llvm::BasicBlock* block = llvm::BasicBlock::Create(context.getContext(), "entry", function, 0);
    llvm::BasicBlock* currentBlock = context.getBuilder().GetInsertBlock();
    context.getBuilder().SetInsertPoint(block);
    auto scopeGuard = makeGuard([&]() {
        context.getBuilder().SetInsertPoint(currentBlock);
    });

    auto argIt = this->definition->arguments.begin();
    for (auto it = function->arg_begin(); it != function->arg_end(); it++) {
        it->setName((*argIt)->name.c_str());

        llvm::Type* type = (*argIt)->type->codeGen(context);
        if (it->getType() != type) {
            LOG_ERROR("Function argument type error");
            return Value::null();
        }

        llvm::AllocaInst* inst = context.getBuilder().CreateAlloca(type, nullptr, (*argIt)->name.c_str());
        context.getBuilder().CreateStore(&*it, inst);
        context.setVariable((*argIt)->name, {(*argIt)->type->name, inst});
        argIt++;
    }

    this->block->codeGen(context);

    if (block->getTerminator() == nullptr) {
        if (function->getReturnType()->isVoidTy()) {
            context.getBuilder().CreateRetVoid();
        } else {
            LOG_ERROR("Function must return a value");
            return Value::null();
        }
    }

    context.registerFunction(this->definition->name, this->definition->retType->name);

    return Value::create(DDLBX_TYPE_FUN, function);
}

Value NTemplateFunctionDeclaration::codeGen(CodeGenContext& context, std::vector<std::string> templateArgs) {
    std::shared_ptr<NTemplateFunctionDefinition> definition = std::dynamic_pointer_cast<NTemplateFunctionDefinition>(this->definition);

    context.pushTemplateTypeStack();
    auto popStackGuard = makeGuard([&]() {
        context.popTemplateTypeStack();
    });

    for (int i = 0; i < templateArgs.size(); i++) {
        LOG_DEBUG("Registering template type " + definition->templates[i] + " as " + templateArgs[i]);
        context.registerTemplateType(definition->templates[i], templateArgs[i]);
    }

    std::string originalName = definition->name;

    definition->name += "<";
    for (const auto& arg : templateArgs) {
        definition->name += arg + ",";
    }
    definition->name.pop_back();
    definition->name += ">";
    auto resetNameGuard = makeGuard([&]() {
        definition->name = originalName;
    });

    auto func = NFunctionDeclaration::codeGen(context);

    return func;
}

Value NFunctionCall::codeGen(CodeGenContext& context) {
    if (name == "sizeof" && !parent) {
        if (arguments.size() != 1) {
            LOG_ERROR("Function \"sizeof\" expects 1 argument, but " + std::to_string(arguments.size()) + " were provided");
            return Value::null();
        }
        Value value = arguments[0]->codeGen(context);
        llvm::Type* type = context.getType(value.ddlbxTypeName).type;
        if (type == nullptr) {
            LOG_ERROR("Type \"" + value.ddlbxTypeName + "\" is not defined");
            return Value::null();
        }
        return Value::create(DDLBX_TYPE_INT, context.getBuilder().getInt32(type->getPrimitiveSizeInBits() / 8));
    }

    std::vector<llvm::Value*> argValues;
    for (const auto& arg : arguments) {
        argValues.push_back(arg->codeGen(context).llvmValue);
        if (argValues.back() == nullptr) {
            LOG_ERROR("Function argument error");
            return Value::null();
        }
    }

    std::string fullName = name;
    Value parentValue = Value::null();
    if (parent) {
        parentValue = parent->codeGen(context);
        if (parentValue.llvmValue == nullptr) {
            LOG_ERROR("Parent value error");
            return Value::null();
        }

        fullName = parentValue.ddlbxTypeName + "." + name;
    }

    if (false == templateArgs.empty()) {
        fullName += "<";
        for (const auto& arg : templateArgs) {
            fullName += arg + ",";
        }
        fullName.pop_back();
        fullName += ">";
    }

    llvm::Function* targetFunction = context.getModule().getFunction(fullName);
    std::string returnType = context.getFunction(fullName).returnType;
    if (!targetFunction) {
        LOG_DEBUG("Function " + fullName + " not found");

        if (false == templateArgs.empty()) {
            LOG_DEBUG("Trying to find template function " + name);
            std::shared_ptr<NTemplateFunctionDeclaration> templateFunction = context.getTemplateFunction(name);
            if (nullptr != templateFunction) {
                targetFunction = static_cast<llvm::Function*>(templateFunction->codeGen(context, templateArgs).llvmValue);
                returnType = templateFunction->definition->retType->name;
                LOG_DEBUG("Template function " + fullName + " created");
            } else {
                LOG_DEBUG("Template function " + name + " creation failed");
            }
        } else {
            LOG_DEBUG("Trying to find trait method " + name);
            std::shared_ptr<NTraitMethodDeclaration> traitMethod = context.getTraitMethod(name);
            if (nullptr != traitMethod) {
                targetFunction = static_cast<llvm::Function*>(traitMethod->codeGen(context, parentValue.ddlbxTypeName).llvmValue);
                returnType = traitMethod->declaration->definition->retType->name;
                LOG_DEBUG("Trait method " + fullName + " created");
            } else {
                LOG_DEBUG("Trait method " + name + " creation failed");
            }
        }

        if (nullptr == targetFunction) {
            LOG_ERROR("Function " + fullName + " creation failed");
            return Value::null();
        }
    }

    if (parentValue.llvmValue != nullptr) {
        argValues.push_back(parentValue.llvmValue);
    }

    if (targetFunction->arg_size() != argValues.size()) {
        LOG_ERROR("Function " + fullName + " expects " + std::to_string(targetFunction->arg_size()) + " arguments, but " + std::to_string(argValues.size()) + " were provided");
        return Value::null();
    }

    return Value::create(returnType, context.getBuilder().CreateCall(targetFunction, argValues));
}

Value NMethodDeclaration::codeGen(CodeGenContext& context) {
    llvm::Type* parentType = context.getType(parentName).type;
    if (nullptr == parentType) {
        LOG_ERROR("Type \"" + parentName + "\" is not defined");
        return Value::null();
    }

    llvm::StructType* structType = llvm::cast<llvm::StructType>(parentType);
    declaration->definition->arguments.push_back(std::make_shared<NArgument>(std::make_shared<NType>(parentName), "this"));
    auto res = declaration->codeGen(context);
    declaration->definition->arguments.pop_back();

    return res;
}

Value NTraitMethodDeclaration::codeGen(CodeGenContext& context, std::string parentName) {
    this->parentName = parentName;
    declaration->definition->name = parentName + "." + declaration->definition->name;

    return NMethodDeclaration::codeGen(context);
}