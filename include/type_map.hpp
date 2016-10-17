//

#ifndef TYPESYSTEMS_TYPE_MAP_HPP
#define TYPESYSTEMS_TYPE_MAP_HPP

#include <tuple>
#include <iterator>
#include "type_traits.hpp"

namespace typesystems {

template <typename Tuple, typename... Key>
struct type_map;

template <typename T, typename TypeMap>
struct type_map_has_type;

/* get */
/*template <
  typename Key_Value
, typename Tuple
, typename... Key >
auto
get (
  type_map<Tuple, Key...> & _con
)
-> decltype (
  std::get <
    get_type_index<Key_Value>::value >
  (_con.tup)
);

/ * get * /
template <
  std::size_t Key_Value
, typename Tuple
, typename... Key >
auto
get (
  type_map<Tuple, Key...> & _con
)
-> decltype (
  std::get<Key_Value>(_con.tup)
);*/

/* map concat */
/*template <typename... Map>
type_map<>
map_cat (
  Map&&... _maps
){
return make_type_map <>
(std::tuple_cat(_maps.tuple...);
}*/

/* type map */
template <typename Tuple, typename... Key>
struct type_map {

Tuple tup;

public:

type_map () = default;

template <typename... Ts>
type_map (
  Ts...
);

explicit
type_map (
  Tuple &
);

type_map (
  type_map<Tuple, Key...> const &
) = default;

type_map (
  type_map<Tuple, Key...> &&
) = default;

~type_map () = default;

type_map<Tuple, Key...> &
operator = (
  type_map<Tuple, Key...> const &
) = default;

type_map<Tuple, Key...> &
operator = (
  type_map<Tuple, Key...> &&
) = default;

}; /* type_map */

template <typename... Keys, typename Tuple>
type_map <Tuple, Keys...>
make_type_map (
  Tuple _tup
){
return type_map <Tuple, Keys...> (_tup);
}

} /* typesystems */
#include "./bits/type_map.tcc"
#endif

