#pragma once

#include <tao/pegtl.hpp>

#include "parser/grammar.hpp"

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace parser {

template <typename Rule>
struct Selector : std::false_type {};

template <> struct Selector<Integer> : std::true_type {};
template <> struct Selector<Float> : std::true_type {};
template <> struct Selector<String> : std::true_type {};
template <> struct Selector<Value> : std::true_type {};
template <> struct Selector<Boolean> : std::true_type {};
template <> struct Selector<UnaryOperator> : std::true_type {};
template <> struct Selector<BinaryOperator> : std::true_type {};
template <> struct Selector<ComparisonOperator> : std::true_type {};
template <> struct Selector<LogicalOperator> : std::true_type {};
template <> struct Selector<Type> : std::true_type {};
template <> struct Selector<Identifier> : std::true_type {};
template <> struct Selector<MemberAccess> : std::true_type {};
template <> struct Selector<Expression> : std::true_type {};
template <> struct Selector<FunctionCall> : std::true_type {};
template <> struct Selector<VariableDeclaration> : std::true_type {};
template <> struct Selector<Statement> : std::true_type {};
template <> struct Selector<Assignment> : std::true_type {};
template <> struct Selector<Bracket> : std::true_type {};
template <> struct Selector<Return> : std::true_type {};
template <> struct Selector<Block> : std::true_type {};
template <> struct Selector<Parameter> : std::true_type {};
template <> struct Selector<MultiParameter> : std::true_type {};
template <> struct Selector<EmptyParameter> : std::true_type {};
template <> struct Selector<Object> : std::true_type {};
template <> struct Selector<Function> : std::true_type {};
template <> struct Selector<ExternalFunction> : std::true_type {};
template <> struct Selector<Conditional> : std::true_type {};
template <> struct Selector<RangeStart> : std::true_type {};
template <> struct Selector<RangeEnd> : std::true_type {};
template <> struct Selector<RangeStep> : std::true_type {};
template <> struct Selector<LoopRange> : std::true_type {};
template <> struct Selector<Loop> : std::true_type {};
template <> struct Selector<Program> : std::true_type {};

}  // namespace parser
}  // namespace ddlbx