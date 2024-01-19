#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::grammer;

TEST(grammer, boolean) {
    std::string sample1 = "true";
    std::string sample2 = "false";
    std::string sample3 = "maybe";
    std::string sample4 = "";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");

    EXPECT_TRUE(parse<Boolean>(in1));
    EXPECT_TRUE(parse<Boolean>(in2));
    EXPECT_TRUE(parse<Boolean>(in3));
    EXPECT_FALSE(parse<Boolean>(in4));
}