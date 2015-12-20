#include "../src/qualified_typeid.cpp"
#include "../include/writer.hpp"
#include "../include/typelist.hpp"

#include <iterator>
#include <map>
#include <vector>
#include <iostream>

using namespace typesystems;

typedef std::map<
  qualified_typeinfo
, iwriter_base_type > map_t;
typedef int con_type;
typedef float v_type;

int main (){
map_t iwriter;

std::vector<con_type> buffer;

iwriter [qualified_typeid<float>()]
= make_iwriter (
  new iwriter_function <
    v_type
  , std::vector<con_type>::iterator
  , map_t::iterator > (
  //  type        buffer iterator type                                    writer iterator type
  [] (float & _var, std::vector<con_type>::iterator, std::vector<con_type>::iterator, map_t::iterator, map_t::iterator) -> bool {
  _var = 4.21;
  return true;
  }
));

auto writer = use_iwriter <
  v_type
, std::vector<con_type>::iterator
, map_t::iterator>
(iwriter[qualified_typeid<v_type>()], qualified_typeid<v_type>());

v_type val (3.145);
  if ((*writer)(val, begin(buffer), end(buffer), begin(iwriter), end(iwriter))){
  std::cout << "A" << val << "\n";
  } else {
  std::cout << "B\n";
  }

v_type var = 0;
rewrite (
  var
, std::begin(buffer)
, std::end(buffer)
, std::begin(iwriter)
, std::end(iwriter)
, typelist<int>
);

std::cout << var << std::endl;

return 0;
}
