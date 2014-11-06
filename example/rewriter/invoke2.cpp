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
#include "../../include/put_rewriter.hpp"
#include "../../include/get_rewriter.hpp"

#include "../../src/rewriter_base.cpp"
#include "../../src/total_typeid.cpp"
#include "../../src/typebuffer_map.cpp"
#include "../../src/typebuffer.cpp"

#include "double_rw_int_put.hpp"

using typesystems::put_rewriter;
using typesystems::get_rewriter;
using typesystems::typebuffer_container;
using typesystems::has_typebuffer;
using typesystems::use_typebuffer;
using typesystems::set_typebuffer;
using typesystems::typebuffer_interface;
using typesystems::typebuffer;
using typesystems::empty;

int main(){
typebuffer_container buffer;
set_typebuffer<int, std::vector<int> >(buffer);

put_rewriter<double> * dbl_rw = new double_rw_int_put(1);

double value = std::numeric_limits<double>::max();

dbl_rw->rewrite(value, buffer);

  if (empty<int>(buffer)){
  std::cout << "No data" << std::endl;
  return 1;
  }

typebuffer<int, std::vector<int> > & buff
          = use_typebuffer<int, std::vector<int> >(buffer);

std::vector<int> & con = buff.get_container();

std::cout << "number of elements: " << con.size() << std::endl;
std::cout << "the double: " << std::setprecision(15) << value << " turned into: ";
//while (empty<int>(buffer) == false){
///cout << buff.next() << " and ";
//}
std::cout << std::endl;
return 0;
}
