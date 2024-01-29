#include <gtest/gtest.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include "ir/value.hpp"
#include "parser/grammer.hpp"

using namespace tao::pegtl;

class ValueTest : public ::testing::Test {
protected:
    llvm::LLVMContext context;
    llvm::IRBuilder<> builder;

public:
    ValueTest() : context(), builder(context) {}

    void SetUp() override {}

    llvm::Value* parse(const std::string& input) {
        memory_input<> in(input, "test");
        const auto root = parse_tree::parse<ddlbx::parser::Value>(in);
        return ddlbx::ir::Value::create(root->children[0], context);
    }
};

TEST_F(ValueTest, CreateIntegerValue) {
    llvm::Value* result = parse("42");

    ASSERT_NE(nullptr, result);
    EXPECT_TRUE(result->getType()->isIntegerTy());
    EXPECT_EQ(llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), 42), result);
}

TEST_F(ValueTest, CreateFloatValue) {
    llvm::Value* result = parse("3.14");

    ASSERT_NE(nullptr, result);
    EXPECT_TRUE(result->getType()->isFloatTy());
    EXPECT_EQ(llvm::ConstantFP::get(llvm::Type::getFloatTy(context), 3.14), result);
}

TEST_F(ValueTest, CreateStringValue) {
    llvm::Value* result = parse("'hello'");

    ASSERT_NE(nullptr, result);

    auto* constant = llvm::dyn_cast<llvm::ConstantDataArray>(result);
    ASSERT_NE(nullptr, constant);
    EXPECT_EQ("hello", constant->getAsString().str().substr(0, 5));  // remove null terminator
}

TEST_F(ValueTest, CreateBooleanValue) {
    llvm::Value* result1 = parse("true");
    llvm::Value* result2 = parse("false");
    llvm::Value* result3 = parse("maybe");

    ASSERT_NE(nullptr, result1);
    ASSERT_NE(nullptr, result2);
    ASSERT_NE(nullptr, result3);
    EXPECT_TRUE(result1->getType()->isIntegerTy(1));
    EXPECT_TRUE(result2->getType()->isIntegerTy(1));
    EXPECT_TRUE(result3->getType()->isIntegerTy(1));
    EXPECT_EQ(llvm::ConstantInt::getTrue(context), result1);
    EXPECT_EQ(llvm::ConstantInt::getFalse(context), result2);
    EXPECT_EQ(llvm::UndefValue::get(llvm::Type::getInt1Ty(context)), result3);
}
