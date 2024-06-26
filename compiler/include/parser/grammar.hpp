#pragma once

#include <tao/pegtl.hpp>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace parser {

class Integer : public pegtl::seq<
    pegtl::opt<
        pegtl::one<'-'>
    >,
    pegtl::plus<
        pegtl::digit
    >
> {};

class Float : public pegtl::seq<
    Integer,
    pegtl::one<'.'>,
    pegtl::plus<
        pegtl::digit
    >
> {};

class String : public pegtl::seq<
    pegtl::one<'\''>,
    pegtl::star<pegtl::not_one<'\''>>,
    pegtl::one<'\''>
> {};

class Boolean : public pegtl::sor<
    pegtl::keyword<'t', 'r', 'u', 'e'>,
    pegtl::keyword<'f', 'a', 'l', 's', 'e'>,
    pegtl::keyword<'m', 'a', 'y', 'b', 'e'>
> {};

class Value : public pegtl::sor<
    Float,
    Integer,
    String,
    Boolean
> {};

class End : public pegtl::one<'!'> {};

class BinaryOperator : public pegtl::sor<
    pegtl::one<'+'>,
    pegtl::one<'-'>,
    pegtl::one<'*'>,
    pegtl::one<'/'>,
    pegtl::one<'%'>
> {};

class AssignmentOperator : public pegtl::sor<
    pegtl::string<'='>,
    pegtl::string<'+', '='>,
    pegtl::string<'-', '='>,
    pegtl::string<'*', '='>,
    pegtl::string<'/', '='>,
    pegtl::string<'%', '='>
> {};

class UnaryOperator : public pegtl::sor<
    pegtl::one<'!'>,
    pegtl::string<'-', '-'>,
    pegtl::string<'+', '+'>
> {};

class ComparisonOperator : public pegtl::sor<
    pegtl::string<'<', '='>,
    pegtl::string<'>', '='>,
    pegtl::string<'=', '='>,
    pegtl::string<'!', '='>,
    pegtl::one<'>'>,
    pegtl::one<'<'>
> {};

class LogicalOperator : public pegtl::sor<
    pegtl::keyword<'a', 'n', 'd'>,
    pegtl::keyword<'o', 'r'>
> {};

class Identifier : public pegtl::seq<
    pegtl::not_at<
    pegtl::sor<
            pegtl::keyword<'v', 'a', 'r'>,
            pegtl::keyword<'f', 'u', 'n'>,
            pegtl::keyword<'r', 'e', 't'>,
            pegtl::keyword<'o', 'p', 't'>,
            pegtl::keyword<'f', 'o', 'r'>,
            pegtl::keyword<'o', 'b', 'j'>,
            pegtl::keyword<'e', 'x', 't', 'e', 'r', 'n'>
    >
    >,
    pegtl::identifier
> {};

class Type : public pegtl::sor<
    pegtl::keyword<'I', 'n', 't'>,
    pegtl::keyword<'F', 'l', 't'>,
    pegtl::keyword<'S', 't', 'r'>,
    pegtl::keyword<'B', 'o', 'o'>,
    pegtl::keyword<'N', 'o', 'n'>,
    pegtl::keyword<'P', 't', 'r'>,
    Identifier
> {};

class FunctionCall;
class Bracket;

class MemberAccess : public pegtl::seq<
    pegtl::sor<
        FunctionCall,
        Identifier
    >,
    pegtl::plus<
        pegtl::seq<
            pegtl::one<'.'>,
            pegtl::sor<
                FunctionCall,
                Identifier
            >
        >
    >
> {};

class Statement : public pegtl::seq<
    pegtl::seq<
        pegtl::opt<
            UnaryOperator
        >,
        pegtl::sor<
            Bracket,
            Value,
            MemberAccess,
            FunctionCall,
            Identifier
        >
    >,
    pegtl::star<
        pegtl::pad<
            pegtl::sor<
                BinaryOperator,
                ComparisonOperator,
                LogicalOperator
            >,
            pegtl::space
        >,

        // Below code can reduce the hight of AST from stmt->stmt->value to stmt->value
        pegtl::seq<
            pegtl::opt<
                UnaryOperator
            >,
            pegtl::sor<
                Bracket,
                Value,
                MemberAccess,
                FunctionCall,
                Identifier
            >
        >
    >
> {};

class Assignment : public pegtl::seq<
    Identifier,
    pegtl::pad<
        AssignmentOperator,
        pegtl::space
    >,
    Statement
> {};

class Bracket : public pegtl::seq<
    pegtl::one<'('>,
    pegtl::pad<
        Statement,
        pegtl::space
    >,
    pegtl::one<')'>
> {};

class Template : public pegtl::seq<
    pegtl::pad<
        pegtl::one<'<'>,
        pegtl::space
    >,
    pegtl::list<
        Identifier,
        pegtl::one<','>,
        pegtl::space
    >,
    pegtl::pad<
        pegtl::one<'>'>,
        pegtl::space
    >
> {};

class Argument : public pegtl::opt<
    pegtl::list<
        Statement,
        pegtl::one<','>,
        pegtl::space
    >,
    pegtl::success
> {};

class FunctionCall : public pegtl::seq<
    Identifier,
    pegtl::opt<Template>,
    pegtl::one<'('>,
    Argument,
    pegtl::one<')'>
> {};

class VariableDeclaration : public pegtl::seq<
    pegtl::keyword<'v', 'a', 'r'>,
    pegtl::pad<
        Identifier,
        pegtl::space
    >,
    pegtl::seq<
        pegtl::one<'='>,
        pegtl::pad<
            Statement,
            pegtl::space
        >
    >
> {};

class Return : public pegtl::seq<
    pegtl::keyword<'r', 'e', 't'>,
    pegtl::pad<
        Statement,
        pegtl::space
    >
> {};

class Conditional;
class Loop;
class Expression : public pegtl::sor< 
    pegtl::seq<
        pegtl::sor<
            Assignment,
            VariableDeclaration,
            Return,
            Statement
        >,
        End
    >,
    pegtl::sor<
        Loop,
        Conditional
    >
> {};

class Block : public pegtl::seq<
    pegtl::pad<
        pegtl::one<'{'>,
        pegtl::space
    >,
    pegtl::star<
        pegtl::pad<
            Expression,
            pegtl::space
        >
    >,
    pegtl::pad<
        pegtl::one<'}'>,
        pegtl::space
    >
> {};

class Conditional : public pegtl::seq<
    pegtl::keyword<'o', 'p', 't'>,
    pegtl::pad<
        pegtl::one<'('>,
        pegtl::space
    >,
    Statement,
    pegtl::pad<
        pegtl::one<')'>,
        pegtl::space
    >,
    pegtl::pad<
        pegtl::sor<
            Expression,
            Block
        >,
        pegtl::space
    >
> {};

class RangeStart : public pegtl::seq<
    pegtl::keyword<'f', 'r', 'o', 'm'>,
    pegtl::pad<
        Statement,
        pegtl::space
    >
> {};

class RangeEnd : public pegtl::seq<
    pegtl::keyword<'t', 'o'>,
    pegtl::pad<
        Statement,
        pegtl::space
    >
> {};

class RangeStep : public pegtl::seq<
    pegtl::keyword<'s', 't', 'e', 'p'>,
    pegtl::pad<
        Statement,
        pegtl::space
    >
> {};

class LoopRange : public pegtl::seq<
    pegtl::pad<
        Identifier,
        pegtl::space
    >,
    pegtl::opt<RangeStart>,
    RangeEnd,
    pegtl::opt<RangeStep>
> {};

class Loop : public pegtl::seq<
    pegtl::keyword<'f', 'o', 'r'>,
    pegtl::pad<
        pegtl::one<'('>,
        pegtl::space
    >,
    pegtl::sor<
        LoopRange,
        Statement
    >,
    pegtl::pad<
        pegtl::one<')'>,
        pegtl::space
    >,
    pegtl::pad<
        pegtl::sor<
            Expression,
            Block
        >,
        pegtl::space
    >
> {};

class ArrowBlock : public pegtl::seq<
    pegtl::string<'=', '>'>,
    pegtl::pad<
        Expression,
        pegtl::space
    >
> {};

class Parameter : public pegtl::seq<
    Identifier,
    pegtl::pad<
        pegtl::one<':'>,
        pegtl::space
    >,
    Type
> {};

class MultiParameter : public pegtl::list<
    pegtl::pad<
        Parameter,
        pegtl::space
    >,
    pegtl::one<','>,
    pegtl::space
> {};

class EmptyParameter : public pegtl::success {};

class Object : public pegtl::seq<
    pegtl::keyword<'o', 'b', 'j'>,
    pegtl::pad<
        Identifier,
        pegtl::space
    >,
    pegtl::opt<Template>,
    pegtl::one<'{'>,
    pegtl::sor<
        MultiParameter,
        EmptyParameter
    >,
    pegtl::one<'}'>
> {};

class Trait : public pegtl::seq<
    pegtl::one<'{'>,
    pegtl::sor<
        MultiParameter,
        EmptyParameter
    >,
    pegtl::one<'}'>
> {};

class FunctionDeclaration : public pegtl::seq<
    pegtl::keyword<'f', 'u', 'n'>,
    pegtl::opt<
        pegtl::pad<
            pegtl::sor<
                Type,
                Trait
            >,
            pegtl::space
        >,
        pegtl::pad<
            pegtl::one<'.'>,
            pegtl::space
        >
    >,
    pegtl::pad<
        Identifier,
        pegtl::space
    >,
    pegtl::opt<Template>,
    pegtl::one<'('>,
    pegtl::sor<
        MultiParameter,
        EmptyParameter
    >,
    pegtl::one<')'>,
    pegtl::pad<
        pegtl::one<':'>,
        pegtl::space
    >,
    Type
> {};

class ExternalFunction : public pegtl::seq<
    pegtl::keyword<'e', 'x', 't', 'e', 'r', 'n'>,
    pegtl::pad<
        pegtl::space,
        FunctionDeclaration
    >
> {};

class Function : public pegtl::seq<
    FunctionDeclaration,
    pegtl::pad<
        pegtl::sor<
            ArrowBlock,
            Block
        >,
        pegtl::space
    >
> {};

class Program : public pegtl::star<
    pegtl::sor<
        ExternalFunction,
        Function,
        Object,
        pegtl::space
    >
> {};

} // namespace parser    
} // namespace ddlbx
