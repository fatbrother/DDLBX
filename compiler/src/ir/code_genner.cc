#include "ir/code_genner.hpp"

#include <llvm/IR/Verifier.h>

#include <iostream>
#include <stack>

namespace ddlbx {
namespace ir {

std::map<std::string, std::function<llvm::Type*(llvm::LLVMContext&)>> CodeGenner::typeMap = {
    {"Int", [](llvm::LLVMContext& context) { return llvm::Type::getInt32Ty(context); }},
    {"Flo", [](llvm::LLVMContext& context) { return llvm::Type::getFloatTy(context); }},
    {"Str", [](llvm::LLVMContext& context) { return llvm::Type::getInt8PtrTy(context)->getPointerTo(); }},
    {"Boo", [](llvm::LLVMContext& context) { return llvm::Type::getInt1Ty(context); }},
    {"Non", [](llvm::LLVMContext& context) { return llvm::Type::getVoidTy(context); }},
};

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
    {"ddlbx::parser::FunctionCall", CodeGenner::ExpressionType::FunctionCall},
    {"ddlbx::parser::Return", CodeGenner::ExpressionType::Return},
    {"ddlbx::parser::Statement", CodeGenner::ExpressionType::Statement},
    {"ddlbx::parser::Conditional", CodeGenner::ExpressionType::Conditional},
    {"ddlbx::parser::Loop", CodeGenner::ExpressionType::Loop},
};

void CodeGenner::generate(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Program") return;
    if (node->children.empty()) return;

    for (const auto& child : node->children) {
        if (child->type == "ddlbx::parser::Function") {
            generateFunctionDeclaration(child);
        }
        if (child->type == "ddlbx::parser::ExternalFunction") {
            generateExternalFunctionDeclaration(child);
        }
        if (child->type == "ddlbx::parser::Object") {
            generateObjectDeclaration(child);
        }
    }
}

llvm::BasicBlock* CodeGenner::generateBlock(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler* funcHandler = nullptr) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Block") return nullptr;
    
    llvm::Function* func = nullptr;    //for new class
    if(funcHandler)
        func = funcHandler->getFunction();    //for new class
    
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);

    for (const auto& child : node->children) {
        generateExpression(child, funcHandler);        //for new class
    }

    return block;
}   //Updated

void CodeGenner::generateFunctionDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Function") return;

    int idx = 0;
    std::string parentType = "";
    if (node->children[idx]->type == "ddlbx::parser::Type") {
        parentType = node->children[idx++]->string();
    }
    const auto name = (parentType != "" ? parentType + "_" : "") + node->children[idx++]->string();
    const auto& params = node->children[idx++];
    const auto& ret = node->children[idx++];
    const auto& body = node->children[idx++];
    int param_count = params->children.size();

    llvm::Type* structType = nullptr;
    if (parentType != "") {
        structType = typeMap[parentType](context);
    }

    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    if (structType) {
        paramTypes.push_back(structType->getPointerTo());
        param_count++;
    }
    for (const auto& param : params->children) {
        std::string type = param->children[1]->string();
        paramTypes.push_back(typeMap[type](context));
    }

    // Get return type
    auto retType = typeMap[ret->string()](context);

    // Create function type
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    FunctionHandler* funcHandler = new FunctionHandler();      //for new class
    llvm::Function* func = funcHandler->createFunction(funcType, name, module);     //for new class
    //llvm::Function* func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);

    // Set parameter names
    for (int i = 0; i < param_count; i++) {
        if (i == 0 && structType) {
            func->getArg(i)->setName("this");
            continue;
        }
        func->getArg(i)->setName(params->children[i]->children[0]->string());
    }

    // Generate function body
    generateBlock(body, funcHandler);      //for new class

    // Check if last block has terminator
    llvm::BasicBlock* lastBlock = builder.GetInsertBlock();
    if (!lastBlock->getTerminator() && retType->isVoidTy()) {
        builder.CreateRetVoid();
    }

    // Verify function
    // std::string error;
    // llvm::raw_string_ostream errorStream = llvm::raw_string_ostream(error);
    // if (llvm::verifyFunction(*func, &errorStream)) {
    //     int line = node->begin().line;
    //     throw std::runtime_error(std::to_string(line) + ": " + errorStream.str());
    // }
}   //Updated

void CodeGenner::generateExternalFunctionDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::ExternalFunction") return;

    auto name = node->children[0]->string();
    const auto& params = node->children[1];
    const auto& ret = node->children[2];
    int param_count = params->children.size();

    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    for (const auto& param : params->children) {
        std::string type = param->children[1]->string();
        paramTypes.push_back(typeMap[type](context));
    }

    // Get return type
    auto retType = typeMap[ret->string()](context);

    // Create function type
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);

    try {
        auto func = module.getOrInsertFunction(name, funcType);
        functionMap[name] = func;
    }
    catch (std::runtime_error& e) {
        int line = node->begin().line;
        throw std::runtime_error(std::to_string(line) + ": " + e.what());
    }
}

void CodeGenner::generateExpression(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler* funcHandler = nullptr) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Expression") return;

    const auto& child = node->children[0];
    switch (expressionTypeMap[std::string{child->type}]) {
        case ExpressionType::VariableDeclaration:
            generateVariableDeclaration(child, funcHandler);
            break;
        case ExpressionType::FunctionCall:
            generateFunctionCall(child, funcHandler);
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
    }
}   //UPDATED

llvm::Value* CodeGenner::generateStatement(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler* funcHandler = nullptr) {
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
        if (child->type == "ddlbx::parser::Identifier") {
            std::string name = child->string();
            llvm::Function* func = (funcHandler)? funcHandler->getFunction(): nullptr;
            llvm::Value* var = nullptr;

            if (func) {
                for (auto& arg : func->args()) {
                    if (arg.getName() == name) {
                        var = &arg;
                        break;
                    }
                }
            }
            if (!var && variableMap.find(name) != variableMap.end()) {
                llvm::AllocaInst* alloca = variableMap[name];
                llvm::Type* type = alloca->getAllocatedType();
                var = builder.CreateLoad(type, alloca);
                // check if variable is struct ptr
                if (var->getType()->isPointerTy()) {
                    // TODO: support struct ptr
                    throw std::runtime_error("struct ptr is not supported yet");
                }
            }
            if (!var) {
                int line = child->begin().line;
                throw std::runtime_error(std::to_string(line) + ": " + name + " is not defined");
            }

            valueStack.push(var);
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
}   //Updated variableMap used here

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
        result = llvm::ConstantInt::get(typeMap["Int"](context), std::stoi(value->string()));
    }
    else if (value->type == "ddlbx::parser::Float") {
        result = llvm::ConstantFP::get(typeMap["Flo"](context), std::stof(value->string()));
    }
    else if (value->type == "ddlbx::parser::String") {
        result = builder.CreateGlobalString(value->string());
    }
    else if (value->type == "ddlbx::parser::Boolean") {
        if (value->string() == "true") {
            result = llvm::ConstantInt::getTrue(context);
        }
        else if (value->string() == "false") {
            result = llvm::ConstantInt::getFalse(context);
        }
        else if (value->string() == "maybe") {
            result = llvm::UndefValue::get(typeMap["Boo"](context));
        }
    }

    return result;
}

llvm::Value* CodeGenner::generateFunctionCall(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler* funcHandler = nullptr) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::FunctionCall") return nullptr;

    auto name = node->children[0]->string();

    bool isConstructor = false;
    if (typeMap.find(name) != typeMap.end())
        isConstructor = true;

    std::vector<llvm::Value*> argValues;
    for (size_t i = 1; i < node->children.size(); i++) {
        const auto& value = node->children[i];
        llvm::Value* val = generateStatement(value, funcHandler);
        argValues.push_back(val);
    }

    if (isConstructor)
        name += "_factory";
    llvm::Function* targetFunction = module.getFunction(name);

    // check if parameter is matching
    if (targetFunction->arg_size() != argValues.size()) {
        int line = node->begin().line;
        throw std::runtime_error(std::to_string(line) + ": " + name + " parameter size is not matching");
    }

    return builder.CreateCall(targetFunction, argValues);
}   //UPDATED

void CodeGenner::generateVariableDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler* funcHandler = nullptr) {
    if (!node) return;
    if (node->type != "ddlbx::parser::VariableDeclaration") return;

    const auto& name = node->children[0]->string();
    const auto& value = node->children[1];

    llvm::Value* val = generateStatement(value, funcHandler);

    llvm::AllocaInst* alloca = builder.CreateAlloca(val->getType(), nullptr, name);
    builder.CreateStore(val, alloca);
    variableMap[name] = alloca;
}   //UPDATED variableMap used here

void CodeGenner::generateObjectDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Object") return;

    std::string name = node->children[0]->string();
    const auto& members = node->children[1];

    llvm::StructType* structType = llvm::StructType::create(context, name);
    std::vector<llvm::Type*> memberTypes;
    for (const auto& member : members->children) {
        std::string type = member->children[1]->string();
        memberTypes.push_back(typeMap[type](context));
    }
    structType->setBody(memberTypes);

    module.getOrInsertGlobal(name, structType);
    typeMap[name] = [structType](llvm::LLVMContext& context) { return structType; };

    // create constructor
    llvm::FunctionType* funcType = llvm::FunctionType::get(structType, memberTypes, false);
    llvm::Function* func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name + "_factory", &module);
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);
    llvm::Value* thisPtr = builder.CreateAlloca(structType, nullptr, "this");
    int i = 0;
    for (auto& arg : func->args()) {
        llvm::Value* ptr = builder.CreateStructGEP(structType, thisPtr, i++);
        builder.CreateStore(&arg, ptr);
    }
    llvm::Value* ret = builder.CreateLoad(structType, thisPtr);
    builder.CreateRet(ret);
}

void CodeGenner::generateConditional(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler* funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Conditional") return;

    const auto& condition = node->children[0];
    const auto& child = node->children[1];

    llvm::Value* cond = generateStatement(condition, funcHandler);
    if (!cond->getType()->isIntegerTy(1)) {
        cond = builder.CreateICmpNE(cond, llvm::ConstantInt::get(cond->getType(), 0));
    }

    llvm::Function* func = funcHandler->getFunction();

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
    builder.CreateBr(continueBlock);

    builder.SetInsertPoint(currentBlock);
    builder.CreateCondBr(cond, thenBlock, elseBlock);

    builder.SetInsertPoint(elseBlock);
    // TODO: support else if
    // builder.CreateRet(llvm::UndefValue::get(function->getReturnType()));

    builder.CreateBr(continueBlock);
    builder.SetInsertPoint(continueBlock);
}   //UPDATED

void CodeGenner::generateLoop(const std::unique_ptr<pegtl::parse_tree::node>& node, FunctionHandler* funcHandler) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Loop") return;

    const auto& condition = node->children[0];
    const auto& child = node->children[1];

    llvm::Function* func = funcHandler->getFunction();

    llvm::BasicBlock* currentBlock = builder.GetInsertBlock();
    llvm::BasicBlock* loopBlock = nullptr;
    llvm::BasicBlock* conditionBlock = llvm::BasicBlock::Create(context, "condition", func);
    llvm::BasicBlock* continueBlock = llvm::BasicBlock::Create(context, "continue", func);
    if (condition->type == "ddlbx::parser::LoopRange") {
        std::string idxName = condition->children[0]->string();
        llvm::Value* start = llvm::ConstantInt::get(typeMap["Int"](context), 0);
        llvm::Value* end = llvm::ConstantInt::get(typeMap["Int"](context), 0);
        llvm::Value* increment = llvm::ConstantInt::get(typeMap["Int"](context), 1);

        for (const auto& child : condition->children) {
            if (child->type == "ddlbx::parser::RangeStart")
                start = generateStatement(child->children[0], funcHandler);
            if (child->type == "ddlbx::parser::RangeEnd")
                end = generateStatement(child->children[0], funcHandler);
            if (child->type == "ddlbx::parser::RangeStep")
                increment = generateStatement(child->children[0], funcHandler);
        }

        llvm::AllocaInst* idx = builder.CreateAlloca(typeMap["Int"](context), nullptr, idxName);
        builder.CreateStore(start, idx);
        variableMap[idxName] = idx;

        loopBlock = generateBlock(child, funcHandler);
        builder.SetInsertPoint(loopBlock);
        llvm::Value* currentIdx = builder.CreateLoad(typeMap["Int"](context), idx);
        llvm::Value* nextIdx = builder.CreateAdd(currentIdx, increment);
        builder.CreateStore(nextIdx, idx);
        builder.CreateBr(conditionBlock);

        builder.SetInsertPoint(currentBlock);
        builder.CreateBr(conditionBlock);
        builder.SetInsertPoint(conditionBlock);
        llvm::Value* cond = builder.CreateICmpSLT(builder.CreateLoad(typeMap["Int"](context), idx), end);
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
}   //UPDATED

}  // namespace ir
}  // namespace ddlbx
