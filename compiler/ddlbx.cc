#include <llvm/IR/LLVMContext.h>
#include <iostream>

void showHelp() {
    std::cout << "Usage: ddlbx -o <output> <input>" << std::endl;
}

int main() {
    llvm::LLVMContext context;

    return 0;
}