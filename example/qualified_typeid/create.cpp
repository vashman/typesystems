//

//          Copyright Sundeep S. Sangha 2013 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../../include/qualified_typeid.hpp"

using typesystems::qualified_typeinfo;
using typesystems::qualified_typeid;

int main(){

qualified_typeinfo id (
  qualified_typeid<const int>() );

auto type_id (qualified_typeid<int>());

return 0;
}
