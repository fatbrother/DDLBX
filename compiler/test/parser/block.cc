#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(Grammar, Block) {
    std::string sample1 = R"(
{
    var a = 1!
    var b = 'hello' !
    1 + 2!
}
    )";

    std::string sample2 = R"({
var a = 1!
}
    )";

    std::string sample3 = "{ 1 + 2! }";
    std::string sample4 = "{1 + 2!}";
    std::string sample5 = "{}";
    std::string sample6 = "{1 + 2!";
    std::string sample7 = "1 + 2! }";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");

    EXPECT_TRUE(parse<Block>(in1));
    EXPECT_TRUE(parse<Block>(in2));
    EXPECT_TRUE(parse<Block>(in3));
    EXPECT_TRUE(parse<Block>(in4));
    EXPECT_TRUE(parse<Block>(in5));
    EXPECT_FALSE(parse<Block>(in6));
    EXPECT_FALSE(parse<Block>(in7));
}