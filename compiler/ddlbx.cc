#include <iostream>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include "grammer.hpp"
#include "selector.hpp"

std::string test = R"(
fun main(): Non {
    var a = 1!
    var b = 2!
    a + b!
}

fun add(a: Int, b: Int): Int {
    ret a + b!
}
)";

namespace pegtl = tao::pegtl;
int main(int argc, char **argv) {
    pegtl::string_input<> in(test, "input");
    const auto root = pegtl::parse_tree::parse<ddlbx::parser::Program, ddlbx::parser::Selector>(in);
    if (!root) {
        std::cout << "parse error" << std::endl;
        return 0;
    }

    llvm::LLVMContext context;
    llvm::Module module("test", context);

    const auto& program = root->children[0];
    for (const auto& func : program->children) {
        if (func->children.size() > 3) {
            std::string name = func->children[0]->string();
            const auto& params = func->children[1];
            const auto& ret = func->children[2];
            const auto& body = func->children[3];

            int param_count = params->children.size();
            
            std::cout << "func name: " << name << std::endl;
            std::cout << "params: " << param_count << std::endl;
            std::cout << "ret: " << ret->string() << std::endl;

            std::vector<llvm::Type*> param_types;
            for (const auto& param : params->children) {
                std::string type = param->children[1]->string();
                if (type == "Int") {
                    param_types.push_back(llvm::Type::getInt32Ty(context));
                } else if (type == "Flo") {
                    param_types.push_back(llvm::Type::getFloatTy(context));
                } else if (type == "Str") {
                    param_types.push_back(llvm::Type::getInt8PtrTy(context));
                } else if (type == "Boo") {
                    param_types.push_back(llvm::Type::getInt1Ty(context));
                } else {
                    std::cout << "unknown type: " << type << std::endl;
                    return 0;
                }
            }

            llvm::FunctionType *func_type = llvm::FunctionType::get(
                llvm::Type::getInt32Ty(context),
                param_types,
                false
            );

            llvm::Function *llvm_func = llvm::Function::Create(
                func_type,
                llvm::Function::ExternalLinkage,
                name,
                &module
            );

            int i = 0;
            for (auto& arg : llvm_func->args()) {
                arg.setName(params->children[i]->children[0]->string());
                i++;
            }

            llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entry", llvm_func);
            llvm::IRBuilder<> builder(entry);
            
            for (const auto& stmt : body->children) {
                if (stmt->string().substr(0, 3) == "ret") {
                    pegtl::parse_tree::print_dot(std::cout, *stmt);
                    const auto& expr = stmt->children[0];
                    std::string lhs = expr->children[0]->string();
                    std::string op = expr->children[1]->string();
                    std::string rhs = expr->children[2]->string();

                    llvm::Value *lhs_value = nullptr;
                    llvm::Value *rhs_value = nullptr;
                    if (lhs == "a") {
                        lhs_value = llvm_func->args().begin();
                    } else if (lhs == "b") {
                        lhs_value = llvm_func->args().begin() + 1;
                    } else {
                        std::cout << "unknown lhs: " << lhs << std::endl;
                        return 0;
                    }

                    if (rhs == "a") {
                        rhs_value = llvm_func->args().begin();
                    } else if (rhs == "b") {
                        rhs_value = llvm_func->args().begin() + 1;
                    } else {
                        std::cout << "unknown rhs: " << rhs << std::endl;
                        return 0;
                    }
   
                    if (op == "+") {
                        llvm::Value *add = builder.CreateAdd(lhs_value, rhs_value);
                        builder.CreateRet(add);
                    } else {
                        std::cout << "unknown op: " << op << std::endl;
                        return 0;
                    }
                }
            }
            // output
            module.print(llvm::outs(), nullptr);
        }


    }
    return 0;
}
