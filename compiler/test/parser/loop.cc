#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(Grammar, Loop) {
    std::string sample1 = "for (i to 10) { print(i)! }";
    std::string sample2 = "for (i to 10) print(i)!";
    std::string sample3 = "for (i from 0 to 10) { print(i)! }";
    std::string sample4 = "for (i from 0 to 10 step 2) { print(i)! }";
    std::string sample5 = "for (a < 10) print(a)!";
    std::string sample6 = R"(for (i to 10) {
    print(i)!
}
)";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");

    EXPECT_TRUE(parse<Loop>(in1));
    EXPECT_TRUE(parse<Loop>(in2));
    EXPECT_TRUE(parse<Loop>(in3));
    EXPECT_TRUE(parse<Loop>(in4));
    EXPECT_TRUE(parse<Loop>(in5));
    EXPECT_TRUE(parse<Loop>(in6));
}