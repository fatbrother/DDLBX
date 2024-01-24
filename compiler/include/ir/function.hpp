#pragma once

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>

#include "parser/grammer.hpp"
#include "parser/selector.hpp"

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace ir {

class Function {
public:
    /**
     * @brief Construct a new Function object
     *
     * @param root
     * @param context
     * @param module
     */
    Function(const std::unique_ptr<pegtl::parse_tree::node>&, llvm::LLVMContext&, llvm::Module&);

    /**
     * @brief Get the LLVM function
     *
     * @return llvm::Function*
     */
    llvm::Function* get() const;

    /**
     * @brief Get the LLVM function name
     *
     * @return std::string
     */
    std::string getName() const;

private:
    llvm::LLVMContext& context;
    llvm::Module& module;
    llvm::IRBuilder<> builder;

    std::string name;
    std::vector<llvm::Type*> paramTypes;
    llvm::Type* retType;
    llvm::Function* func;
};

}  // namespace ir
}  // namespace ddlbx