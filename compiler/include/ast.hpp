#include <tao/pegtl.hpp>
#include "grammer.hpp"
#include <vector>

namespace pegtl = tao::pegtl;

namespace ddlbx {
namespace grammer {

class AstNode {
public:
    virtual ~AstNode() = default;
};

class Program : public AstNode {
public:
    Program(std::unique_ptr<AstNode> main, std::vector<std::unique_ptr<AstNode>> functions, std::vector<std::unique_ptr<AstNode>> objects)
        : main_(std::move(main)), functions_(std::move(functions)), objects_(std::move(objects)) {}
private:
    std::unique_ptr<AstNode> main_;
    std::vector<std::unique_ptr<AstNode>> functions_;
    std::vector<std::unique_ptr<AstNode>> objects_;
};

class Main : public AstNode {
    Main(std::vector<std::unique_ptr<AstNode>> argument, std::unique_ptr<AstNode> block)
        : argument_(std::move(argument)), block_(std::move(block)) {}
private:
    std::vector<std::unique_ptr<AstNode>> argument_;
    std::unique_ptr<AstNode> block_;
};

class End : public AstNode {

};

class Block : public AstNode {
public:
    Block(std::vector<std::unique_ptr<AstNode>> statement, std::unique_ptr<AstNode> end)
        :statement_(std::move(statement)), end_(std::move(end)) {}
    virtual ~Block() noexcept override = default;
private:
    std::vector<std::unique_ptr<AstNode>> statement_;
    std::unique_ptr<AstNode> end_;
};

class Function : public AstNode {
public:
    Function(std::unique_ptr<AstNode> type, std::unique_ptr<AstNode> identifier, std::vector<std::unique_ptr<AstNode>> argument,
             std::unique_ptr<AstNode> statement, std::unique_ptr<AstNode> block, std::unique_ptr<AstNode> end)
        :type_(std::move(type)), identifier_(std::move(identifier)), argument_(std::move(argument)), statement_(std::move(statement)),
         block_(std::move(block)) {}
private:
    std::unique_ptr<AstNode> type_;
    std::unique_ptr<AstNode> identifier_;
    std::vector<std::unique_ptr<AstNode>> argument_;
    std::unique_ptr<AstNode> statement_;
    std::unique_ptr<AstNode> block_;
};

class Argument : public AstNode {
public:
    Argument(std::unique_ptr<AstNode> type, std::unique_ptr<AstNode> identifier, std::unique_ptr<AstNode> expression, 
             std::unique_ptr<AstNode> end)
        :type_(std::move(type)), identifier_(std::move(identifier)), expression_(std::move(expression)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> type_;
    std::unique_ptr<AstNode> identifier_;
    std::unique_ptr<AstNode> expression_;
    std::unique_ptr<AstNode> end_;
};

class Object : public AstNode {
public:
    Object(std::unique_ptr<AstNode> identifier, std::vector<std::unique_ptr<AstNode>> argument, std::vector<std::unique_ptr<AstNode>> function, std::unique_ptr<AstNode> end)
        :identifier_(std::move(identifier)), argument_(std::move(argument)), function_(std::move(function)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> identifier_;
    std::vector<std::unique_ptr<AstNode>> argument_;
    std::vector<std::unique_ptr<AstNode>> function_;
    std::unique_ptr<AstNode> end_;
};

// <statement> ::= <expression> <end>
//               | <when>
//               | <format>
//               | <return>
class Statement : public AstNode {
public:
    Statement(std::unique_ptr<AstNode> expression, std::unique_ptr<AstNode> whenState, std::unique_ptr<AstNode> formatState, 
              std::unique_ptr<AstNode> returnState)
        :expression_(std::move(expression)), whenState_(std::move(whenState)), formatState_(std::move(formatState)), returnState_(std::move(returnState)) {}
private:
    std::unique_ptr<AstNode> expression_;
    std::unique_ptr<AstNode> whenState_;
    std::unique_ptr<AstNode> formatState_;
    std::unique_ptr<AstNode> returnState_;
};

class WhenState : public AstNode {
public:
    WhenState(std::vector<std::unique_ptr<AstNode>> caseState, std::unique_ptr<AstNode> elseState, std::unique_ptr<AstNode> end)
        :caseState_(std::move(caseState)), elseState_(std::move(elseState)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> elseState_;
    std::unique_ptr<AstNode> end_;
    std::vector<std::unique_ptr<AstNode>> caseState_;
};

class CaseState : public AstNode {
public:
    CaseState(std::unique_ptr<AstNode> expression, std::unique_ptr<AstNode> statement, std::unique_ptr<AstNode> end)
        :expression_(std::move(expression)), statement_(std::move(statement)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> expression_;
    std::unique_ptr<AstNode> statement_;
    std::unique_ptr<AstNode> end_;
};

class ElseState : public AstNode {
public:
    ElseState(std::vector<std::unique_ptr<AstNode>> statement, std::vector<std::unique_ptr<AstNode>> end)
        :statement_(std::move(statement)), end_(std::move(end)) {}
private:
    std::vector<std::unique_ptr<AstNode>> statement_;
    std::vector<std::unique_ptr<AstNode>> end_;
};

class FormatState : public AstNode {
public:
    FormatState(std::unique_ptr<AstNode> regex, std::unique_ptr<AstNode> end)
        :regex_(std::move(regex)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> regex_;
    std::unique_ptr<AstNode> end_;
};

class ReturnState : public AstNode {
public:
    ReturnState(std::unique_ptr<AstNode> expression, std::unique_ptr<AstNode> end)
        :expression_(std::move(expression)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> expression_;
    std::unique_ptr<AstNode> end_;
};

class Type : public AstNode {
public:
    Type(std::string dataType) : dataType_(dataType) {}
private:
    std::string dataType_;
};

// <expression> ::= (<identifier>
//                 | <literal>
//                 | <function-call>
//                 | <object-call>
//                 | <expression> <operator> <expression>
//                 | "(" <expression> ")"
//                 | <regex>)
//                | <reversing>
class Expression : public AstNode {
public:
    Expression(std::unique_ptr<AstNode> identifier, std::unique_ptr<AstNode> literal, std::unique_ptr<AstNode> functionCall,
               std::unique_ptr<AstNode> objectCall, std::unique_ptr<AstNode> expression, std::unique_ptr<AstNode> operator_,
               std::unique_ptr<AstNode> regex, std::unique_ptr<AstNode> reversing)
        :identifier_(std::move(identifier)), literal_(std::move(literal)), functionCall_(std::move(functionCall)), objectCall_(std::move(objectCall)),
         expression_(std::move(expression)), operator_(std::move(operator_)), regex_(std::move(regex)), reversing_(std::move(reversing)) {}
private:
    std::unique_ptr<AstNode> identifier_;
    std::unique_ptr<AstNode> literal_;
    std::unique_ptr<AstNode> functionCall_;
    std::unique_ptr<AstNode> objectCall_;
    std::unique_ptr<AstNode> expression_;
    std::unique_ptr<AstNode> operator_;
    std::unique_ptr<AstNode> regex_;
    std::unique_ptr<AstNode> reversing_;
};


// <literal> ::= <number> | <string> | <boolean> | <list>
class Literal : AstNode {
public:
    Literal(std::unique_ptr<AstNode> number, std::unique_ptr<AstNode> string, std::unique_ptr<AstNode> boolean, std::unique_ptr<AstNode> list)
        :number_(std::move(number)), string_(std::move(string)), boolean_(std::move(boolean)), list_(std::move(list)) {}
private:
    std::unique_ptr<AstNode> number_;
    std::unique_ptr<AstNode> string_;
    std::unique_ptr<AstNode> boolean_;
    std::unique_ptr<AstNode> list_;
};

// <number> ::= [ "-" ] <digit>+ [ "." <digit>+ ]
class Number : AstNode {
public:
    Number(std::unique_ptr<AstNode> digit, std::unique_ptr<AstNode> dot)
        :digit_(std::move(digit)), dot_(std::move(dot)) {}
private:
    std::unique_ptr<AstNode> digit_;
    std::unique_ptr<AstNode> dot_;
};

// <string> ::= "'" <character>* "'"
class String : AstNode {
public:
    String(std::vector<std::unique_ptr<AstNode>> character)
        :character_(std::move(character)) {}
private:
    std::vector<std::unique_ptr<AstNode>> character_;
};

// <boolean> ::= "true" | "false"
class Boolean : AstNode {
public:
    Boolean(bool Boolean)
        : boolean_(Boolean){}
private:
    bool boolean_;
};

// <regex> ::= "@(" <character>* ")" 
class Regex : AstNode {
public:
    Regex(std::vector<std::unique_ptr<AstNode>> character)
        :character_(std::move(character)) {}
private:
    std::vector<std::unique_ptr<AstNode>> character_;
};

// <list> ::= "[" <literal> ( "," <literal> )* "]"
class List : AstNode {
public:
    List(std::vector<std::unique_ptr<AstNode>> literal)
        :literal_(std::move(literal)) {}
private:
    std::vector<std::unique_ptr<AstNode>> literal_;
};

// <function-call> ::= <identifier> "(" <expression>* ")" <end>
class FunctionCall : AstNode {
public:
    FunctionCall(std::unique_ptr<AstNode> identifier, std::vector<std::unique_ptr<AstNode>> expression, std::unique_ptr<AstNode> end)
        :identifier_(std::move(identifier)), expression_(std::move(expression)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> identifier_;
    std::vector<std::unique_ptr<AstNode>> expression_;
    std::unique_ptr<AstNode> end_;
};

// <object-call> ::= <identifier> "." <identifier> "(" <expression>* ")" <end>
class ObjectCall : AstNode {
public:
    ObjectCall(std::unique_ptr<AstNode> identifier, std::unique_ptr<AstNode> identifier2, std::vector<std::unique_ptr<AstNode>> expression, std::unique_ptr<AstNode> end)
        :identifier_(std::move(identifier)), identifier2_(std::move(identifier2)), expression_(std::move(expression)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> identifier_;
    std::unique_ptr<AstNode> identifier2_;
    std::vector<std::unique_ptr<AstNode>> expression_;
    std::unique_ptr<AstNode> end_;
};

// <reversing> ::= "rev" <end>
class Reversing : AstNode {
public:
    Reversing(std::unique_ptr<AstNode> end)
        :end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> end_;
};

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
class Operator : AstNode {
public:
    Operator(std::string op)
        :op_(op) {}
private:
    std::string op_;
};

// <identifier> ::= (<letter> | <digit> | "_")+
class Identifier : AstNode {
public:
    Identifier(std::string identifier)
        :identifier_(identifier) {}
private:
    std::string identifier_;
};

// <letter> ::= "a" | "b" | ... | "z" | "A" | "B" | ... | "Z"
class Letter : AstNode {
public:
    Letter(char letter)
        :letter_(letter) {}
private:
    char letter_;
};

// <digit> ::= "0" | "1" | ... | "9"
class Digit : AstNode {
public:
    Digit(char digit)
        :digit_(digit) {}
private:
    char digit_;
};

// <symbol> ::= "!" | "@" | "#" | "$" | "%" | "^" | "&" | "*" | "(" | ")" | "-" | "+" | "=" | "{" | "}" | "[" | "]" | "|" | "\" | ":" | ";" | "'" | '"' | "<" | ">" | "," | "." | "?" | "/" | "`" | "~" | "_"
class Symbol : AstNode {
public:
    Symbol(char symbol)
        :symbol_(symbol) {}
private:
    char symbol_;
};

// <character> ::= <letter> | <digit> | <symbol>
class Character : AstNode {
public:
    Character(std::unique_ptr<AstNode> letter, std::unique_ptr<AstNode> digit, std::unique_ptr<AstNode> symbol)
        :letter_(std::move(letter)), digit_(std::move(digit)), symbol_(std::move(symbol)) {}
private:
    std::unique_ptr<AstNode> letter_;
    std::unique_ptr<AstNode> digit_;
    std::unique_ptr<AstNode> symbol_;
};
} // namespace grammer
} // namespace ddlbx