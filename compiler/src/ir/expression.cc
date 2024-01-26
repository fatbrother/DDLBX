#include "ir/expression.hpp"

#include "ir/type.hpp"

namespace ddlbx {
namespace ir {

enum class Expression::ExpressionType {
    VariableDeclaration,
    FunctionCall,
    Return,
    Expression,
};

std::map<std::string, Expression::ExpressionType> Expression::expressionTypeMap = {
    {"ddlbx::parser::VariableDeclaration", Expression::ExpressionType::VariableDeclaration},
    {"ddlbx::parser::FunctionCall", Expression::ExpressionType::FunctionCall},
    {"ddlbx::parser::Return", Expression::ExpressionType::Return},
    {"ddlbx::parser::Expression", Expression::ExpressionType::Expression},
};

llvm::Value* Expression::create(const std::unique_ptr<pegtl::parse_tree::node>& root, llvm::LLVMContext& context, llvm::Module& module) {
    assert(root->type == "ddlbx::parser::Expression");

    llvm::IRBuilder<> builder(context);

    switch (expressionTypeMap[std::string{root->children[0]->type}]) {
        case ExpressionType::VariableDeclaration: {
            const auto& name = root->children[0]->children[1]->string();
            const auto& value = root->children[0]->children[2];
            const auto& type = root->children[0]->children[2]->string();

            // Create variable
            llvm::Type* varType = Type::get(type, context);
            llvm::AllocaInst* var = builder.CreateAlloca(varType, nullptr, name);

            // Create value
            // llvm::Value* val = Expression::create(value, context, module);

            // Store value
            // builder.CreateStore(val, var);
            break;
        }
        case ExpressionType::FunctionCall: {
            const auto& name = root->children[0]->children[0]->string();
            const auto& args = root->children[0]->children[1];

            // Get function
            llvm::Function* func = module.getFunction(name);

            // Create arguments
            std::vector<llvm::Value*> funcArgs;
            for (const auto& arg : args->children) {
                // funcArgs.push_back(Expression::create(arg, context, module));
            }

            // Create call
            builder.CreateCall(func, funcArgs);
            break;
        }
        case ExpressionType::Return: {
            const auto& value = root->children[0]->children[0];

            // Create value
            // llvm::Value* val = Expression::create(value, context, module);

            // Create return instruction
            // builder.CreateRet(val);
            break;
        }
        case ExpressionType::Expression: {
            const auto& value = root->children[0];

            // Create value
            // llvm::Value* val = Expression::create(value, context, module);
            break;
        }
    }
}

}  // namespace ir
}  // namespace ddlbx