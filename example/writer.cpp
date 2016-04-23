#include "../src/qualified_typeid.cpp"
#include "../include/writer.hpp"

#include <iterator>
#include <map>
#include <vector>
#include <iostream>

using namespace typesystems;
using std::begin;
using std::back_inserter;

// other typesystem *******************/
typedef float other_type;

// application typesytem **************/
typedef int internal_type;
internal_type default_value = 0;

// typesystem model *******************/
std::vector<other_type> output_buffer;

typedef std::back_insert_iterator <
  std::vector<other_type> > oiter_t;

/* writer map
erase the type of writer used as
well. */
std::map <
  qualified_typeinfo, owriter_base >
writer_map;

// free function re-writer
template <typename Iter>
bool
output_function (
  internal_type const & _var
, Iter _out
){
*_out = (static_cast<other_type>(_var) + 0.50);
++_out;
return true;
}

struct input_functor {
template <typename Iter>
bool
operator ()(
  internal_type & _v
, Iter _iter
, Iter _end
){
  if (_iter == _end) return false;
other_type temp (*_iter++);
_v = static_cast<internal_type>((2*temp));
return true;
}
};

// functor re-writer
struct output_functor {
template <typename Iter>
bool operator() (
  internal_type const & _var
, Iter _out
){
*_out = (other_type(_var) + 1.01);
++_out;
return true;
}
};

auto lamda = [] (
  internal_type const & _var
, oiter_t _output
) -> bool {
*_output = (static_cast<other_type>(_var) + 1.50);
return true;
};

int main (){
/* types are added at typesystem
boundary. */
auto id (
  qualified_typeid<internal_type>() );

// add lamda re-writer
writer_map [id]
  = make_owriter <internal_type> (
  lamda, back_inserter(output_buffer) );

// add free re-writer
writer_map [id]
  = make_owriter<internal_type> (
  output_function<oiter_t>
, back_inserter(output_buffer) );

// add functor re-writer
writer_map [id]
  = make_owriter<internal_type> (
  output_functor()
, back_inserter(output_buffer) );

internal_type var = default_value;

bool rv = use_owriter (
  default_value
, std::back_inserter(output_buffer)
, writer_map[id] );

  if (rv == true){
    if (output_buffer.empty()) {
    std::cout << "Output failed\n";  
    } else {
    other_type val = output_buffer[0];
    std::cout << "Output value is: " << val << "\n";
    }
  } else {
  std::cout << "Writer Failed";
  }

auto iw (
  make_iwriter<internal_type>(
    input_functor()
  , begin(output_buffer) )
);

rv = iw (var, begin(output_buffer), end(output_buffer));
  if (rv == true)
  std::cout << "\nvalue: " << var;
  else
  std::cout << "error\n";

return 0;
}
