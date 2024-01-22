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
    >,
    pegtl::opt<RightExpression>
> {};

class Expression : public pegtl::seq<
    pegtl::sor<
        Value,
        Identifier
    >,
    pegtl::star<pegtl::space>,
    pegtl::opt<RightExpression>
> {};

class Declaration : public pegtl::seq<
    Type,
    pegtl::pad<
        Identifier,
        pegtl::space
    >,
    pegtl::opt<RightExpression>
> {};

class Statement : public pegtl::seq<
    pegtl::sor<
        Expression,
        Declaration
    >,
    pegtl::star<pegtl::space>,
    End
> {};

class Block : public pegtl::seq<
    pegtl::one<'{'>,
    pegtl::star<Statement>,
    pegtl::one<'}'>
> {};

class Parameter : public pegtl::seq<
    Type,
    pegtl::star<pegtl::space>,
    Identifier
> {};

class Function : public pegtl::seq<
    pegtl::keyword<'f', 'u', 'n'>,
    Identifier,
    pegtl::one<'('>,
    pegtl::star<pegtl::space>,
    pegtl::list<
        Parameter,
        pegtl::pad<
            pegtl::one<','>,
            pegtl::space
        >
    >,
    pegtl::one<')'>,
    pegtl::star<pegtl::space>,
    pegtl::one<':'>,
    Type,
    pegtl::star<pegtl::space>,
    Block
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
