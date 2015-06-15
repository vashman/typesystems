//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <vector>
#include "../../include/owriter.hpp"
#include "../../include/iwriter.hpp"

#include "../../src/owriter_base.cpp"
#include "../../src/iwriter_base.cpp"
#include "../../src/total_typeid.cpp"
#include "../../src/typebuffer_map.cpp"
#include "../../src/typebuffer.cpp"
#include "../../include/typebuffer_queue.hpp"

#include "double_int_put.hpp"

using typesystems::owriter;
using typesystems::iwriter;
using typesystems::iwriter_container;
using typesystems::owriter_container;
using typesystems::add_writer;
using typesystems::use_writer;
using typesystems::typebuffer_container;
using typesystems::has_typebuffer;
using typesystems::use_typebuffer;
using typesystems::set_typebuffer;
using typesystems::typebuffer;
using typesystems::typebuffer_queue;
using typesystems::typebuffer;
using typesystems::empty;

int main(){
typebuffer_container buffer;
set_typebuffer<
  int
, typebuffer_queue<int>
> (buffer);

owriter_container writer;
add_writer<double_int_put>(writer);

double value = std
::numeric_limits<double>::max();

auto &
dblwriter = use_writer<double>(writer);

dblwriter.put(value, buffer, writer);

  if (empty<int>(buffer)){
  std::cout << "No data" << std::endl;
  return 1;
  }

typebuffer<int> &
buff = use_typebuffer<int> (buffer);

std::cout
<< "the double: "
<< std::setprecision(15)
<< value
<< " turned into: ";
//while (empty<int>(buffer) == false){
///cout << buff.next() << " and ";
//}
std::cout << std::endl;
return 0;
}
