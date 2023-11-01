#include <tao/pegtl.hpp>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace grammer {

// <program> ::= <main> <function>* <object>* <function>*
struct Program : pegtl::seq<
    Main,
    pegtl::star<Function>,
    pegtl::star<Object>,
    pegtl::star<Function>
> {};

// <main> ::= "Int main(" <argument>* ")" <block>
struct Main : pegtl::seq<
    pegtl::string<'I', 'n', 't'>,
    pegtl::string<'m', 'a', 'i', 'n'>,
    pegtl::one<'('>,
    pegtl::star<Argument>,
    pegtl::one<')'>,
    Block
> {};

// <end> ::= "!"
struct End : pegtl::one<'!'> {};

// <block> ::= "{" <statement>* "}" <end>
struct Block : pegtl::seq<
    pegtl::one<'{'>,
    pegtl::star<Statement>,
    pegtl::one<'}'>,
    End
> {};

// <function> ::= <type> <identifier> "(" <argument>* ")" ("=>" <statement> | <block>) <end>
struct Function : pegtl::seq<
    Type,
    Identifier,
    pegtl::one<'('>,
    pegtl::star<Argument>,
    pegtl::one<')'>,
    pegtl::sor<
        pegtl::seq<
            pegtl::one<'='>,
            pegtl::one<'>'>,
            Statement
        >,
        Block
    >,
    End
> {};

// <argument> ::= <type> <identifier> [ "=" <expression> ] <end>
struct Argument : pegtl::seq<
    Type,
    Identifier,
    pegtl::opt<
        pegtl::seq<
            pegtl::one<'='>,
            Expression
        >
    >,
    End
> {};

// <object> ::= "obj" <identifier> "{" <argument>* <function>* "}" <end>
struct Object : pegtl::seq<
    pegtl::string<'o', 'b', 'j'>,
    Identifier,
    pegtl::one<'{'>,
    pegtl::star<Argument>,
    pegtl::star<Function>,
    pegtl::one<'}'>,
    End
> {};

// <statement> ::= <expression> <end>
//               | <when>
//               | <format>
//               | <return>
//               | <end>
struct Statement : pegtl::sor<
    Expression,
    When,
    Format,
    Return,
    End
> {};

// <when> ::= "when" "{" <case>* [<else>] "}" <end>
struct When : pegtl::seq<
    pegtl::string<'w', 'h', 'e', 'n'>,
    pegtl::one<'{'>,
    pegtl::star<Case>,
    pegtl::opt<Else>,
    pegtl::one<'}'>,
    End
> {};

// <case> ::= "case" <expression> ":" ( <statement>* | "{" <statement>* | "end!" "}" ) <end>
struct Case : pegtl::seq<
    pegtl::string<'c', 'a', 's', 'e'>,
    Expression,
    pegtl::one<':'>,
    pegtl::sor<
        pegtl::star<Statement>,
        pegtl::one<'{'>,
        pegtl::star<Statement>,
        pegtl::string<'e', 'n', 'd', '!'>,
        pegtl::one<'}'>
    >,
    End
> {};

// <else> ::= "else" ( <statement>* | "{" <statement>* | "end!" "}" ) <end>
struct Else : pegtl::seq<
    pegtl::string<'e', 'l', 's', 'e'>,
    pegtl::sor<
        pegtl::star<Statement>,
        pegtl::seq<
            pegtl::one<'{'>,
            pegtl::star<Statement>,
            pegtl::string<'e', 'n', 'd', '!'>,
            pegtl::one<'}'>
        >
    >,
    End 
> {};

// <format> ::= "del" | "undel" <regex> <end>
struct Format : pegtl::seq<
    pegtl::sor<
        pegtl::string<'d', 'e', 'l'>,
        pegtl::string<'u', 'n', 'd', 'e', 'l'>
    >,
    Regex
> {};

// <return> ::= "ret" <expression> <end>
struct Return : pegtl::seq<
    pegtl::string<'r', 'e', 't'>,
    Expression, 
    End
> {};

// <type> ::= "Int"
//          | "Str"
//          | "Nul"
//          | "Boo"
//          | "Reg"
//          | "List" "<" <type> ">"
struct Type : pegtl::sor<
    pegtl::string<'I', 'n', 't'>,
    pegtl::string<'S', 't', 'r'>,
    pegtl::string<'N', 'u', 'l'>,
    pegtl::string<'B', 'o', 'o'>,
    pegtl::string<'R', 'e', 'g'>,
    pegtl::seq<
        pegtl::string<'L', 'i', 's', 't'>,
        pegtl::one<'<'>,
        Type,
        pegtl::one<'>'>
    >
> {};

// <expression> ::= (<identifier>
//                 | <literal>
//                 | <function-call>
//                 | <object-call>
//                 | <expression> <operator> <expression>
//                 | "(" <expression> ")"
//                 | <regex>)
//                | <reversing>
struct Expression : pegtl::sor<
    Identifier,
    Literal,
    FunctionCall,
    ObjectCall,
    pegtl::seq<
        Expression,
        Operator,
        Expression
    >,
    pegtl::seq<
        pegtl::one<'('>,
        Expression,
        pegtl::one<')'>
    >,
    Regex,
    Reversing
> {};

// <literal> ::= <number> | <string> | <boolean> | <list>
struct Literal : pegtl::sor<
    Number,
    String,
    Boolean,
    List
> {};

// <number> ::= [ "-" ] <digit>+ [ "." <digit>+ ]
struct Number : pegtl::seq<
    pegtl::opt<
        pegtl::one<'-'>
    >,
    pegtl::plus<Digit>,
    pegtl::opt<
        pegtl::seq<
            pegtl::one<'.'>,
            pegtl::plus<Digit>
        >
    >
> {};

// <string> ::= "'" <character>* "'"
struct String : pegtl::seq<
    pegtl::one<'\''>,
    pegtl::star<Character>,
    pegtl::one<'\''>
> {};

// <boolean> ::= "true" | "false"
struct Boolean : pegtl::sor<
    pegtl::string<'t', 'r', 'u', 'e'>,
    pegtl::string<'f', 'a', 'l', 's', 'e'>
> {};

// <regex> ::= "@(" <character>* ")" 
struct Regex : pegtl::seq<
    pegtl::one<'@'>,
    pegtl::one<'('>,
    pegtl::star<Character>,
    pegtl::one<')'>
> {};

// <list> ::= "[" <literal> ( "," <literal> )* "]"
struct List : pegtl::seq<
    pegtl::one<'['>,
    Literal,
    pegtl::star<
        pegtl::seq<
            pegtl::one<','>,
            Literal
        >
    >,
    pegtl::one<']'>
> {};

// <function-call> ::= <identifier> "(" <expression>* ")" <end>
struct FunctionCall : pegtl::seq<
    Identifier,
    pegtl::one<'('>,
    pegtl::star<Expression>,
    pegtl::one<')'>,
    End
> {};

// <object-call> ::= <identifier> "." <identifier> "(" <expression>* ")" <end>
struct ObjectCall : pegtl::seq<
    Identifier,
    pegtl::one<'.'>,
    Identifier,
    pegtl::one<'('>,
    pegtl::star<Expression>,
    pegtl::one<')'>,
    End
> {};

// <reversing> ::= "rev" <end>
struct Reversing : pegtl::seq<
    pegtl::string<'r', 'e', 'v'>,
    End
> {};

// <operator> ::= "+"
//              | "-"
//              | "*"
//              | "/"
//              | "%"
//              | "=="
//              | "\="
//              | "<"
//              | ">"
//              | "<="
//              | ">="
//              | "&&"
//              | "||"
//              | "\"
//              | "="
struct Operator : pegtl::sor<
    pegtl::string<'+'>,
    pegtl::string<'-'>,
    pegtl::string<'*'>,
    pegtl::string<'/'>,
    pegtl::string<'%'>,
    pegtl::string<'=', '='>,
    pegtl::string<'\\', '='>,
    pegtl::string<'<'>,
    pegtl::string<'>'>,
    pegtl::string<'<', '='>,
    pegtl::string<'>', '='>,
    pegtl::string<'&', '&'>,
    pegtl::string<'|', '|'>,
    pegtl::string<'\\'>,
    pegtl::string<'='>
> {};

// <identifier> ::= (<letter> | <digit> | "_")+
struct Identifier : pegtl::plus<
    pegtl::sor<
        Letter,
        Digit,
        pegtl::one<'_'>
    >
> {};

// <letter> ::= "a" | "b" | ... | "z" | "A" | "B" | ... | "Z"
struct Letter : pegtl::sor<
    pegtl::range<'a', 'z'>,
    pegtl::range<'A', 'Z'>
> {};

// <digit> ::= "0" | "1" | ... | "9"
struct Digit : pegtl::range<'0', '9'> {};

// <symbol> ::= "!" | "@" | "#" | "$" | "%" | "^" | "&" | "*" | "(" | ")" | "-" | "+" | "=" | "{" | "}" | "[" | "]" | "|" | "\" | ":" | ";" | "'" | '"' | "<" | ">" | "," | "." | "?" | "/" | "`" | "~" | "_"
struct Symbol : pegtl::sor<
    pegtl::one<'!'>,
    pegtl::one<'@'>,
    pegtl::one<'#'>,
    pegtl::one<'$'>,
    pegtl::one<'%'>,
    pegtl::one<'^'>,
    pegtl::one<'&'>,
    pegtl::one<'*'>,
    pegtl::one<'('>,
    pegtl::one<')'>,
    pegtl::one<'-'>,
    pegtl::one<'+'>,
    pegtl::one<'='>,
    pegtl::one<'{'>,
    pegtl::one<'}'>,
    pegtl::one<'['>,
    pegtl::one<']'>,
    pegtl::one<'|'>,
    pegtl::one<'\\'>,
    pegtl::one<':'>,
    pegtl::one<';'>,
    pegtl::one<'\''>,
    pegtl::one<'"'>,
    pegtl::one<'<'>,
    pegtl::one<'>'>,
    pegtl::one<','>,
    pegtl::one<'.'>,
    pegtl::one<'?'>,
    pegtl::one<'/'>,
    pegtl::one<'`'>,
    pegtl::one<'~'>,
    pegtl::one<'_'>
> {};

// <character> ::= <letter> | <digit> | <symbol>
struct Character : pegtl::sor<
    Letter,
    Digit,
    Symbol
> {};


} // namespace grammer
} // namespace ddlbx
