//

#include <iostream>
#include <vector>
#include <exception>
#include "../../include/typesystem.hpp"

using typesystems::typesystem;
using typesystems::set_typebuffer;
using typesystems::use_get_rewriter;
using typesystems::use_put_rewriter;
using typesystems::get_rewriter;
using typesystems::put_rewriter;

int main() try {

typesystem typesys;
set_typebuffer<int, std::vector<int> >(typesys);

try {

get_rewriter<int> & grw = use_get_rewriter<int>(typesys);

put_rewriter<int> & prw = use_put_rewriter<int>(typesys);

  }
    catch (...) {
  std::cerr << "";
  }

return 0;
}
  catch (std::exception const & _e) {
std::cerr << _e.what();
return 1;
}
  catch (...) {
std::cerr << "A unknown exception was thrown.\n";
return 1;
}
