#pragma once

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include "grammer.hpp"
#include "selector.hpp"

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace ir {

} // namespace ir
} // namespace ddlbx