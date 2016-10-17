//

#ifndef TYPESYSTEMS_TYPE_MAP_TCC
#define TYPESYSTEMS_TYPE_MAP_TCC

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
  Tuple & _tup
)
: tup (_tup) {
}

/* get */
template <typename Key, typename Tuple, typename... Keys>
auto
get (
  type_map<Tuple, Keys...> & _con
)
-> decltype (
  std::get <get_type_index<Key, Keys...>::value >(_con.tup) )
{
return
std::get <
  get_type_index<Key, Keys...>::value >
(_con.tup);
}

/* get */
template <
  typename Key
, typename Tuple
, typename... Keys >
auto
get (
  type_map<Tuple, Keys...> && _con
)
-> decltype ( std::get <
  get_type_index<Key, Keys...>::value >
  (std::move(_con.tup))
)
{
return
std::get <
  get_type_index<Key, Keys...>::value >
(std::move(_con.tup));
}

/* get */ 
template <
  std::size_t Key
, typename Tuple
, typename... Keys >
auto
get (
  type_map<Tuple, Keys...> & _con
)
-> decltype (std::get<Key>(_con.tup))
{
return std::get<Key> (_con.tup);
}

/* get */ 
template <
  std::size_t Key
, typename Tuple
, typename... Keys >
auto
get (
  type_map<Tuple, Keys...> && _con
)
-> decltype
  (std::get<Key>(std::move(_con.tup)))
{
return
std::get<Key> (std::move(_con.tup));
}

/* get */
template <
  typename Key
, typename Tuple
, typename... Keys >
auto
get (
  type_map<Tuple, Keys...> const & _con
)
-> decltype ( std::get <
  get_type_index<Key, Keys...>::value >
(_con.tup)
)
{
return
std::get <
  get_type_index<Key, Keys...>::value >
(_con.tup);
}

/* get */ 
template <
  std::size_t Key
, typename Tuple
, typename... Keys >
auto
get (
  type_map<Tuple, Keys...> const & _con
)
-> decltype (std::get<Key>(_con.tup))
{
return std::get<Key> (_con.tup);
}

template <typename T, typename Tup>
struct type_map_has_type <T, type_map<Tup>>
: std::false_type {};

template <typename T, typename Tup, typename U, typename... Ts>
struct type_map_has_type <T, type_map<Tup, U, Ts...>>
: type_map_has_type<T, type_map<Tup, Ts...>> {};

template <typename T, typename Tup, typename... Ts>
struct type_map_has_type<T, type_map<Tup, T, Ts...>>
: std::true_type {};

} /* typesystems */
#endif

