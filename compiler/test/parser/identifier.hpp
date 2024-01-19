#include <gtest/gtest.h>

#include <tao/pegtl.hpp>

#include "grammer.hpp"

using namespace tao::pegtl;
using namespace ddlbx::grammer;

TEST (grammer, Identifier) {
    std::string sample1 = "hello";
    std::string sample2 = "123";
    std::string sample3 = "hello123";
    std::string sample4 = "123hello";
    std::string sample5 = "hello_world";
    std::string sample6 = "_hello";
    std::string sample7 = "hello_";
    std::string sample8 = "_";
    std::string sample9 = "";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");
    string_input<> in8(sample8, "input");
    string_input<> in9(sample9, "input");

    EXPECT_TRUE(parse<Identifier>(in1));
    EXPECT_TRUE(parse<Identifier>(in2));
    EXPECT_TRUE(parse<Identifier>(in3));
    EXPECT_TRUE(parse<Identifier>(in4));
    EXPECT_TRUE(parse<Identifier>(in5));
    EXPECT_TRUE(parse<Identifier>(in6));
    EXPECT_TRUE(parse<Identifier>(in7));
    EXPECT_TRUE(parse<Identifier>(in8));
    EXPECT_FALSE(parse<Identifier>(in9));
}