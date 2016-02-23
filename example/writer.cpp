#include "../src/qualified_typeid.cpp"
#include "../include/writer.hpp"

#include <iterator>
#include <map>
#include <vector>
#include <iostream>

using namespace typesystems;

// other typesystem
typedef float f_type;
typedef std::vector<f_type> outbuffer_t;
typedef outbuffer_t::iterator buffer_iter;
typedef std::back_insert_iterator <
  outbuffer_t > output_iter;

// typestem boundary
typedef writer_type <
  buffer_iter,output_iter > writer_t;

/* erase the type of writer used as
well. */
typedef std::map <
  qualified_typeinfo
, writer_base_type
> writer_map_notype;

/* useful when the iterators erase the
types used. */
typedef std::map <
  qualified_typeinfo, writer_t >
writer_map_type;

// free function re-writer
template <typename T, typename T2>
bool
function (
  T
, T
, T2 _out
){
_out = 99;
return true;
}

// functor re-writer
struct functor {
template <typename T, typename T2>
bool operator() (
  T
, T
, T2 _out
){
_out = 66;
return true;
}
};

outbuffer_t buffer;
outbuffer_t outbuffer;
writer_map_notype writer_map_typeless;
writer_map_type writer_map;

// application typesytem **************/
typedef int con_type;
typedef std::vector<con_type> buffer_t;

int main (){
/* types are added at typesystem
boundary. */
auto id = qualified_typeid<f_type>();

// add lamda re-writer
writer_map_typeless [id] = make_writer <
  buffer_iter, output_iter > (
  [] (
    buffer_iter _iter
  , buffer_iter _end
  , output_iter _output
  ) -> bool {
  _output = 4.21;
  return true;
  }
);

// add free re-writer
writer_map_typeless [id] = make_writer <
 buffer_iter, output_iter > (
  function<buffer_iter,output_iter> );

// add functor re-writer
writer_map_typeless [id] = make_writer <
  buffer_iter, output_iter > (
  functor() );

auto id2 = qualified_typeid<f_type>();

writer_map.insert ( std::make_pair (
  id2
, make_writer<buffer_iter,output_iter> (
  [] (
    buffer_iter _iter
  , buffer_iter _end
  , output_iter _output
  ) -> bool {
  _output = 5.14;
  return true;
  }
 )
));

writer_map.insert ( std::make_pair (
  id2
, make_writer<buffer_iter, output_iter>
  (function<buffer_iter,output_iter>)
));

writer_map.insert ( std::make_pair (
  id2
, make_writer<buffer_iter, output_iter>
  (functor())
));

auto writer = use_writer <
  buffer_iter, output_iter > (
  writer_map[id2] );

auto rv = writer (
  begin(outbuffer)
, end(outbuffer)
, std::back_inserter(outbuffer) );

  if (rv == true){
    if (outbuffer.empty()) {
    std::cout << "Output is Null\n";  
    } else {
    f_type val = outbuffer[0];
    std::cout << "Value is: " << val << "\n";
    }
  } else {
  std::cout << "Writer Failed";
  }

return 0;
}
