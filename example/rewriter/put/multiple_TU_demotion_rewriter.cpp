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

class dbl_rw_int_put : public rewriter_put<double>{
public:
  explicit
  dbl_rw_int_put(std::size_t _refs = 0) : rewriter_put<double>(_refs){
  }

  virtual bool
  do_rewrite(
    double const & _value
  , typebuffer_container const & _buffers
  ) const {
    /* check if the int buffer is present */
    if (has_typebuffer<int>(_buffers) == false){
    return false;
    }
  /* split the value before and after the decimal */
  double dbl_int;
  double dbl_dec = modf(_value, &dbl_int);
  typebuffer_interface<int> & buffer = use_typebuffer<int>(_buffers);

  try {
    while (numeric_limits<int>::max() < dbl_int){
    buffer.push(static_cast<int>(dbl_int - numeric_limits<int>::max()));
    dbl_int -= numeric_limits<int>::max();
    }
    buffer.push(static_cast<int>(dbl_int));
    
    while (numeric_limits<int>::max() < dbl_dec){
    buffer.push(static_cast<int>(dbl_dec - numeric_limits<int>::max()));
    dbl_dec -= numeric_limits<int>::max();
    }
    buffer.push(static_cast<int>(dbl_dec));
  } catch (...){
  return false;
  }
  return true;
  }
};

int main(){
typebuffer_container buffer;
set_typebuffer<vector<int>, int>(buffer);

rewriter_put<double> * dbl_rw = new dbl_rw_int_put(1);

double value = numeric_limits<double>::max();

dbl_rw->rewrite(value, buffer);

  if (empty<int>(buffer)){
  cout << "No data" << endl;
  return 1;
  }

typebuffer<int, vector<int> > & buff
          = use_typebuffer<vector<int>, int>(buffer);

cout << "number of elements: " << buff.c.size() << endl;
cout << "the double: " << std::setprecision(15) << value << " turned into: ";
//while (empty<int>(buffer) == false){
///cout << buff.next() << " and ";
//}
cout << endl;
return 0;
}
