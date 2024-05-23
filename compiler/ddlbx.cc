#include <fstream>
#include <iostream>
#include <string>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Transforms/Utils.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>

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

    // for every line in the file, find "//" and remove the rest of the line
    std::string content;
    for (std::string line; std::getline(file, line);) {
        auto pos = line.find("//");
        if (pos != std::string::npos) {
            line = line.substr(0, pos);
        }
        content += line + "\n";
    }

    pegtl::string_input<> in(content, "input"); 
    const auto root = pegtl::parse_tree::parse<ddlbx::parser::Program, ddlbx::parser::Selector>(in);
    if (!root) {
        std::cout << "parse error" << std::endl;
        return 0;
    }

    // print parse tree
    // pegtl::parse_tree::print_dot(std::cout, *root);

    llvm::LLVMContext context;
    llvm::Module module(fileNmae, context);
    ddlbx::ir::CodeGenner codeGenner(context, module);
    codeGenner.generate(root->children[0]);

    // optimize module
    // llvm::legacy::PassManager passManager;
    // passManager.add(llvm::createPromoteMemoryToRegisterPass());
    // passManager.add(llvm::createInstructionCombiningPass());
    // passManager.add(llvm::createReassociatePass());
    // passManager.add(llvm::createGVNPass());
    // passManager.add(llvm::createCFGSimplificationPass());
    // passManager.run(module);

    // print module
    codeGenner.getModule().print(llvm::errs(), nullptr);

    // generate object file
    ddlbx::pass::ObjectGenner objectGenner;
    objectGenner.generate(codeGenner.getModule());
}
