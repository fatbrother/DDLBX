#pragma once

#include <tao/pegtl.hpp>

#include "grammer.hpp"

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace grammer {

template <typename Rule>
struct Selector : std::false_type {};

template <> struct Selector<Integer> : std::true_type {};
template <> struct Selector<Float> : std::true_type {};
template <> struct Selector<String> : std::true_type {};
template <> struct Selector<Boolean> : std::true_type {};
template <> struct Selector<Operator> : std::true_type {};
template <> struct Selector<Type> : std::true_type {};
template <> struct Selector<Identifier> : std::true_type {};
template <> struct Selector<Expression> : std::true_type {};
template <> struct Selector<Call> : std::true_type {};
template <> struct Selector<Declaration> : std::true_type {};
template <> struct Selector<Statement> : std::true_type {};
template <> struct Selector<Block> : std::true_type {};
template <> struct Selector<Parameter> : std::true_type {};
template <> struct Selector<MultiParameter> : std::true_type {};
template <> struct Selector<Function> : std::true_type {};
template <> struct Selector<Program> : std::true_type {};

}  // namespace grammer
}  // namespace ddlbx