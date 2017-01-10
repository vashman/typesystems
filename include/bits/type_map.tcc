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

/* get */
template <typename Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> & _con
)
-> decltype (
  std::get <get_type_index<Key, Keys...>::value >(_con.tup)
){
return
std::get <get_type_index<Key, Keys...>::value> (_con.tup);
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
return std::get <get_type_index<Key, Keys...>::value >
(std::move(_con.tup));
}

/* get */ 
template <std::size_t Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> & _con
)
-> decltype (std::get<Key>(_con.tup))
{
return std::get<Key> (_con.tup);
}

/* get */ 
template <std::size_t Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> && _con
)
-> decltype (std::get<Key>(std::move(_con.tup)))
{
return std::get<Key> (std::move(_con.tup));
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
return
std::get <get_type_index<Key, Keys...>::value>(_con.tup);
}

/* get */ 
template <std::size_t Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> const & _con
)
-> decltype (std::get<Key>(_con.tup))
{
return std::get<Key> (_con.tup);
}

/*template <typename T, typename Tup>
struct type_map_has_type <T, type_map<Tup>>
: std::false_type {};

template <
  typename T, typename Tup, typename U, typename... Ts >
struct type_map_has_type <T, type_map<Tup, U, Ts...>>
: type_map_has_type<T, type_map<Tup, Ts...>> {};

template <typename T, typename Tup, typename... Ts>
struct type_map_has_type<T, type_map<Tup, T, Ts...>>
: std::true_type {};
*/
/* map concat */
/*template <typename... Map>
type_map<>
map_cat (
  Map&&... _maps
){
return make_type_map <>
(std::tuple_cat(_maps.tuple...);
}*/

} /* typesystems */
#endif

