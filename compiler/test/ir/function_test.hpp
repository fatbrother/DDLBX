#include <gtest/gtest.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <memory>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include "ir/function.hpp"
#include "parser/grammer.hpp"
#include "parser/selector.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

// Parameterized test fixture
class FunctionTest : public ::testing::TestWithParam<std::tuple<std::string, std::string, int, std::function<llvm::Type*(llvm::LLVMContext&)>, llvm::Function::LinkageTypes>> {
protected:
    FunctionTest() = default;
    ~FunctionTest() override = default;

    void SetUp() override {}
    void TearDown() override {}
};

// Parameterized test case
TEST_P(FunctionTest, ParseAndCreateFunction) {
    llvm::LLVMContext context;
    llvm::Module module("test", context);

    const auto& [input, name, numArgs, getReturnType, linkage] = GetParam();
    const auto returnType = getReturnType(context);
    memory_input<> in(input, "test");
    const auto root = parse_tree::parse<ddlbx::parser::Function, ddlbx::parser::Selector>(in);

    ASSERT_NE(nullptr, root);
    ASSERT_NE(0, root->children.size());

    auto result = ddlbx::ir::Function::create(root->children[0], context, module);

    EXPECT_NE(nullptr, result);
    EXPECT_EQ(name, result->getName().str());
    EXPECT_EQ(numArgs, result->arg_size());
    EXPECT_EQ(returnType->getTypeID(), result->getReturnType()->getTypeID());
    EXPECT_EQ(linkage, result->getLinkage());

    result->eraseFromParent();
}

// Parameterized test cases
INSTANTIATE_TEST_SUITE_P(Functions, FunctionTest,
    ::testing::Values(
        std::make_tuple("fun main(): Int { ret 0! }", "main", 0, llvm::Type::getInt32Ty, llvm::Function::ExternalLinkage),
        std::make_tuple("fun main(a: Int): Int { ret 0! }", "main", 1, llvm::Type::getInt32Ty, llvm::Function::ExternalLinkage),
        std::make_tuple("fun main(a: Int, b: Int): Non { ret 0! }", "main", 2, llvm::Type::getVoidTy, llvm::Function::ExternalLinkage)
    )
);