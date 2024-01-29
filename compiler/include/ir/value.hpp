#pragma once

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace ir {

class Value {
public:
    Value() = delete;

    /**
     * @brief Construct a new Value object
     *
     * @param root
     * @param context
     *
     * @details
     * The root node must be of type ddlbx::parser::Value.
     */
    static llvm::Value* create(const std::unique_ptr<pegtl::parse_tree::node>&, llvm::LLVMContext&);
};

}  // namespace ir
}  // namespace ddlbx