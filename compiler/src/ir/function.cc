#include "ir/function.hpp"

#include "utils/logger.hpp"
#include "utils/scope_guard.hpp"
#include "utils/type_parser.hpp"

using namespace ddlbx::ir;

Value NFunctionDefinition::codeGenValue(CodeGenContext& context) {
    std::vector<llvm::Type*> argTypes;

    for (auto arg : arguments) {
        argTypes.push_back(arg->type->codeGenValue(context).type);
        if (argTypes.back() == nullptr) {
            LOG_ERROR("Function argument type generation failed");
            return Value::null();
        }
    }

    llvm::FunctionType* functionType = llvm::FunctionType::get(retType->codeGenValue(context).type, argTypes, false);
    llvm::Function* function = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, name.c_str(), context.getModule());
    context.registerFunction(name, retType->name);

    return Value::create(DDLBX_TYPE_FUN, function);
}

Value NFunctionDeclaration::codeGenValue(CodeGenContext& context) {
    llvm::Function* function = context.getModule().getFunction(this->definition->name.c_str());

    if (!function) {
        function = static_cast<llvm::Function*>(this->definition->codeGenValue(context).llvmValue);

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

        auto [typeName, type, _] = (*argIt)->type->codeGenValue(context);
        if (it->getType() != type) {
            LOG_ERROR("Function argument type error");
            return Value::null();
        }

        llvm::AllocaInst* inst = context.getBuilder().CreateAlloca(type, nullptr, (*argIt)->name.c_str());
        context.getBuilder().CreateStore(&*it, inst);
        context.setVariable((*argIt)->name, {typeName, inst});
        argIt++;
    }

    this->block->codeGenValue(context);

    if (block->getTerminator() == nullptr) {
        if (function->getReturnType()->isVoidTy()) {
            context.getBuilder().CreateRetVoid();
        } else {
            LOG_ERROR("Function must return a value");
            return Value::null();
        }
    }

    return Value::create(DDLBX_TYPE_FUN, function);
}

Value NTemplateFunctionDeclaration::codeGenValue(CodeGenContext& context, std::vector<std::string> templateArgs) {
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

    definition->name += utility::getTemplateString(templateArgs);
    auto resetNameGuard = makeGuard([&]() {
        definition->name = originalName;
    });

    auto func = NFunctionDeclaration::codeGenValue(context);

    return func;
}

Value NFunctionCall::codeGenValue(CodeGenContext& context) {
    if (name == "sizeof" && !parent) {
        if (arguments.size() != 1) {
            LOG_ERROR("Function \"sizeof\" expects 1 argument, but " + std::to_string(arguments.size()) + " were provided");
            return Value::null();
        }
        Value value = arguments[0]->codeGenValue(context);
        llvm::Type* type = context.getType(value.ddlbxTypeName).type;
        if (type == nullptr) {
            LOG_ERROR("Type \"" + value.ddlbxTypeName + "\" is not defined");
            return Value::null();
        }
        return Value::create(DDLBX_TYPE_INT, context.getBuilder().getInt32(type->getPrimitiveSizeInBits() / 8));
    }

    std::vector<llvm::Value*> argValues;
    for (const auto& arg : arguments) {
        argValues.push_back(arg->codeGenValue(context).llvmValue);
        if (argValues.back() == nullptr) {
            LOG_ERROR("Function argument error");
            return Value::null();
        }
    }

    std::string fullName = name;
    Value parentValue = Value::null();
    if (parent) {
        parentValue = parent->codeGenValue(context);
        if (parentValue.llvmValue == nullptr) {
            LOG_ERROR("Parent value error");
            return Value::null();
        }

        fullName = parentValue.ddlbxTypeName + "." + name;
    }

    if (false == templateArgs.empty()) {
        fullName += utility::getTemplateString(templateArgs);
    }

    llvm::Function* targetFunction = context.getModule().getFunction(fullName);
    std::string returnType = context.getFunction(fullName).returnType;
    if (!targetFunction) {
        LOG_DEBUG("Function " + fullName + " not found");

        if (std::string::npos != parentValue.ddlbxTypeName.find("<")) {
            LOG_DEBUG("Trying to find " + parentValue.ddlbxTypeName + " method " + name);
            std::string targetName = utility::getOrginalNameFromFullName(parentValue.ddlbxTypeName) + "." + name;
            std::shared_ptr<NTemplateObjectMethodDeclaration> templateObjectMethod = context.getTemplateObjectMethod(targetName);
            std::vector<std::string> templateArgs = utility::getTemplateArgsFromFullName(parentValue.ddlbxTypeName);

            if (nullptr != templateObjectMethod) {
                targetFunction = static_cast<llvm::Function*>(templateObjectMethod->codeGenValue(context, templateArgs).llvmValue);
                returnType = templateObjectMethod->definition->retType->name;
                LOG_DEBUG("Template object method " + fullName + " created");
            } else {
                LOG_DEBUG("Template object method " + name + " creation failed");
            }
        }

        if (nullptr == targetFunction && false == templateArgs.empty()) {
            LOG_DEBUG("Trying to find template function " + name);
            std::shared_ptr<NTemplateFunctionDeclaration> templateFunction = context.getTemplateFunction(name);
            if (nullptr != templateFunction) {
                targetFunction = static_cast<llvm::Function*>(templateFunction->codeGenValue(context, templateArgs).llvmValue);
                returnType = templateFunction->definition->retType->name;
                LOG_DEBUG("Template function " + fullName + " created");
            } else {
                LOG_DEBUG("Template function " + name + " creation failed");
            }
        }

        if (nullptr == targetFunction) {
            LOG_DEBUG("Trying to find trait method " + name);
            std::shared_ptr<NTraitMethodDeclaration> traitMethod = context.getTraitMethod(name);
            if (nullptr != traitMethod) {
                targetFunction = static_cast<llvm::Function*>(traitMethod->codeGenValue(context, parentValue.ddlbxTypeName).llvmValue);
                returnType = traitMethod->definition->retType->name;
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

Value NMethodDeclaration::codeGenValue(CodeGenContext& context) {
    auto methodDefintion = std::dynamic_pointer_cast<NMethodDefinition>(this->definition);
    llvm::Type* parentType = context.getType(methodDefintion->parentName).type;
    if (nullptr == parentType) {
        LOG_ERROR("Type \"" + methodDefintion->parentName + "\" is not defined");
        return Value::null();
    }

    llvm::StructType* structType = llvm::cast<llvm::StructType>(parentType);
    methodDefintion->arguments.push_back(std::make_shared<NArgument>(std::make_shared<NType>(methodDefintion->parentName), "this"));
    auto resetGuard = makeGuard([&]() {
        methodDefintion->arguments.pop_back();
    });

    std::string originalName = methodDefintion->name;
    methodDefintion->name = methodDefintion->parentName + "." + methodDefintion->name;
    auto resetNameGuard = makeGuard([&]() {
        methodDefintion->name = originalName;
    });

    auto res = methodDefintion->codeGenValue(context);

    return NFunctionDeclaration::codeGenValue(context);
}

Value NTemplateObjectMethodDeclaration::codeGenValue(CodeGenContext& context, std::vector<std::string> templateArgs) {
    auto methodDefintion = std::dynamic_pointer_cast<NTemplateObjectMethodDefinition>(this->definition);
    methodDefintion->parentName += utility::getTemplateString(templateArgs);
    context.pushTemplateTypeStack();
    auto popStackGuard = makeGuard([&]() {
        context.popTemplateTypeStack();
        methodDefintion->parentName = utility::getOrginalNameFromFullName(methodDefintion->parentName);
    });

    for (int i = 0; i < templateArgs.size(); i++) {
        LOG_DEBUG("Registering template type " + methodDefintion->templates[i] + " as " + templateArgs[i]);
        context.registerTemplateType(methodDefintion->templates[i], templateArgs[i]);
    }

    return NMethodDeclaration::codeGenValue(context);
}

Value NTraitMethodDeclaration::codeGenValue(CodeGenContext& context, std::string parentName) {
    auto methodDefintion = std::dynamic_pointer_cast<NMethodDefinition>(this->definition);
    methodDefintion->parentName = parentName;

    return NMethodDeclaration::codeGenValue(context);
}