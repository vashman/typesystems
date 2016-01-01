#include "../src/qualified_typeid.cpp"
#include "../include/writer.hpp"
#include "../include/typelist.hpp"

#include <iterator>
#include <map>
#include <vector>
#include <iostream>

using namespace typesystems;

typedef int con_type;
typedef float v_type;

typedef std::vector<con_type> buffer_t;
typedef std::vector<v_type> outbuffer_t;

typedef buffer_t::iterator buff_iter;
typedef std::back_insert_iterator <
  outbuffer_t > out_iter;

typedef writer_type<buff_iter,out_iter>
writer_t;

typedef std::map <
  qualified_typeinfo
, writer_base_type > map_t;

typedef std::map <
  qualified_typeinfo, writer_t > map_t2;

typedef int con_type;
typedef float v_type;

template <typename T, typename T2>
qualified_typeinfo
function (T, T, T2 _out){
_out = 99;
return qualified_typeid<float>();
}

struct functor {
template <typename T, typename T2>
qualified_typeinfo operator() (
  T, T, T2 _out
){
_out = 66;
return qualified_typeid<float>();
}
};

int main (){
map_t writer_map;
map_t2 kwriter_map;
buffer_t buffer;
outbuffer_t outbuffer;

writer_map [qualified_typeid<float>()]
= make_writer <buff_iter, out_iter > (
  [] (
    std::vector<con_type>::iterator _iter
  , std::vector<con_type>::iterator _end
  , out_iter _output
  ) -> qualified_typeinfo {
  _output = 4.21;
  return qualified_typeid<float>();
  }
);

writer_map [qualified_typeid<v_type>()]
= make_writer <buff_iter, out_iter > (
  function<buff_iter,out_iter>
);

writer_map [qualified_typeid<v_type>()]
= make_writer <buff_iter, out_iter > (
functor()
);

kwriter_map.insert(
std::make_pair(
  qualified_typeid<v_type>()
, make_writer<buff_iter, out_iter> (
  [] (
    std::vector<con_type>::iterator _iter
  , std::vector<con_type>::iterator _end
  , out_iter _output
  ) -> qualified_typeinfo {
  _output = 5.14;
  return qualified_typeid<v_type>();
  }
 )
));

kwriter_map.insert(
std::make_pair(
  qualified_typeid<v_type>()
, make_writer<buff_iter, out_iter> (function<buff_iter,out_iter>)
));

kwriter_map.insert(
std::make_pair(
  qualified_typeid<v_type>()
, make_writer<buff_iter, out_iter> (functor())
));

auto writer = use_writer <buff_iter, out_iter>
(writer_map[qualified_typeid<v_type>()]);

auto rv = writer(begin(buffer), end(buffer), std::back_inserter(outbuffer));

  if (rv == qualified_typeid<v_type>()){
    if (outbuffer.empty()) {
    std::cout << "Output is Null\n";  
    } else {
    v_type val = outbuffer[0];
    std::cout << "Value is: " << val << "\n";
    }
  } else {
  std::cout << "Writer Failed";
  }

return 0;
}
