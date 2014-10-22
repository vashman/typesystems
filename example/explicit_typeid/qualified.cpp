//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../../include/explicit_typeid.hpp"

using typesystems::explicit_typeid;

int main(){

  /* produce false */
  if (explicit_typeid<int>::compare<int const>()){
  } else {
  std::cout << "int and const int differ." << std::endl;
  }

  if (explicit_typeid<int>::compare<int volatile>()){
  std::cout << "int and volatile int are the same" << std::endl;
  } else {
  std::cout << "int and volatile int are differnt" << std::endl;
  }

return 0;
}
