#include <tao/pegtl.hpp>
#include <llvm/IR/LLVMContext.h>
#include <iostream>

void showHelp() {
    std::cout << "Usage: ddlbx -o <output> <input>" << std::endl;
}

int main() {
    tao::pegtl::string_input<> in("Hello, World!", "input");
    llvm::LLVMContext context;
    return 0;
}