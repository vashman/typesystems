//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>
#include "../../src/typebuffer.cpp"
#include "../../src/typebuffer_map.cpp"
#include "../../src/total_typeid.cpp"

using typesystems::typebuffer_container;
using typesystems::typebuffer;
using typesystems::typebuffer_interface;
using typesystems::set_typebuffer;
using typesystems::has_typebuffer;
using typesystems::use_typebuffer;
using typesystems::empty;
using typesystems::clear;

int main(){
typebuffer_container buffers;

set_typebuffer<int, std::vector<int> >(buffers);
set_typebuffer<char, std::vector<char> >(buffers);

  if (has_typebuffer<int>(buffers) == false){
  std::cout << "" << std::endl;
  return 1;
  }

  if (has_typebuffer<char>(buffers) == false){
  std::cout << "" << std::endl;
  return 1;
  }

typebuffer_interface<int> & int_buff = use_typebuffer<int>(buffers);
typebuffer_interface<char> & char_buff = use_typebuffer<char>(buffers);

int_buff.push(42);
char_buff.push('A');

// run 2 times
for (int i = 0; i<2; ++i){
std::cout << "loop count: " << i << std::endl;

  if (empty<int>(buffers)){
  std::cout << "there are no int types" << std::endl;
  } else {
  std::cout << "there are int types" << std::endl;
  }

  if (empty<char>(buffers)){
  std::cout << "there are no char tyoes" << std::endl;
  } else {
  std::cout << "there are char types" << std::endl;
  }

  /* clear all buffers */
  clear(buffers);

}// end outer for

return 0;
}
