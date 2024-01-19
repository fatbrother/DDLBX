#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::grammer;

TEST(grammer, type) {
    std::string sample1 = "Int";
    std::string sample2 = "Flo";
    std::string sample3 = "Str";
    std::string sample4 = "Boo";
    std::string sample5 = "Non";
    std::string sample6 = "";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");

    EXPECT_TRUE(parse<Type>(in1));
    EXPECT_TRUE(parse<Type>(in2));
    EXPECT_TRUE(parse<Type>(in3));
    EXPECT_TRUE(parse<Type>(in4));
    EXPECT_TRUE(parse<Type>(in5));
    EXPECT_FALSE(parse<Type>(in6));
}