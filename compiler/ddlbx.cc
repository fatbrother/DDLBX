#include "grammerCP.hpp"
#include "tao/pegtl.hpp"
#include <iostream>
#include <tao/pegtl/contrib/parse_tree.hpp>
#include <tao/pegtl/contrib/parse_tree_to_dot.hpp>
#include<vector>

namespace pegtl = tao::pegtl;
int main(int argc, char **argv) {
  std::string Sample = "'ab123''123cd'";
  //segmentation fault
  //Intcost(){reta!}!
  //objHI{}!
  pegtl::string_input<> in(Sample, "input");

  if( const auto root = pegtl::parse_tree::parse< ddlbx::grammer::String, ddlbx::grammer::my_selector >( in )){
    pegtl::parse_tree::print_dot(std::cout, *root);
    return 0;
  }
  
  std::cout << "parse error" << std::endl;
  return 0;
}
