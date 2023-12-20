#include "grammerCP.hpp"
#include "tao/pegtl.hpp"
#include "testParse.hpp"
#include <iostream>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>

namespace pegtl = tao::pegtl;
int main(int argc, char **argv) {
  if( argc > 1) {
      std::string Sample = "List<List<Int>>";

      pegtl::string_input<> in(Sample, "input");

      if( const auto root = pegtl::parse_tree::parse< ddlbx::grammer::Type >( in )){
        pegtl::parse_tree::print_dot(std::cout, *root);
        return 0;
      }
      
      std::cout << "parse error" << std::endl;
  }
  return 0;
}
