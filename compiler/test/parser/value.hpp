#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::grammer;

TEST(grammer, value) {
    std::string sample1 = "0";
    std::string sample2 = "-10";
    std::string sample3 = "10.123";
    std::string sample4 = "-10.123";
    std::string sample5 = "10.";
    std::string sample6 = "-10.";
    std::string sample7 = "-.123";
    std::string sample8 = "";
    std::string sample9 = "true";
    std::string sample10 = "false";
    std::string sample11 = "maybe";
    std::string sample12 = "'hello'";
    std::string sample13 = "'hello world'";
    std::string sample14 = "'hello world!'";
    std::string sample15 = "'he??o'";
    std::string sample16 = "'he\\'o'";
    std::string sample17 = "hello";

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

    EXPECT_TRUE(parse<Value>(in1));
    EXPECT_TRUE(parse<Value>(in2));
    EXPECT_TRUE(parse<Value>(in3));
    EXPECT_TRUE(parse<Value>(in4));
    EXPECT_TRUE(parse<Value>(in5));
    EXPECT_TRUE(parse<Value>(in6));
    EXPECT_FALSE(parse<Value>(in7));
    EXPECT_FALSE(parse<Value>(in8));
    EXPECT_TRUE(parse<Value>(in9));
    EXPECT_TRUE(parse<Value>(in10));
    EXPECT_TRUE(parse<Value>(in11));
    EXPECT_TRUE(parse<Value>(in12));
    EXPECT_TRUE(parse<Value>(in13));
    EXPECT_TRUE(parse<Value>(in14));
    EXPECT_TRUE(parse<Value>(in15));
    EXPECT_TRUE(parse<Value>(in16));
    EXPECT_FALSE(parse<Value>(in17));
}