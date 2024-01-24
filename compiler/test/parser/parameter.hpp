#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(grammer, parameter) {
    std::string sample1 = "a: Int";
    std::string sample2 = "b: Flo";
    std::string sample3 = "c:Str";
    std::string sample4 = "d  : Boo";
    std::string sample5 = "e:";

    std::string sample6 = "a: Int, b: Int";
    std::string sample7 = "a: Int, b: Int,";
    std::string sample8 = "a: Int, b: Int, c: Int";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");
    string_input<> in8(sample8, "input");

    EXPECT_TRUE(parse<Parameter>(in1));
    EXPECT_TRUE(parse<Parameter>(in2));
    EXPECT_TRUE(parse<Parameter>(in3));
    EXPECT_TRUE(parse<Parameter>(in4));
    EXPECT_FALSE(parse<Parameter>(in5));

    EXPECT_FALSE(parse<MultiParameter>(in1));
    EXPECT_TRUE(parse<MultiParameter>(in6));
    EXPECT_TRUE(parse<MultiParameter>(in7));
    EXPECT_TRUE(parse<MultiParameter>(in8));
}