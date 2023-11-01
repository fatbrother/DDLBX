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

} // namespace grammer
} // namespace ddlbx