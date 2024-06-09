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

void printHelp() {
    std::cout << "Usage: ddlbx <file>" << std::endl;
    std::cout << "       ddlbx --help" << std::endl;
    std::cout << "       ddlbx --ll <file>" << std::endl;
    std::cout << "       ddlbx --ast <file>" << std::endl;

    std::cout << "Options:" << std::endl;
    std::cout << "  --help  Print this help message" << std::endl;
    std::cout << "  --ll  Emit LLVM IR code" << std::endl;
    std::cout << "  --ast  Emit AST" << std::endl;
}

int main(int argc, char** argv) {
    std::string fileName = "";
    bool emitLL = false;
    bool emitAST = false;

    if (argc == 2) {
        fileName = argv[1];
    } else if (argc == 3) {
        if (std::string(argv[1]) == "--ll") {
            emitLL = true;
        } else if (std::string(argv[1]) == "--ast") {
            emitAST = true;
        } else {
            printHelp();
            return 1;
        }
        fileName = argv[2];
    } else {
        printHelp();
        return 1;
    }

    std::ifstream file(fileName);
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
    file.close();

    pegtl::string_input<> in(content, "input"); 
    const auto root = pegtl::parse_tree::parse<ddlbx::parser::Program, ddlbx::parser::Selector>(in);
    if (!root) {
        std::cout << "parse error" << std::endl;
        return 0;
    }

    // print parse tree
    if (emitAST) {
        pegtl::parse_tree::print_dot(std::cout, *root);
        return 0;
    }

    llvm::LLVMContext context;
    llvm::Module module(fileName, context);
    ddlbx::ir::CodeGenner codeGenner(context, module);
    codeGenner.generate(root->children[0]);

    // optimize module
    llvm::legacy::PassManager passManager;
    passManager.add(llvm::createPromoteMemoryToRegisterPass());
    passManager.add(llvm::createInstructionCombiningPass());
    passManager.add(llvm::createReassociatePass());
    passManager.add(llvm::createGVNPass());
    passManager.add(llvm::createCFGSimplificationPass());
    passManager.run(module);

    // print module
    if (emitLL) {
        module.print(llvm::errs(), nullptr);
        return 0;
    }

    // generate object file
    ddlbx::pass::ObjectGenner objectGenner;
    objectGenner.generate(codeGenner.getModule());
}
