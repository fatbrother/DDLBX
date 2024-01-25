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
    Function() = delete;

    /**
     * @brief Construct a new Function object
     *
     * @param root
     * @param context
     * @param module
     *
     * @details
     * The root node must be of type ddlbx::parser::Function.
     */
    static void create(const std::unique_ptr<pegtl::parse_tree::node>&, llvm::LLVMContext&, llvm::Module&);
};

}  // namespace ir
}  // namespace ddlbx