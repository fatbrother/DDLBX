#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(grammer, function) {
    std::string sample1 = R"(fun add(a: Int): Int { a + 1! })";

    std::string sample2 = R"(fun add(a: Int, b: Int): Int {
    a + b!
}
    )";

    std::string sample3 = "fun add(): Int {}";
    std::string sample4 = "fun add() {}";
    std::string sample5 = "fun add()";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");

    EXPECT_TRUE(parse<Function>(in1));
    EXPECT_TRUE(parse<Function>(in2));
    EXPECT_TRUE(parse<Function>(in3));
    EXPECT_FALSE(parse<Function>(in4));
    EXPECT_FALSE(parse<Function>(in5));
}
