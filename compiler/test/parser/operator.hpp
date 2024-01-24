#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(grammer, operator) {
    std::string sample1 = "+";
    std::string sample2 = "-";
    std::string sample3 = "*";
    std::string sample4 = "/";
    std::string sample5 = "%";
    std::string sample6 = "^";
    std::string sample7 = "~";
    std::string sample8 = "&";
    std::string sample9 = "|";
    std::string sample10 = "=";
    std::string sample11 = "<";
    std::string sample12 = ">";
    std::string sample13 = "<=";
    std::string sample14 = ">=";
    std::string sample15 = "==";
    std::string sample16 = "not";
    std::string sample17 = "and";
    std::string sample18 = "or";
    std::string sample19 = "";

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
    string_input<> in18(sample18, "input");
    string_input<> in19(sample19, "input");

    EXPECT_TRUE(parse<Operator>(in1));
    EXPECT_TRUE(parse<Operator>(in2));
    EXPECT_TRUE(parse<Operator>(in3));
    EXPECT_TRUE(parse<Operator>(in4));
    EXPECT_TRUE(parse<Operator>(in5));
    EXPECT_TRUE(parse<Operator>(in6));
    EXPECT_TRUE(parse<Operator>(in7));
    EXPECT_TRUE(parse<Operator>(in8));
    EXPECT_TRUE(parse<Operator>(in9));
    EXPECT_TRUE(parse<Operator>(in10));
    EXPECT_TRUE(parse<Operator>(in11));
    EXPECT_TRUE(parse<Operator>(in12));
    EXPECT_TRUE(parse<Operator>(in13));
    EXPECT_TRUE(parse<Operator>(in14));
    EXPECT_TRUE(parse<Operator>(in15));
    EXPECT_TRUE(parse<Operator>(in16));
    EXPECT_TRUE(parse<Operator>(in17));
    EXPECT_TRUE(parse<Operator>(in18));
    EXPECT_FALSE(parse<Operator>(in19));
}