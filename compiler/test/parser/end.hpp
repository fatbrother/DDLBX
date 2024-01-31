#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(grammer, end) {
    std::string sample1 = "!";
    std::string sample2 = "123";
    std::string sample3 = "";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");

    EXPECT_TRUE(parse<End>(in1));
    EXPECT_FALSE(parse<End>(in2));
    EXPECT_FALSE(parse<End>(in3));
}