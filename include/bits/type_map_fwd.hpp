//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_BITS_TYPE_MAP_FWD_HPP
#define TYPESYSTEMS_BITS_TYPE_MAP_FWD_HPP

namespace typesystems {

template <typename Tuple, typename... Key>
struct type_map;

/*template <typename T, typename Tuple, typename... Key>
std::size_t
index (
  type_map<Tuple, Keys...> const &
);

template <typename T, typename TypeMap>
struct type_map_has_type;*/

/* get */
/*template <
  typename Key_Value, typename Tuple, typename... Key >
auto
get (
  type_map<Tuple, Key...> & _con
)
-> decltype (
  std::get <get_type_index<Key_Value>::value >(_con.tup) );

/ * get * /
template <
  std::size_t Key_Value, typename Tuple, typename... Key >
auto
get (
  type_map<Tuple, Key...> & _con
)
-> decltype (std::get<Key_Value>(_con.tup));
*/

template <typename... Keys, typename Tuple>
type_map <Tuple, Keys...>
make_type_map (
  Tuple _tup
){
return type_map <Tuple, Keys...> (_tup);
}

} /* typesystems */
#endif
