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

class FunctionTest : public ::testing::Test {
protected:
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;
    llvm::Module module;

public:
    FunctionTest() : context(), builder(context), module("test", context) {}

    void SetUp() override {}

    llvm::Function* parse(const std::string& input) {
        memory_input<> in(input, "test");
        const auto root = parse_tree::parse<Function, Selector>(in);
        return ddlbx::ir::Function::create(root->children[0], context, module);
    }
};

TEST_F(FunctionTest, CreateEmptyParameterFunction) {
    auto result = parse("fun main(): Int { ret 0! }");

    EXPECT_NE(nullptr, result);
    EXPECT_EQ("main", result->getName().str());
    EXPECT_EQ(0, result->arg_size());
    EXPECT_EQ(llvm::Type::getInt32Ty(context), result->getReturnType());
    EXPECT_EQ(llvm::Function::ExternalLinkage, result->getLinkage());
}

TEST_F(FunctionTest, CreateSingleParameterFunction) {
    auto result = parse("fun main(a: Int): Int { ret 0! }");

    EXPECT_NE(nullptr, result);
    EXPECT_EQ("main", result->getName().str());
    EXPECT_EQ(1, result->arg_size());
    EXPECT_EQ(llvm::Type::getInt32Ty(context), result->getReturnType());
    EXPECT_EQ(llvm::Function::ExternalLinkage, result->getLinkage());
}

TEST_F(FunctionTest, CreateMultipleParameterFunction) {
    auto result = parse("fun main(a: Int, b: Int): Non { ret 0! }");

    EXPECT_NE(nullptr, result);
    EXPECT_EQ("main", result->getName().str());
    EXPECT_EQ(2, result->arg_size());
    EXPECT_EQ(llvm::Type::getVoidTy(context), result->getReturnType());
    EXPECT_EQ(llvm::Function::ExternalLinkage, result->getLinkage());
}