#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

using namespace tao::pegtl;
using namespace ddlbx::parser;

TEST(Grammar, Conditional) {
    std::string sample1 = "opt (a == 1) { print(1)! }";
    std::string sample2 = "opt (a == 1) print(1)!";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");

    EXPECT_TRUE(parse<Conditional>(in1));
    EXPECT_TRUE(parse<Conditional>(in2));
}