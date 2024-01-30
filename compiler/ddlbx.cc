#include <iostream>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include "ir/code_genner.hpp"
#include "parser/grammar.hpp"
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
    ddlbx::ir::CodeGenner codeGenner(context, module);
    codeGenner.generate(root->children[0]);

    // print module
    codeGenner.getModule().print(llvm::errs(), nullptr);
}
