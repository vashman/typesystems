//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <vector>
#include "../../include/typebuffer.hpp"

using typesystems::typebuffer_container;
using typesystems::set_typebuffer;
using typesystems::has_typebuffer;
using typesystems::use_typebuffer;

int main(){

typebuffer_container container_1;

set_typebuffer<int, std::vector<int> >(container_1);

  if (has_typebuffer<int>(container_1) == false){
  return 1;
  }

auto & buffer = use_typebuffer<int>(container_1);

  if (has_typebuffer<int, std::vector<int> >(container_1) == false){
  return 1;
  }

auto & b = use_typebuffer<int, std::vector<int> >(container_1);

return 0;
}
