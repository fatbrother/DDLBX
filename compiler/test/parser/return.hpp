#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::grammer;

TEST(grammer, ret) {
    std::string input1 = "ret 123";
    std::string input2 = "ret 1 + 2";
    std::string input3 = "ret 1 + 2 + 3";
    std::string input4 = "ret";

    string_input<> in1(input1, "input");
    string_input<> in2(input2, "input");
    string_input<> in3(input3, "input");
    string_input<> in4(input4, "input");

    EXPECT_TRUE(parse<Return>(in1));
    EXPECT_TRUE(parse<Return>(in2));
    EXPECT_TRUE(parse<Return>(in3));
    EXPECT_FALSE(parse<Return>(in4));
}