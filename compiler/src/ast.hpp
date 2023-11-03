#include <tao/pegtl.hpp>
#include "grammer.hpp"

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

class Statement : public AstNode {
public:

private:
};

class When : public AstNode {
public:
    When(std::vector<std::unique_ptr<AstNode>> Case, std::unique_ptr<AstNode> Else, std::unique_ptr<AstNode> end)
        :case_(std::move(Case)), else_(std::move(Else)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> else_;
    std::unique_ptr<AstNode> end_;
    std::vector<std::unique_ptr<AstNode>> case_;
};

class Case : public AstNode {
public:

private:
    std::unique_ptr<AstNode> expression_;
    std::unique_ptr<AstNode> statement_;
    std::unique_ptr<AstNode> end_;
};

class Else : public AstNode {
public:
    Else(std::vector<std::unique_ptr<AstNode>> statement, std::vector<std::unique_ptr<AstNode>> end)
        :statement_(std::move(statement)), end_(std::move(end)) {}
private:
    std::vector<std::unique_ptr<AstNode>> statement_;
    std::vector<std::unique_ptr<AstNode>> end_;
};

class Format : public AstNode {
public:
    Format(std::unique_ptr<AstNode> regex, std::unique_ptr<AstNode> end)
        :regex_(std::move(regex)), end_(std::move(end)) {}
private:
    std::unique_ptr<AstNode> regex_;
    std::unique_ptr<AstNode> end_;
};

class Return : public AstNode {
public:
    Return(std::unique_ptr<AstNode> expression, std::unique_ptr<AstNode> end)
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

class Expression : public AstNode {

};

class Literal : AstNode {

};
} // namespace grammer
} // namespace ddlbx