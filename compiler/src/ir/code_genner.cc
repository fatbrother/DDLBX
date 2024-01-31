#include "ir/code_genner.hpp"

#include <stack>

namespace ddlbx {
namespace ir {

std::map<std::string, std::function<llvm::Type*(llvm::LLVMContext&)>> CodeGenner::typeMap = {
    {"Int", [](llvm::LLVMContext& context) { return llvm::Type::getInt32Ty(context); }},
    {"Flo", [](llvm::LLVMContext& context) { return llvm::Type::getFloatTy(context); }},
    {"Str", [](llvm::LLVMContext& context) { return llvm::Type::getInt8PtrTy(context); }},
    {"Boo", [](llvm::LLVMContext& context) { return llvm::Type::getInt1Ty(context); }},
    {"Non", [](llvm::LLVMContext& context) { return llvm::Type::getVoidTy(context); }},
};

std::map<std::string, int> CodeGenner::opPropertyMap = {
    {"+", 1},
    {"-", 1},
    {"*", 2},
    {"/", 2},
    {"%", 2},
};

std::map<std::string, llvm::Instruction::BinaryOps> CodeGenner::opMap = {
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
};

void CodeGenner::generate(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Block" && node->type != "ddlbx::parser::Program") return;
    if (node->children.empty()) return;

    if (node->type == "ddlbx::parser::Block")
        generateBlock();

    for (const auto& child : node->children) {
        if (child->type == "ddlbx::parser::Function") {
            generateFunctionDeclaration(child);
        }
        if (child->type == "ddlbx::parser::Expression") {
            generateExpression(child);
        }
    }
}

void CodeGenner::generateBlock() {
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entry", parentFunction);
    builder.SetInsertPoint(block);
}

void CodeGenner::generateFunctionDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Function") return;

    const auto name = node->children[0]->string();
    const auto& params = node->children[1];
    const auto& ret = node->children[2];
    const auto& body = node->children[3];
    int param_count = params->children.size();

    // Get parameter types
    std::vector<llvm::Type*> paramTypes;
    for (const auto& param : params->children) {
        std::string type = param->children[1]->string();
        paramTypes.push_back(typeMap[type](context));
    }

    // Get return type
    auto retType = typeMap[ret->string()](context);

    // Create function
    llvm::FunctionType* funcType = llvm::FunctionType::get(retType, paramTypes, false);
    auto func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, module);

    // Set parameter names
    for (int i = 0; i < param_count; i++) {
        func->getArg(i)->setName(params->children[i]->children[0]->string());
    }

    CodeGenner codeGenner(context, module, func);
    codeGenner.generate(body);
}

void CodeGenner::generateExpression(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::Expression") return;

    const auto& child = node->children[0];
    switch (expressionTypeMap[std::string{child->type}]) {
        case ExpressionType::VariableDeclaration:
            generateVariableDeclaration(child);
            break;
        case ExpressionType::FunctionCall:
            generateFunctionCall(child);
            break;
        case ExpressionType::Return:
            builder.CreateRet(generateStatement(child->children[0]));
            break;
        case ExpressionType::Statement:
            generateStatement(child);
            break;
    }
}

llvm::Value* CodeGenner::generateStatement(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::Statement") return nullptr;

    std::stack<llvm::Value*> valueStack;
    std::stack<std::string> opStack;

    for (const auto& child : node->children) {
        if (child->type == "ddlbx::parser::Bracket")
            valueStack.push(generateStatement(child->children[0]));
        if (child->type == "ddlbx::parser::Value")
            valueStack.push(generateValue(child));
        if (child->type == "ddlbx::parser::FunctionCall")
            valueStack.push(generateFunctionCall(child));
        if (child->type == "ddlbx::parser::Identifier") {
            std::string name = child->string();
            llvm::Value* var = nullptr;
            if (parentFunction) {
                for (auto& arg : parentFunction->args()) {
                    if (arg.getName() == name) {
                        var = &arg;
                        break;
                    }
                }
            }
            if (!var && variableMap.find(name) != variableMap.end()) {
                llvm::AllocaInst * alloca = variableMap[name];
                llvm::Type* type = alloca->getAllocatedType();
                var = builder.CreateLoad(type, alloca);
            }
            if (var) {
                valueStack.push(var);
            }
        }
        if (child->type == "ddlbx::parser::Operator") {
            std::string op = child->string();
            if (opStack.empty()) {
                opStack.push(op);
                continue;
            }
            while (!opStack.empty() && opPropertyMap[opStack.top()] >= opPropertyMap[op]) {
                llvm::Value* rhs = valueStack.top();
                valueStack.pop();
                llvm::Value* lhs = valueStack.top();
                valueStack.pop();
                llvm::Instruction::BinaryOps op = opMap[opStack.top()];
                opStack.pop();
                valueStack.push(builder.CreateBinOp(op, lhs, rhs));
            }
            opStack.push(op);
        }
    }

    while (!opStack.empty()) {
        llvm::Value* rhs = valueStack.top();
        valueStack.pop();
        llvm::Value* lhs = valueStack.top();
        valueStack.pop();
        llvm::Instruction::BinaryOps op = opMap[opStack.top()];
        opStack.pop();
        valueStack.push(builder.CreateBinOp(op, lhs, rhs));
    }

    if (!valueStack.empty())
        return valueStack.top();
    return nullptr;
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
        std::string str = value->string().substr(1, value->string().size() - 2);  // remove quotes
        result = llvm::ConstantDataArray::getString(context, str);
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

llvm::Value* CodeGenner::generateFunctionCall(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return nullptr;
    if (node->type != "ddlbx::parser::FunctionCall") return nullptr;

    const auto& name = node->children[0]->string();

    std::vector<llvm::Value*> argValues;
    for (size_t i = 1; i < node->children.size(); i++) {
        const auto& value = node->children[i];
        llvm::Value* val = generateStatement(value);
        argValues.push_back(val);
    }

    llvm::Function* function = module.getFunction(name);
    return builder.CreateCall(function, argValues);
}

void CodeGenner::generateVariableDeclaration(const std::unique_ptr<pegtl::parse_tree::node>& node) {
    if (!node) return;
    if (node->type != "ddlbx::parser::VariableDeclaration") return;

    const auto& name = node->children[0]->string();
    const auto& value = node->children[1];

    llvm::Value* val = generateStatement(value);
    
    llvm::AllocaInst* alloca = builder.CreateAlloca(val->getType(), nullptr, name);
    builder.CreateStore(val, alloca);
    variableMap[name] = alloca;
}

}  // namespace ir
}  // namespace ddlbx