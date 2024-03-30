#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(Grammar, Operator) {
    std::string sample1 = "+";
    std::string sample2 = "-";
    std::string sample3 = "*";
    std::string sample4 = "/";
    std::string sample5 = "%";
    std::string sample6 = "==";
    std::string sample7 = "!=";
    std::string sample8 = "<";
    std::string sample9 = ">";
    std::string sample10 = "<=";
    std::string sample11 = ">=";
    std::string sample12 = "&&";
    std::string sample13 = "||";
    std::string sample14 = "!";

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

    EXPECT_TRUE(parse<BinaryOperator>(in1));
    EXPECT_TRUE(parse<BinaryOperator>(in2));
    EXPECT_TRUE(parse<BinaryOperator>(in3));
    EXPECT_TRUE(parse<BinaryOperator>(in4));
    EXPECT_TRUE(parse<BinaryOperator>(in5));
    EXPECT_TRUE(parse<ComparisonOperator>(in6));
    EXPECT_TRUE(parse<ComparisonOperator>(in7));
    EXPECT_TRUE(parse<ComparisonOperator>(in8));
    EXPECT_TRUE(parse<ComparisonOperator>(in9));
    EXPECT_TRUE(parse<ComparisonOperator>(in10));
    EXPECT_TRUE(parse<ComparisonOperator>(in11));
    EXPECT_TRUE(parse<ComparisonOperator>(in12));
    EXPECT_TRUE(parse<ComparisonOperator>(in13));
    EXPECT_TRUE(parse<UnaryOperator>(in14));
}