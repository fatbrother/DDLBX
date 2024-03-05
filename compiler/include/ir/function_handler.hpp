#pragma once

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <map>
#include <vector>
#include <memory>
#include <string>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

namespace pegtl = tao::pegtl;

namespace ddlbx{
namespace ir{

class FunctionHandler{
public:

    FunctionHandler()
        : function(nullptr) {}

    /**
     * @brief Create a new LLVM Function.
     * 
     * @param funcType The type of the function.
    */
    void createFunction(llvm::FunctionType* funcType, std::string name, llvm::Module &module){
        function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, &module);
    }
    /**
     * @brief Get the LLVM Function.
     * 
     * @return llvm::Function& The LLVM Function.
     */
    llvm::Function *getFunction() { return function; }
private:
    llvm::Function *function;

    std::map<std::string, int> intVarible;
    std::map<std::string, float> floatVarible;
    std::map<std::string, std::string> stringVarible;
    std::map<std::string, bool> boolVarible;

};
}
}