#include <fstream>
#include <iostream>
#include <string>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include "ir/code_genner.hpp"
#include "parser/grammar.hpp"
#include "parser/selector.hpp"
#include "pass/object_genner.hpp"

namespace pegtl = tao::pegtl;

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ddlbx <file>" << std::endl;
        return 1;
    }

    std::string fileNmae(argv[1]);
    std::ifstream file(fileNmae, std::ios::in);
    if (!file) {
        std::cout << "file not found" << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    pegtl::string_input<> in(content, "input");
    const auto root = pegtl::parse_tree::parse<ddlbx::parser::Program, ddlbx::parser::Selector>(in);
    if (!root) {
        std::cout << "parse error" << std::endl;
        return 0;
    }

    llvm::LLVMContext context;
    llvm::Module module(fileNmae, context);
    ddlbx::ir::CodeGenner codeGenner(context, module);
    codeGenner.generate(root->children[0]);

    // print module
    codeGenner.getModule().print(llvm::errs(), nullptr);

    // // generate object file
    // ddlbx::pass::ObjectGenner objectGenner;
    // objectGenner.generate(codeGenner.getModule());
}
