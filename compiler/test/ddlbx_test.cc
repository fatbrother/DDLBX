#include <gtest/gtest.h>

#include "./parser/block.hpp"
#include "./parser/boolean.hpp"
#include "./parser/declaration.hpp"
#include "./parser/end.hpp"
#include "./parser/expression.hpp"
#include "./parser/function.hpp"
#include "./parser/identifier.hpp"
#include "./parser/number.hpp"
#include "./parser/operator.hpp"
#include "./parser/parameter.hpp"
#include "./parser/right_expression.hpp"
#include "./parser/statement.hpp"
#include "./parser/string.hpp"
#include "./parser/type.hpp"
#include "./parser/value.hpp"

using namespace tao::pegtl;

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}