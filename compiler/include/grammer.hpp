#pragma once

#include <tao/pegtl.hpp>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace grammer {


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
    Integer,
    Float,
    String,
    Boolean
> {};

class End : public pegtl::one<'!'> {};

class Operator : public pegtl::sor<
    pegtl::one<'+'>,
    pegtl::one<'-'>,
    pegtl::one<'*'>,
    pegtl::one<'/'>,
    pegtl::one<'%'>,
    pegtl::one<'^'>,
    pegtl::one<'&'>,
    pegtl::one<'|'>,
    pegtl::one<'~'>,
    pegtl::one<'='>,
    pegtl::one<'>'>,
    pegtl::one<'<'>,
    pegtl::string<'<', '='>,
    pegtl::string<'>', '='>,
    pegtl::string<'=', '='>,
    pegtl::string<'n', 'o', 't'>,
    pegtl::string<'a', 'n', 'd'>,
    pegtl::string<'o', 'r'>
> {};

class Type : public pegtl::sor<
    pegtl::keyword<'I', 'n', 't'>,
    pegtl::keyword<'F', 'l', 'o'>,
    pegtl::keyword<'S', 't', 'r'>,
    pegtl::keyword<'B', 'o', 'o'>,
    pegtl::keyword<'N', 'o', 'n'>
> {};

class Identifier : public pegtl::plus<
    pegtl::sor<
        pegtl::alnum,
        pegtl::one<'_'>
    >
> {};

class RightExpression : public pegtl::seq<
    pegtl::pad<
        Operator,
        pegtl::space
    >,
    pegtl::sor<
        Value,
        Identifier
    >
> {};

class Expression : public pegtl::seq<
    pegtl::sor<
        Value,
        Identifier
    >,
    pegtl::star<RightExpression>
> {};

class Declaration : public pegtl::seq<
    pegtl::keyword<'v', 'a', 'r'>,
    pegtl::pad<
        Identifier,
        pegtl::space
    >,
    pegtl::seq<
        pegtl::one<'='>,
        pegtl::pad<
            Expression,
            pegtl::space
        >
    >
> {};

class Statement : public pegtl::seq<
    pegtl::sor<
        Declaration,
        Expression
    >,
    End
> {};

class Block : public pegtl::seq<
    pegtl::pad<
        pegtl::one<'{'>,
        pegtl::space
    >,
    pegtl::star<
        pegtl::pad<
            Statement,
            pegtl::space
        >
    >,
    pegtl::pad<
        pegtl::one<'}'>,
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
    Parameter,
    pegtl::pad<
        pegtl::one<','>,
        pegtl::space
    >
> {};

class Function : public pegtl::seq<
    pegtl::keyword<'f', 'u', 'n'>,
    pegtl::pad<
        Identifier,
        pegtl::space
    >,
    pegtl::one<'('>,
    pegtl::sor<
        MultiParameter,
        Parameter,
        pegtl::success
    >,
    pegtl::one<')'>,
    pegtl::pad<
        pegtl::one<':'>,
        pegtl::space
    >,
    Type,
    pegtl::pad<
        Block,
        pegtl::space
    >
> {};

class Program : public pegtl::pad<
    pegtl::star<
        pegtl::sor<
            Function,
            Statement,
            pegtl::space,
            pegtl::eol
        >
    >,
    pegtl::star<pegtl::space>
> {};


} // namespace grammer    
} // namespace ddlbx
