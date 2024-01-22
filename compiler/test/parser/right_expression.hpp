#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::grammer;

TEST(grammer, right_expression) {
    std::string sample1 = "= 1";
    std::string sample2 = " = 1";
    std::string sample3 = " =1";
    std::string sample4 = "=1";
    std::string sample5 = "=1 = 1";
    std::string sample6 = "=1 =1";
    std::string sample7 = "=1= 1";
    std::string sample8 = "=1=1";
    std::string sample9 = "1";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");
    string_input<> in8(sample8, "input");
    string_input<> in9(sample9, "input");

    EXPECT_TRUE(parse<RightExpression>(in1));
    EXPECT_TRUE(parse<RightExpression>(in2));
    EXPECT_TRUE(parse<RightExpression>(in3));
    EXPECT_TRUE(parse<RightExpression>(in4));
    EXPECT_TRUE(parse<RightExpression>(in5));
    EXPECT_TRUE(parse<RightExpression>(in6));
    EXPECT_TRUE(parse<RightExpression>(in7));
    EXPECT_TRUE(parse<RightExpression>(in8));
    EXPECT_FALSE(parse<RightExpression>(in9));
}