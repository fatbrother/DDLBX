#pragma once

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace ir {

class Block {
public:
    Block() = delete;

    /**
     * @brief Construct a new Block object
     *
     * @param root
     * @param context
     * @param module
     * @param Parent
     *
     * @details
     * The root node must be of type ddlbx::parser::Block.
     */
    static llvm::BasicBlock* create(const std::unique_ptr<pegtl::parse_tree::node>&, llvm::LLVMContext&, llvm::Module&, llvm::Function*);
};

}  // namespace ir
}  // namespace ddlbx