//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../../include/qualified_typeid.hpp"

using typesystems::qualified_typeid;

int main(){

typedef int some_type;
qualified_typeid<int> id()
  /* true statement */
  if (id == typeid(int)){
  std::cout << "some_type is a int." << std::endl;
  }

return 0;
}
