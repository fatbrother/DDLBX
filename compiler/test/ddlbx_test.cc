#include <gtest/gtest.h>

#include "grammerCP.hpp"

using namespace tao::pegtl;

TEST(grammerCP, basic)
{
    std::string sample1 = "-10.123!";
    std::string sample2 = "\'abcd\n\'";           //string內不能有單引號 註:\n,\t...等特殊符號需加入規則
    std::string sample3 = "true";
    std::string sample4 = "[ 123, 134, 1234 ]"; //list測試--
    std::string sample5 = "[]";
    std::string sample6 = "[ 'abc' , '123' , '456' ]"; 
    std::string sample7 = "[ 12.45 , '123' , '456' , [ 'abc' , '123' , '456' ] ]";  //list測試-- 
    std::string sample8 = "Int";
    std::string sample9 = "List< Int>";
    std::string sample10 = "List<List< Str >  >";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");
    string_input<> in4(sample4, "input");
    string_input<> in5(sample5, "input");
    string_input<> in6(sample6, "input");
    string_input<> in7(sample7, "input");
    string_input<> in8(sample8, "input");
    string_input<> in9(sample9, "input");

    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::Number>(in1));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::String>(in2));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::Boolean>(in3));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::List>(in4));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::List>(in5));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::List>(in6));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::List>(in7));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::Type>(in8));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::Type>(in9));
}

TEST(grammerCP, Expression)
{
    std::string sample1 = "1+2";
    std::string sample2 = "1+2*3";
    std::string sample3 = "a=b+c";

    string_input<> in1(sample1, "input");
    string_input<> in2(sample2, "input");
    string_input<> in3(sample3, "input");

    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::Expression>(in1));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::Expression>(in2));
    EXPECT_TRUE(pegtl::parse<ddlbx::grammer::Expression>(in3));
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}