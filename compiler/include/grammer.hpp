#pragma once

#include <tao/pegtl.hpp>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace grammer {


class Number : public pegtl::seq<
    pegtl::opt<pegtl::one<'-'>>,
    pegtl::plus<pegtl::digit>,
    pegtl::opt<pegtl::seq<
        pegtl::one<'.'>,
        pegtl::star<pegtl::digit>
    >>
> {};

class String : public pegtl::seq<
    pegtl::one<'\''>,
    pegtl::star<pegtl::not_one<'\''>>,
    pegtl::one<'\''>
> {};

class Boolean : public pegtl::sor<
    pegtl::string<'t', 'r', 'u', 'e'>,
    pegtl::string<'f', 'a', 'l', 's', 'e'>,
    pegtl::string<'m', 'a', 'y', 'b', 'e'>
> {};

class Value : public pegtl::sor<
    Number,
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
    pegtl::string<'I', 'n', 't'>,
    pegtl::string<'F', 'l', 'o'>,
    pegtl::string<'S', 't', 'r'>,
    pegtl::string<'B', 'o', 'o'>,
    pegtl::string<'N', 'o', 'n'>
> {};

class Identifier : public pegtl::plus<
    pegtl::sor<
        pegtl::alnum,
        pegtl::one<'_'>
    >
> {};

class RightExpression : public pegtl::seq<
    pegtl::star<pegtl::blank>,
    Operator,
    pegtl::star<pegtl::blank>,
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
    pegtl::star<pegtl::blank>,
    pegtl::opt<RightExpression>
> {};

class Declaration : public pegtl::seq<
    Type,
    pegtl::star<pegtl::blank>,
    Identifier,
    pegtl::star<pegtl::blank>,
    pegtl::opt<RightExpression>
> {};

class Statement : public pegtl::seq<
    pegtl::sor<
        Expression,
        Declaration
    >,
    pegtl::star<pegtl::blank>,
    End
> {};

class Block : public pegtl::seq<
    pegtl::one<'{'>,
    pegtl::star<Statement>,
    pegtl::one<'}'>
> {};

class Parameter : public pegtl::seq<
    Type,
    pegtl::star<pegtl::blank>,
    Identifier
> {};

class Function : public pegtl::seq<
    pegtl::string<'f', 'u', 'n'>,
    pegtl::star<pegtl::blank>,
    Identifier,
    pegtl::one<'('>,
    pegtl::star<pegtl::blank>,
    pegtl::list<
        Parameter,
        pegtl::one<','>,
        pegtl::star<pegtl::blank>
    >,
    pegtl::one<')'>,
    pegtl::star<pegtl::blank>,
    pegtl::one<':'>,
    Type,
    pegtl::star<pegtl::blank>,
    Block
> {};

class Program : public pegtl::seq<
    pegtl::star<pegtl::blank>,
    pegtl::sor<
        Function,
        Statement
    >,
    pegtl::star<pegtl::blank>
> {};


} // namespace grammer    
} // namespace ddlbx
