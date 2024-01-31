#include <gtest/gtest.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>

#include "ir/variable_declaration.hpp"
#include "parser/grammar.hpp"
#include "parser/selector.hpp"

using namespace tao::pegtl;

class VariableDeclarationTest : public ::testing::Test {
protected:
    llvm::LLVMContext context;
    llvm::Module module;
    llvm::IRBuilder<> builder;

    VariableDeclarationTest() : builder(context), module("test", context) {}

    llvm::Value* parse(const std::string& input) {
        memory_input<> in(input, "test");
        const auto root = parse_tree::parse<ddlbx::parser::VariableDeclaration, ddlbx::parser::Selector>(in);
        return ddlbx::ir::VariableDeclaration::create(root->children[0], context, module);
    }
};

TEST_F(VariableDeclarationTest, CreateVariableDeclaration) {
    llvm::Value* result = parse("var x = 42");

    ASSERT_NE(nullptr, result);
    EXPECT_TRUE(result->getType()->isPointerTy());
    EXPECT_TRUE(llvm::isa<llvm::AllocaInst>(result));
    
    auto* store = llvm::dyn_cast<llvm::StoreInst>(result);
    ASSERT_NE(nullptr, store);
    EXPECT_TRUE(store->getType()->isIntegerTy());
    EXPECT_TRUE(llvm::isa<llvm::ConstantInt>(store->getValueOperand()));
    EXPECT_EQ(llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 42), store->getValueOperand());
}
