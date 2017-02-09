//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_BITS_TYPE_MAP_TCC
#define TYPESYSTEMS_BITS_TYPE_MAP_TCC

// std::forward
#include <utility>
// std::get
#include <tuple>
// get_type_index
#include "../type_traits.hpp"

namespace typesystems {

template <typename Tuple, typename... Keys>
template <typename... Ts>
type_map<Tuple, Keys...>::type_map (
  Ts... _ts
)
: tup (_ts...) {
}

template <typename Tuple, typename... Keys>
type_map<Tuple, Keys...>::type_map (
  Tuple && _tup
)
: tup (std::forward<Tuple>(_tup)) {
}

template <typename Tuple, typename... Keys>
type_map<Tuple, Keys...>::operator Tuple (
){
return this->tup;
}

/* get */
template <typename Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> & _con
)
-> decltype (
  std::get <get_type_index<Key, Keys...>::value >(_con.tup)
){
using std::get;

return get <get_type_index<Key, Keys...>::value> (_con.tup);
}

/* get */
template <typename Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> && _con
)
-> decltype ( std::get <
  get_type_index<Key, Keys...>::value >
  (std::move(_con.tup))
){
using std::get;
using std::move;

return
get<get_type_index<Key, Keys...>::value >(move(_con.tup));
}

/* get */ 
template <std::size_t Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> & _con
)
-> decltype (std::get<Key>(_con.tup))
{
using std::get;

return get<Key> (_con.tup);
}

/* get */ 
template <std::size_t Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> && _con
)
-> decltype (std::get<Key>(std::move(_con.tup)))
{
using std::get;

return get<Key> (std::move(_con.tup));
}

/* get */
template <typename Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> const & _con
)
-> decltype ( std::get <get_type_index<Key, Keys...>::value>
  (_con.tup))
{
using std::get;

return get <get_type_index<Key, Keys...>::value>(_con.tup);
}

/* get */ 
template <std::size_t Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> const & _con
)
-> decltype (std::get<Key>(_con.tup))
{
using std::get;

return get<Key> (_con.tup);
}

template <
  typename Tuple1
, typename Tuple2
, typename... Keys1
, typename... Keys2 >
auto
type_map_cat (
  type_map <Tuple1, Keys1...> _type_map1
, type_map <Tuple2, Keys2...> _type_map2
)
-> type_map<decltype(tuple_cat (static_cast<Tuple1>(_type_map1), static_cast<Tuple2>(_type_map2))), Keys1..., Keys2...>
{
using std::tuple_cat;

return type_map<decltype(tuple_cat (static_cast<Tuple1>(_type_map1), static_cast<Tuple2>(_type_map2))), Keys1..., Keys2...> {
  tuple_cat (
  static_cast<Tuple1>(_type_map1)
, static_cast<Tuple2>(_type_map2)
)};
}

} /* typesystems */
#endif

