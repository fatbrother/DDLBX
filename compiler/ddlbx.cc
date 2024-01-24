#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <iostream>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>

#include "ir/function.hpp"
#include "parser/grammer.hpp"
#include "parser/selector.hpp"

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

int main(int argc, char** argv) {
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
        if (func->type == "ddlbx::parser::Function") {
            ddlbx::ir::Function funcIR(func, context, module);
            std::cout << funcIR.getName() << std::endl;

            llvm::Function* llvmFunc = funcIR.get();
            llvmFunc->print(llvm::outs());
        }
    }
    return 0;
}
