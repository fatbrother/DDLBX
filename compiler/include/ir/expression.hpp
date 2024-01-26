#pragma once

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include <map>
#include <string>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace ir {

class Expression {
public:
    Expression() = delete;

    /**
     * @brief Construct a new Expression object
     *
     * @param root
     * @param context
     * @param module
     *
     * @details
     * The root node must be of type ddlbx::parser::Expression.
     */
    static llvm::Value* create(const std::unique_ptr<pegtl::parse_tree::node>&, llvm::LLVMContext&, llvm::Module&);

private:
    enum class ExpressionType;
    static std::map<std::string, ExpressionType> expressionTypeMap;
};

}  // namespace ir
}  // namespace ddlbx