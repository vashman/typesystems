//

//          Copyright Sundeep S. Sangha 2013 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../../include/qualified_typeid.hpp"

using typesystems::qualified_typeid;

int main(){

typedef int some_type;

auto id = qualified_typeid<int>();

  /* true statement */
  if (id == qualified_typeinfo<int>){
  std::cout << "some_type is a int."
  << std::endl;
  }

return 0;
}
