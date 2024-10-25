#include <fstream>
#include <iostream>
#include <string>

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Transforms/Utils.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>

#include "ir/node.hpp"
#include "ir/code_gen_context.hpp"
#include "pass/object_genner.hpp"
#include "parser/parse_file.hpp"

#include <iostream>
#include <memory>

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

    llvm::LLVMContext context;
    llvm::Module module("main", context);
    ddlbx::ir::CodeGenContext codeGenContext(context, module);

    if (false == ddlbx::parser::parseFile(fileName)) {
        LOG_ERROR("Failed to parse file: " + fileName);
        return 1;
    }

    if (1 > programs.size() || nullptr == programs.back()) {
        LOG_ERROR("Failed to parse file: " + fileName);
        return 1;
    }

    programs.back()->codeGen(codeGenContext);

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
    objectGenner.generate(module);
}
