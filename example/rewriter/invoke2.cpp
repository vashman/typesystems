//

//

#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
#include <vector>
#include "../../../include/put_rewriter.hpp"

#include "../../../src/rewriter_base.cpp"
#include "../../../src/total_typeid.cpp"
#include "../../../src/typebuffer_map.cpp"
#include "../../../src/typebuffer.cpp"

using std::cout;
using std::endl;
using std::modf;
using std::pow;
using std::vector;
using std::numeric_limits;
using typesystems::rewriter_put;
using typesystems::rewriter_get;
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

rewriter_put<double> * dbl_rw = new dbl_rw_int_put(1);

double value = std::numeric_limits<double>::max();

dbl_rw->rewrite(value, buffer);

  if (empty<int>(buffer)){
  std::cout << "No data" << std::endl;
  return 1;
  }

typebuffer<int, std::vector<int> > & buff
          = use_typebuffer<int, std::vector<int> >(buffer);

std::cout << "number of elements: " << buff.c.size() << std::endl;
std::cout << "the double: " << std::setprecision(15) << value << " turned into: ";
//while (empty<int>(buffer) == false){
///cout << buff.next() << " and ";
//}
std::cout << std::endl;
return 0;
}
