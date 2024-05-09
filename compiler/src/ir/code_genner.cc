#include "ir/code_genner.hpp"

#include <llvm/IR/Verifier.h>

#include <iostream>
#include <stack>

namespace ddlbx {
namespace ir {

std::map<std::string, int> CodeGenner::opPropertyMap = {
    {"and", 1},
    {"or", 1},
    {"==", 2},
    {"!=", 2},
    {"<", 2},
    {"<=", 2},
    {">", 2},
    {">=", 2},
    {"+", 3},
    {"-", 3},
    {"*", 4},
    {"/", 4},
    {"%", 4},
    {"!", 5},
};

std::map<std::string, llvm::Instruction::BinaryOps> CodeGenner::binaryOpMap = {
    {"+", llvm::Instruction::BinaryOps::Add},
    {"-", llvm::Instruction::BinaryOps::Sub},
    {"*", llvm::Instruction::BinaryOps::Mul},
    {"/", llvm::Instruction::BinaryOps::SDiv},
    {"%", llvm::Instruction::BinaryOps::SRem},
};

std::map<std::string, CodeGenner::ExpressionType> CodeGenner::expressionTypeMap = {
    {"ddlbx::parser::VariableDeclaration", CodeGenner::ExpressionType::VariableDeclaration},
    {"ddlbx::parser::Return", CodeGenner::ExpressionType::Return},
    {"ddlbx::parser::Statement", CodeGenner::ExpressionType::Statement},
    {"ddlbx::parser::Conditional", CodeGenner::ExpressionType::Conditional},
    {"ddlbx::parser::Loop", CodeGenner::ExpressionType::Loop},
    {"ddlbx::parser::Assignment", CodeGenner::ExpressionType::Assignment},
};

CodeGenner::CodeGenner(llvm::LLVMContext& context, llvm::Module& module)
    : context(context), module(module), builder(context) {
    typeMap["Int"] = llvm::Type::getInt32Ty(context);
    typeMap["Flt"] = llvm::Type::getFloatTy(context);
    typeMap["Str"] = llvm::Type::getInt8PtrTy(context);
    typeMap["Boo"] = llvm::Type::getInt1Ty(context);
    // typeMap["Ptr"] = llvm::Type::getInt8PtrTy(context);
    typeMap["Non"] = llvm::Type::getVoidTy(context);
}

void CodeGenner::generate(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Program") return;
    if (node->children.empty()) return;

    for (auto& child : node->children) {
        if (child->type == "ddlbx::parser::Function") {
            std::shared_ptr<FunctionHandler> funcHandler = std::make_shared<FunctionHandler>(child);
            if (funcHandler->getParentTypeName() != "") {
                std::string parentType = funcHandler->getParentTypeName();
                objectMap[parentType].insertMethod(funcHandler);
            } else {
                generateFunctionDeclaration(*funcHandler);
            }
        }
        if (child->type == "ddlbx::parser::ExternalFunction") {
            int idx = 0;
            std::string parentType = "";
            if (child->children[idx]->type == "ddlbx::parser::Type") {
                parentType = child->children[idx++]->string();
            }
            std::string name = (parentType != "" ? parentType + "_" : "") + child->children[idx++]->string();
            const auto& params = child->children[idx++];
            std::string retTypeName = child->children[idx++]->string();

            std::vector<std::string> paramTypeNames;
            if (parentType != "") paramTypeNames.push_back(parentType);
            for (const auto& param : params->children) {
                std::string typeName = param->children[1]->string();
                paramTypeNames.push_back(typeName);
            }

            generateExternalFunctionDeclaration(name, paramTypeNames, retTypeName);
        }
        if (child->type == "ddlbx::parser::Object") {
            ObjectHandler objectHandler(child);
            objectMap[objectHandler.getName()] = objectHandler;
        }
    }
}

llvm::BasicBlock* CodeGenner::generateBlock(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Block") return nullptr;

    llvm::Function* func = funcHandler.getFunction();
    
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);

    for (const auto& child : node->children) {
        generateExpression(child, funcHandler);
    }

    return block;
}

void CodeGenner::generateFunctionDeclaration(FunctionHandler& funcHandler) {
    llvm::Function* func = funcHandler.createFunction(module, typeMap);

    auto& body = funcHandler.getBody();

    generateBlock(body, funcHandler);

    auto lastBlock = builder.GetInsertBlock();
    if (!lastBlock->getTerminator()) {
        if (func->getReturnType()->isVoidTy()) {
            builder.CreateRetVoid();
        }
        else {
            int line = body->begin().line;
            throw std::runtime_error(std::to_string(line) + ": Function must return a value");
        }
    }

    // Verify function
    std::string error;
    llvm::raw_string_ostream errorStream = llvm::raw_string_ostream(error);
    if (llvm::verifyFunction(*func, &errorStream)) {
        throw std::runtime_error(errorStream.str());
    }
}

void CodeGenner::generateExternalFunctionDeclaration(std::string& name, std::vector<std::string>& paramTypeNames, std::string& retTypeName) {
    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    for (const auto& paramTypeName : paramTypeNames)
        paramTypes.push_back(typeMap[paramTypeName]);

    // Get return type
    auto retType = typeMap[retTypeName];

    // Create function type
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    auto func = module.getOrInsertFunction(name, funcType);
}

void CodeGenner::generateExpression(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler &funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Expression") return;

    const auto& child = node->children[0];
    switch (expressionTypeMap[std::string{child->type}]) {
        case ExpressionType::VariableDeclaration:
            generateVariableDeclaration(child, funcHandler);
            break;
        case ExpressionType::Return:
            builder.CreateRet(generateStatement(child->children[0], funcHandler));
            break;
        case ExpressionType::Statement:
            generateStatement(child, funcHandler);
            break;
        case ExpressionType::Conditional:
            generateConditional(child, funcHandler);
            break;
        case ExpressionType::Loop:
            generateLoop(child, funcHandler);
            break;
        case ExpressionType::Assignment:
            generateAssignment(child, funcHandler);
            break;
    }
}

llvm::Value* CodeGenner::generateStatement(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler &funcHandler) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Statement") return nullptr;

    std::stack<llvm::Value*> valueStack;
    std::stack<std::string> opStack;

    for (const auto& child : node->children) {
        if (child->type == "ddlbx::parser::Bracket")
            valueStack.push(generateStatement(child->children[0], funcHandler));
        if (child->type == "ddlbx::parser::Value")
            valueStack.push(generateValue(child));
        if (child->type == "ddlbx::parser::FunctionCall")
            valueStack.push(generateFunctionCall(child, funcHandler));
        if (child->type == "ddlbx::parser::MemberAccess")
            valueStack.push(generateMemberAccess(child, funcHandler));
        if (child->type == "ddlbx::parser::Identifier") {
            std::string name = child->string();
            try {
                auto var = funcHandler.getVariableValue(name);
                if (!var) {
                    auto alloca = funcHandler.getVariableAlloca(name);
                    if (!alloca) throw std::runtime_error(name + " is not defined");
                    var = builder.CreateLoad(alloca->getAllocatedType(), alloca);
                }
                valueStack.push(var);
            } catch (std::exception& e) {
                int line = child->begin().line;
                throw std::runtime_error(std::to_string(line) + ": " + e.what());
            }
        }
        if (child->type == "ddlbx::parser::BinaryOperator" ||
            child->type == "ddlbx::parser::ComparisonOperator" ||
            child->type == "ddlbx::parser::LogicalOperator") {
            std::string comingOp = child->string();
            while (!opStack.empty() && opPropertyMap[opStack.top()] >= opPropertyMap[comingOp]) {
                llvm::Value* rhs = valueStack.top();
                valueStack.pop();
                llvm::Value* lhs = valueStack.top();
                valueStack.pop();
                std::string op = opStack.top();
                opStack.pop();

                try {
                    llvm::Value* result = handleOperation(lhs, rhs, op);
                    valueStack.push(result);
                }
                catch (std::exception& e) {
                    int line = child->begin().line;
                    throw std::runtime_error(std::to_string(line) + ": " + e.what());
                }
            }
            opStack.push(comingOp);
        }
    }

    while (!opStack.empty()) {
        llvm::Value* rhs = valueStack.top();
        valueStack.pop();
        llvm::Value* lhs = valueStack.top();
        valueStack.pop();
        std::string op = opStack.top();
        opStack.pop();

        try {
            llvm::Value* result = handleOperation(lhs, rhs, op);
            valueStack.push(result);
        }
        catch (std::exception& e) {
            int line = node->begin().line;
            throw std::runtime_error(std::to_string(line) + ": " + e.what());
        }
    }

    if (!valueStack.empty()) {
        return valueStack.top();
    }
    return nullptr;
}

llvm::Value* CodeGenner::generateAssignment(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Assignment") return nullptr;

    const auto& lhs = node->children[0];
    const auto& rhs = node->children[1];

    llvm::Value* lhsValue = nullptr;
    if (lhs->type == "ddlbx::parser::Identifier") {
        std::string name = lhs->string();
        lhsValue = funcHandler.getVariableValue(name);
        if (!lhsValue) {
            lhsValue = funcHandler.getVariableAlloca(name);
        }
    }

    llvm::Value* rhsValue = generateStatement(rhs, funcHandler);

    return builder.CreateStore(rhsValue, lhsValue);
}

llvm::Value* CodeGenner::generateMemberAccess(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& function) {
    llvm::Value* parentValue = nullptr;

    for (auto &child : node->children) {
        if (child->type == "ddlbx::parser::Identifier") {
            std::string name = child->string();
            if (!parentValue) {
                parentValue = function.getVariableValue(name);
                if (!parentValue) {
                    llvm::AllocaInst* alloca = function.getVariableAlloca(name);
                    if (!alloca) {
                        int line = child->begin().line;
                        throw std::runtime_error(std::to_string(line) + ": " + name + " is not defined");
                    }
                    parentValue = builder.CreateLoad(alloca->getAllocatedType(), alloca);
                }
            } else {
                llvm::StructType* structType = llvm::cast<llvm::StructType>(parentValue->getType());
                ObjectHandler object = objectMap[structType->getName().str()];
                int memberIndex = object.getMemberIndex(name);
                if (memberIndex == -1) {
                    throw std::runtime_error(name + " is not a member of " + structType->getName().str());
                }
                parentValue = builder.CreateExtractValue(parentValue, memberIndex);
            }
        }
        if (child->type == "ddlbx::parser::FunctionCall") {
            std::string parrntTypeName = "";
            if (parentValue) {
                for (const auto& [typeName, type] : typeMap) {
                    if (type == parentValue->getType()) {
                        parrntTypeName = typeName;
                        break;
                    }
                }
            }
            std::string name = parrntTypeName == "" ? 
                child->children[0]->string() : 
                parrntTypeName + "_" + child->children[0]->string();
            std::vector<llvm::Value*> argValues;
            for (size_t i = 1; i < child->children.size(); i++) {
                const auto& value = child->children[i];
                llvm::Value* val = generateStatement(value, function);
                argValues.push_back(val);
            }

            if (parentValue != nullptr) {
                argValues.push_back(parentValue);
            }
            llvm::Function* targetFunction = module.getFunction(name);
            if (!targetFunction) {
                int line = child->begin().line;
                throw std::runtime_error(std::to_string(line) + ": " + name + " is not defined");
            }

            if (targetFunction->arg_size() != argValues.size()) {
                int line = child->begin().line;
                throw std::runtime_error(std::to_string(line) + ": " + name + " parameter size is not matching");
            }
            parentValue = builder.CreateCall(targetFunction, argValues);
        }
    }

    return parentValue;
}

llvm::Value* CodeGenner::handleOperation(llvm::Value* lhs, llvm::Value* rhs, const std::string& op) {
    llvm::Value* result = nullptr;
    if (op == "==")
        result = builder.CreateICmpEQ(lhs, rhs);
    else if (op == "!=")
        result = builder.CreateICmpNE(lhs, rhs);
    else if (op == "<")
        result = builder.CreateICmpSLT(lhs, rhs);
    else if (op == "<=")
        result = builder.CreateICmpSLE(lhs, rhs);
    else if (op == ">")
        result = builder.CreateICmpSGT(lhs, rhs);
    else if (op == ">=")
        result = builder.CreateICmpSGE(lhs, rhs);
    else if (op == "and")
        result = builder.CreateAnd(lhs, rhs);
    else if (op == "or")
        result = builder.CreateOr(lhs, rhs);
    else if (op == "=")
        result = builder.CreateStore(rhs, lhs); 
    else {
        llvm::Instruction::BinaryOps binaryOp = binaryOpMap[op];
        result = builder.CreateBinOp(binaryOp, lhs, rhs);
    }
    return result;
}

llvm::Value* CodeGenner::generateValue(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Value") return nullptr;

    llvm::IRBuilder<> builder(context);

    llvm::Value* result = nullptr;

    const auto& value = node->children[0];
    if (value->type == "ddlbx::parser::Integer") {
        result = llvm::ConstantInt::get(typeMap["Int"], std::stoi(value->string()));
    }
    else if (value->type == "ddlbx::parser::Float") {
        result = llvm::ConstantFP::get(typeMap["Flt"], std::stof(value->string()));
    }
    else if (value->type == "ddlbx::parser::String") {
        std::string str = value->string();
        str = str.substr(1, str.size() - 2);
        llvm::Constant *strConstant = llvm::ConstantDataArray::getString(context, str);
        llvm::GlobalVariable *strGlobal = new llvm::GlobalVariable(module, strConstant->getType(), true, llvm::GlobalValue::PrivateLinkage, strConstant);
        result = builder.CreatePointerCast(strGlobal, typeMap["Str"]);
    }
    else if (value->type == "ddlbx::parser::Boolean") {
        if (value->string() == "true") {
            result = llvm::ConstantInt::getTrue(context);
        }
        else if (value->string() == "false") {
            result = llvm::ConstantInt::getFalse(context);
        }
        else if (value->string() == "maybe") {
            bool random = rand() % 2;
            result = llvm::ConstantInt::get(context, llvm::APInt(1, random));
        }
    }

    return result;
}

llvm::Value* CodeGenner::generateFunctionCall(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::FunctionCall") return nullptr;

    auto name = node->children[0]->string();
    bool isConstructor = false;
    if (objectMap.find(name) != objectMap.end())
        isConstructor = true;

    std::vector<std::string> templateNames;
    if (node->children.size() > 1 && node->children[1]->type == "ddlbx::parser::Template") {
        for (const auto& templateNode : node->children[1]->children)
            templateNames.push_back(templateNode->string());
    }

    std::vector<llvm::Value*> argValues;
    for (size_t i = templateNames.size() > 0 ? 2 : 1; i < node->children.size(); i++) {
        const auto& value = node->children[i];
        llvm::Value* val = generateStatement(value, funcHandler);
        argValues.push_back(val);
    }

    if (isConstructor) {
        auto currentBlock = builder.GetInsertBlock();

        std::string constructorName = name;
        for (auto templateName : templateNames)
            constructorName += "_" + templateName;
        constructorName += "_factory";

        // check if name is defined
        if (module.getFunction(constructorName) == nullptr) {
            ObjectHandler& objectHandler = objectMap[name];
            std::vector<std::string> templateList = objectHandler.getTemplateList();

            if (templateList.size() != templateNames.size()) {
                int line = node->begin().line;
                throw std::runtime_error(std::to_string(line) + ": " + name + " template size is not matching");
            }

            std::map<std::string, std::string> templateMap;
            for (size_t i = 0; i < templateList.size(); i++) {
                templateMap[templateList[i]] = templateNames[i];
            }

            typeMap[name] = objectHandler.createObject(context, module, typeMap, templateMap);
            std::string realName = name;
            for (const auto& templateName : templateNames) {
                realName += "_" + templateName;
            }
            for (auto& method : objectHandler.getMethodList()) {
                method->insertParam("this", realName);
                generateFunctionDeclaration(*method);
                method->popParam();
            }
        }

        name = constructorName;
    
        builder.SetInsertPoint(currentBlock);
    }

    llvm::Function* targetFunction = module.getFunction(name);
    if (!targetFunction) {
        int line = node->begin().line;
        throw std::runtime_error(std::to_string(line) + ": " + name + " is not defined");
    }

    // check if parameter is matching
    if (targetFunction->arg_size() != argValues.size()) {
        int line = node->begin().line;
        throw std::runtime_error(std::to_string(line) + ": " + name + " parameter size is not matching");
    }

    return builder.CreateCall(targetFunction, argValues);
}

void CodeGenner::generateVariableDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::VariableDeclaration") return;

    const auto& name = node->children[0]->string();
    const auto& value = node->children[1];

    llvm::Value* val = generateStatement(value, funcHandler);

    llvm::AllocaInst* alloca = builder.CreateAlloca(val->getType(), nullptr, name);
    builder.CreateStore(val, alloca);
    funcHandler.insertVariable(name, alloca);
}

void CodeGenner::generateConditional(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Conditional") return;

    const auto& condition = node->children[0];
    const auto& child = node->children[1];

    llvm::Value* cond = generateStatement(condition, funcHandler);
    if (!cond->getType()->isIntegerTy(1)) {
        cond = builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0));
    }

    llvm::Function* func = funcHandler.getFunction();

    llvm::BasicBlock* currentBlock = builder.GetInsertBlock();

    llvm::BasicBlock* thenBlock = nullptr;
    llvm::BasicBlock* elseBlock = llvm::BasicBlock::Create(context, "else", func);
    llvm::BasicBlock* continueBlock = llvm::BasicBlock::Create(context, "continue", func);

    if (child->type == "ddlbx::parser::Block") {
        thenBlock = generateBlock(child, funcHandler);
    }
    else if (child->type == "ddlbx::parser::Expression") {
        thenBlock = llvm::BasicBlock::Create(context, "then", func);
        builder.SetInsertPoint(thenBlock);
        generateExpression(child, funcHandler);
    }

    // check if current block has terminator
    if (!builder.GetInsertBlock()->getTerminator()) {
        builder.CreateBr(continueBlock);
    }

    builder.SetInsertPoint(currentBlock);
    builder.CreateCondBr(cond, thenBlock, elseBlock);

    builder.SetInsertPoint(elseBlock);
    // TODO: support else if
    // builder.CreateRet(llvm::UndefValue::get(function->getReturnType()));

    builder.CreateBr(continueBlock);
    builder.SetInsertPoint(continueBlock);
}

void CodeGenner::generateLoop(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler& funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Loop") return;

    const auto& condition = node->children[0];
    const auto& child = node->children[1];

    llvm::Function* func = funcHandler.getFunction();

    llvm::BasicBlock* currentBlock = builder.GetInsertBlock();
    llvm::BasicBlock* loopBlock = nullptr;
    llvm::BasicBlock* conditionBlock = llvm::BasicBlock::Create(context, "condition", func);
    llvm::BasicBlock* continueBlock = llvm::BasicBlock::Create(context, "continue", func);
    if (condition->type == "ddlbx::parser::LoopRange") {
        std::string idxName = condition->children[0]->string();
        llvm::Value* start = llvm::ConstantInt::get(typeMap["Int"], 0);
        llvm::Value* end = llvm::ConstantInt::get(typeMap["Int"], 0);
        llvm::Value* increment = llvm::ConstantInt::get(typeMap["Int"], 1);

        for (const auto& child : condition->children) {
            if (child->type == "ddlbx::parser::RangeStart")
                start = generateStatement(child->children[0], funcHandler);
            if (child->type == "ddlbx::parser::RangeEnd")
                end = generateStatement(child->children[0], funcHandler);
            if (child->type == "ddlbx::parser::RangeStep")
                increment = generateStatement(child->children[0], funcHandler);
        }

        llvm::AllocaInst* idx = builder.CreateAlloca(typeMap["Int"], nullptr, idxName);
        builder.CreateStore(start, idx);

        if (child->type == "ddlbx::parser::Block")
            loopBlock = generateBlock(child, funcHandler);
        else if (child->type == "ddlbx::parser::Expression") {
            loopBlock = llvm::BasicBlock::Create(context, "loop", funcHandler.getFunction());
            builder.SetInsertPoint(loopBlock);
            generateExpression(child, funcHandler);
        }
        llvm::Value* currentIdx = builder.CreateLoad(typeMap["Int"], idx);
        llvm::Value* nextIdx = builder.CreateAdd(currentIdx, increment);
        builder.CreateStore(nextIdx, idx);
        builder.CreateBr(conditionBlock);

        builder.SetInsertPoint(currentBlock);
        builder.CreateBr(conditionBlock);
        builder.SetInsertPoint(conditionBlock);
        llvm::Value* cond = builder.CreateICmpSLT(builder.CreateLoad(typeMap["Int"], idx), end);
        builder.CreateCondBr(cond, loopBlock, continueBlock);
    }
    if (condition->type == "ddlbx::parser::Statement") {
        builder.CreateBr(conditionBlock);
        builder.SetInsertPoint(conditionBlock);

        llvm::Value* cond = generateStatement(condition, funcHandler);
        if (!cond->getType()->isIntegerTy(1)) {
            cond = builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0));
        }

        loopBlock = generateBlock(child, funcHandler);
        builder.CreateCondBr(cond, loopBlock, continueBlock);

        builder.SetInsertPoint(continueBlock);

        builder.CreateBr(conditionBlock);
    }

    builder.SetInsertPoint(continueBlock);
}

}  // namespace ir
}  // namespace ddlbx
