//

//          Copyright Sundeep S. Sangha 2013 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../../include/qualified_typeid.hpp"

using typesystems::qualified_typeinfo;
using typesystems::qualified_typeid;

class A{};

class B : public A{};

int main(){

// Create a qualified type id
qualified_typeinfo type_id (
  qualified_typeid<const int>() );

auto type_id_2 (qualified_typeid<int>());

// Compare id / types
  if (qualified_typeid<char>()
  == qualified_typeid<int>()
  ){
  std::cout << "char and int are the"
  " same" << std::endl;
  } else {
  std::cout << "char is not equal to"
  " int" << std::endl;
  }

  if (qualified_typeid<A>()
  == qualified_typeid<A>()
  ){
  std::cout << "class A is the same as"
  " A." << std::endl;
  }

  if (qualified_typeid<A>()
  != qualified_typeid<A>()
  ){
  std::cout << "class A is not the same"
  " as B." << std::endl;
  }

typedef int some_type;

auto id = qualified_typeid<int>();

  /* true statement */
  if (id == qualified_typeid<int>()){
  std::cout << "some_type is a int."
  << std::endl;
  }

return 0;
}
