#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(Grammar, Statement) {
    std::string sample1 = "1 = 1";
    std::string sample2 = "1 =1";
    std::string sample3 = "1= 1";
    std::string sample4 = "1=1";
    std::string sample5 = "1 = 1 = 1";
    std::string sample6 = "a + b = 1";
    std::string sample7 = "a";
    std::string sample8 = "";
    std::string sample9 = "foo()";
    std::string sample10 = "(1 + 2) * 3";
    std::string sample11 = "(1 + 2) * (3 + 4)";
    std::string sample12 = "((1 + 2) * (3 + 4))";
    std::string sample13 = "print(\"Hello, World!\")";
    std::string sample14 = "a.b";
    std::string sample15 = "a.b + a.b";
    std::string sample16 = "a() + a()";
    std::string sample17 = "(a * sin(b) + cos(c) * tan(d) - sqrt(e))";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");
    string_input<> in8(sample8, "input");
    string_input<> in9(sample9, "input");
    string_input<> in10(sample10, "input");
    string_input<> in11(sample11, "input");
    string_input<> in12(sample12, "input");
    string_input<> in13(sample13, "input");
    string_input<> in14(sample14, "input");
    string_input<> in15(sample15, "input");
    string_input<> in16(sample16, "input");
    string_input<> in17(sample17, "input");

    EXPECT_TRUE(parse<Statement>(in1));
    EXPECT_TRUE(parse<Statement>(in2));
    EXPECT_TRUE(parse<Statement>(in3));
    EXPECT_TRUE(parse<Statement>(in4));
    EXPECT_TRUE(parse<Statement>(in5));
    EXPECT_TRUE(parse<Statement>(in6));
    EXPECT_TRUE(parse<Statement>(in7));
    EXPECT_FALSE(parse<Statement>(in8));
    EXPECT_TRUE(parse<Statement>(in9));
    EXPECT_TRUE(parse<Statement>(in10));
    EXPECT_TRUE(parse<Statement>(in11));
    EXPECT_TRUE(parse<Statement>(in12));
    EXPECT_TRUE(parse<Statement>(in13));
    EXPECT_TRUE(parse<Statement>(in14));
    EXPECT_TRUE(parse<Statement>(in15));
    EXPECT_TRUE(parse<Statement>(in16));
    EXPECT_TRUE(parse<Statement>(in17));
}