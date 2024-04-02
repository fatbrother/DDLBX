#include "ir/code_genner.hpp"

#include <gtest/gtest.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/parse_tree.hpp>

#include "parser/grammar.hpp"
#include "parser/selector.hpp"

using namespace ddlbx::ir;
using namespace tao::pegtl;

class CodeGennerTest : public ::testing::Test {
protected:
    llvm::LLVMContext context;
    llvm::Module module;
    CodeGenner codeGenner;

    CodeGennerTest() : module("test", context), codeGenner(context, module) {}

    void SetUp() override {}

    // Helper function to generate LLVM IR code from a block
    void generate(const std::string& input) {
        memory_input<> in(input, "test");
        const auto root = parse_tree::parse<ddlbx::parser::Program, ddlbx::parser::Selector>(in);
        codeGenner.generate(root->children[0]);
    }
};

TEST_F(CodeGennerTest, GenerateSimpleReturn) {
    const std::string input = "fun test1(): Int { ret 0! }";
    generate(input);

    // Assuming the test function is declared in the module
    llvm::Function* testFunction = module.getFunction("test1");

    ASSERT_NE(nullptr, testFunction);
    EXPECT_EQ("test1", testFunction->getName().str());

    llvm::BasicBlock* entryBlock = &testFunction->getEntryBlock();
    ASSERT_NE(nullptr, entryBlock);
    EXPECT_EQ(1, entryBlock->size());

    // Assuming the first instruction is a return instruction
    llvm::ReturnInst* retInst = llvm::dyn_cast<llvm::ReturnInst>(&entryBlock->front());
    ASSERT_NE(nullptr, retInst);
    EXPECT_EQ(llvm::Value::ConstantIntVal, retInst->getReturnValue()->getValueID());
    EXPECT_EQ(0, llvm::cast<llvm::ConstantInt>(retInst->getReturnValue())->getSExtValue());
}

TEST_F(CodeGennerTest, GenerateSimpleFunctionCall) {
    const std::string input = R"(
        fun foo(): Int { ret 0! }
        fun test2(): Non { foo()! }
    )";
    generate(input);

    // Assuming the test function is declared in the module
    llvm::Function* testFunction = module.getFunction("test2");

    ASSERT_NE(nullptr, testFunction);
    EXPECT_EQ("test2", testFunction->getName().str());

    llvm::BasicBlock* entryBlock = &testFunction->getEntryBlock();
    ASSERT_NE(nullptr, entryBlock);
    EXPECT_EQ(2, entryBlock->size()); // Auto added return instruction

    // Assuming the first instruction is a call instruction
    llvm::CallInst* callInst = llvm::dyn_cast<llvm::CallInst>(&entryBlock->front());
    ASSERT_NE(nullptr, callInst);
    EXPECT_EQ("foo", callInst->getCalledFunction()->getName().str());
}

TEST_F(CodeGennerTest, GenerateSimpleVariableDeclaration) {
    const std::string input = R"(
        fun test3(): Non {
            var x = 0!
        }
    )";
    generate(input);

    // Assuming the test function is declared in the module
    llvm::Function* testFunction = module.getFunction("test3");

    ASSERT_NE(nullptr, testFunction);
    EXPECT_EQ("test3", testFunction->getName().str());

    llvm::BasicBlock* entryBlock = &testFunction->getEntryBlock();
    ASSERT_NE(nullptr, entryBlock);
    EXPECT_EQ(3, entryBlock->size()); // Including alloca instruction, store instruction and return instruction

    // Assuming the first instruction is an alloca instruction
    llvm::AllocaInst* allocaInst = llvm::dyn_cast<llvm::AllocaInst>(&entryBlock->front());
    ASSERT_NE(nullptr, allocaInst);
    EXPECT_EQ("x", allocaInst->getName().str());
}

TEST_F(CodeGennerTest, GenerateSimpleStatement) {
    const std::string input = R"(
        fun test4(): Int {
            ret 1 * 2 + 3!
        }
    )";
    generate(input);

    // Assuming the test function is declared in the module
    llvm::Function* testFunction = module.getFunction("test4");

    ASSERT_NE(nullptr, testFunction);
    EXPECT_EQ("test4", testFunction->getName().str());

    // Assuming the test function has a single basic block
    llvm::BasicBlock* entryBlock = &testFunction->getEntryBlock();
    ASSERT_NE(nullptr, entryBlock);
    EXPECT_EQ(1, entryBlock->size());

    // Assuming the first instruction is a return instruction
    llvm::ReturnInst* retInst = llvm::dyn_cast<llvm::ReturnInst>(&entryBlock->front());
    ASSERT_NE(nullptr, retInst);

    // Assuming the return value is 5
    EXPECT_EQ(5, llvm::cast<llvm::ConstantInt>(retInst->getReturnValue())->getSExtValue());
}

TEST_F(CodeGennerTest, GenerateBracketStatement) {
    const std::string input = R"(
        fun test5(): Int {
            ret (1 + 2) * 2!
        }
    )";
    generate(input);

    // Assuming the test function is declared in the module
    llvm::Function* testFunction = module.getFunction("test5");

    ASSERT_NE(nullptr, testFunction);
    EXPECT_EQ("test5", testFunction->getName().str());

    // Assuming the test function has a single basic block
    llvm::BasicBlock* entryBlock = &testFunction->getEntryBlock();
    ASSERT_NE(nullptr, entryBlock);
    EXPECT_EQ(1, entryBlock->size());

    // Assuming the first instruction is a return instruction
    llvm::ReturnInst* retInst = llvm::dyn_cast<llvm::ReturnInst>(&entryBlock->front());
    ASSERT_NE(nullptr, retInst);

    // Assuming the return value is 6
    EXPECT_EQ(6, llvm::cast<llvm::ConstantInt>(retInst->getReturnValue())->getSExtValue());
}

TEST_F(CodeGennerTest, OperatorPriority) {
    const std::string input = R"(
        fun test6(): Boo {
            ret 1 == 1 and 3 == 4!
        }
    )";
    generate(input);

    // Assuming the test function is declared in the module
    llvm::Function* testFunction = module.getFunction("test6");

    ASSERT_NE(nullptr, testFunction);
    EXPECT_EQ("test6", testFunction->getName().str());

    // Assuming the test function has a single basic block
    llvm::BasicBlock* entryBlock = &testFunction->getEntryBlock();
    ASSERT_NE(nullptr, entryBlock);
    EXPECT_EQ(1, entryBlock->size());

    // Assuming the first instruction is a return instruction
    llvm::ReturnInst* retInst = llvm::dyn_cast<llvm::ReturnInst>(&entryBlock->front());
    ASSERT_NE(nullptr, retInst);

    // Assuming the return value is false
    EXPECT_EQ(0, llvm::cast<llvm::ConstantInt>(retInst->getReturnValue())->getSExtValue());
}

TEST_F(CodeGennerTest, GenerateConditional) {
    const std::string input = R"(
        fun test7(): Int {
            opt (1) ret 1!

            ret 0!
        }
    )";
    generate(input);

    // Assuming the test function is declared in the module
    llvm::Function* testFunction = module.getFunction("test7");

    ASSERT_NE(nullptr, testFunction);
    EXPECT_EQ("test7", testFunction->getName().str());

    // Assuming the test function has a single basic block
    llvm::BasicBlock* entryBlock = &testFunction->getEntryBlock();
    ASSERT_NE(nullptr, entryBlock);
    EXPECT_EQ(1, entryBlock->size());

    // Assuming the fist instruction is a branch instruction
    llvm::BranchInst* branchInst = llvm::dyn_cast<llvm::BranchInst>(&entryBlock->front());
    ASSERT_NE(nullptr, branchInst);

    // Assuming the first successor is the then block
    llvm::BasicBlock* thenBlock = branchInst->getSuccessor(0);
    ASSERT_NE(nullptr, thenBlock);
    EXPECT_EQ(2, thenBlock->size());

    // Assuming the first instruction in the then block is a return instruction
    llvm::ReturnInst* retInst = llvm::dyn_cast<llvm::ReturnInst>(&thenBlock->front());
    ASSERT_NE(nullptr, retInst);
    EXPECT_EQ(1, llvm::cast<llvm::ConstantInt>(retInst->getReturnValue())->getSExtValue());

    // Assuming the second successor is the else block
    llvm::BasicBlock* elseBlock = branchInst->getSuccessor(1);
    ASSERT_NE(nullptr, elseBlock);
    EXPECT_EQ(1, elseBlock->size());
}

TEST_F(CodeGennerTest, GenerateLoop) {
    const std::string input = R"(
        fun test8(): Non {
            for (i to 10) { 1 + 1! }
        }
    )";
    generate(input);

    // Assuming the test function is declared in the module
    llvm::Function* testFunction = module.getFunction("test8");

    ASSERT_NE(nullptr, testFunction);
    EXPECT_EQ("test8", testFunction->getName().str());

    // Assuming the test function has a single basic block
    llvm::BasicBlock* entryBlock = &testFunction->getEntryBlock();
    ASSERT_NE(nullptr, entryBlock);
    EXPECT_EQ(3, entryBlock->size());

    // Assuming the last instruction is a branch instruction
    llvm::BranchInst* branchInst = llvm::dyn_cast<llvm::BranchInst>(&entryBlock->back());
    ASSERT_NE(nullptr, branchInst);

    // Assuming the first successor is the loop block
    llvm::BasicBlock* loopBlock = branchInst->getSuccessor(0);
    ASSERT_NE(nullptr, loopBlock);
    EXPECT_EQ(3, loopBlock->size());
}

TEST_F(CodeGennerTest, GenerateObject) {
    const std::string input = R"(
        obj Test {
            a: Int
        }
    )";
    generate(input);

    // Assuming the test function is declared in the module
    auto testTypeList = module.getIdentifiedStructTypes();
    ASSERT_EQ(1, testTypeList.size());
    auto testType = testTypeList[0];
    EXPECT_EQ("Test", testType->getName().str());
    ASSERT_EQ(1, testType->getNumElements());
    auto aType = testType->getElementType(0);
    EXPECT_TRUE(aType->isIntegerTy());
    EXPECT_EQ(32, aType->getIntegerBitWidth());

    // check if factory function is generated
    llvm::Function* factoryFunction = module.getFunction("Test_factory");
    ASSERT_NE(nullptr, factoryFunction);
    EXPECT_EQ("Test_factory", factoryFunction->getName().str());
    EXPECT_EQ(1, factoryFunction->arg_size());
}

TEST_F(CodeGennerTest, GenerateObjectWithMethod) {
    const std::string input = R"(
        obj Test {}

        fun Test.test(): Int { ret 1! }
    )";
    generate(input);

    // Assuming the test function is declared in the module
    llvm::Function* testFunction = module.getFunction("Test_test");

    ASSERT_NE(nullptr, testFunction);
    EXPECT_EQ("Test_test", testFunction->getName().str());

    // Assuming the test function has a parameter "this"
    ASSERT_EQ(1, testFunction->arg_size());
    auto arg = testFunction->arg_begin();
    EXPECT_EQ("this", arg->getName().str());
}