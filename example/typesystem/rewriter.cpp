//

#include <iostream>
#include <vector>
#include "../../include/typesystem.hpp"

using typesystems::typesystem;
using typesystems::set_typebuffer;
using typesystems::has_put_rewriter;
using typesystems::has_get_rewriter;

int main() try {

typesystem typesys;
set_typebuffer<int, std::vector<int> >(typesys);

  if (has_put_rewriter<int>(typesys) == true){
  std::cout << "typesystem has a put rewriter for int." << std::endl;
  } else {
  std::cout << "" << std::endl;
  }

  if (has_get_rewriter<char>(typesys) == true){
  std::cout << "typesyste has a get rewriter for char." << std::endl;
  } else {
  std::cout << "Does not have a get rewriter for char." << std::endl;
  }

  if (has_get_rewriter<int>(typesys) == true){
  std::cout << "typesystem has a get rewriter for int." << std::endl;
  } else {
  std::cout << "" << std::endl;
  }

return 0;
} catch (...) {
return 1;
}
