#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::grammer;

TEST(grammer, number) {
    std::string sample1 = "0";
    std::string sample2 = "-10";
    std::string sample3 = "10.123";
    std::string sample4 = "-10.123";
    std::string sample5 = "10.";
    std::string sample6 = "-10.";
    std::string sample7 = "-.123";
    std::string sample8 = "";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");
    string_input<> in8(sample8, "input");

    EXPECT_TRUE(parse<Number>(in1));
    EXPECT_TRUE(parse<Number>(in2));
    EXPECT_TRUE(parse<Number>(in3));
    EXPECT_TRUE(parse<Number>(in4));
    EXPECT_TRUE(parse<Number>(in5));
    EXPECT_TRUE(parse<Number>(in6));
    EXPECT_FALSE(parse<Number>(in7));
    EXPECT_FALSE(parse<Number>(in8));
}