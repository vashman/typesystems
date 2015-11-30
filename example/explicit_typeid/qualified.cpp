//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../../include/qualified_typeid.hpp"

using typesystems::qualified_typeid;

int main(){

  /* produce false */
  if (qualified_typeid<int const>() == typeid(int)){
  } else {
  std::cout << "int and const int differ." << std::endl;
  }

  if (qualified_typeid<int volatile> == typeid(int)){
  std::cout << "int and volatile int are the same" << std::endl;
  } else {
  std::cout << "int and volatile int are different" << std::endl;
  }

return 0;
}
