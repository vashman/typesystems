//

#ifndef TYPESYSTEMS_TYPE_MAP_TCC
#define TYPESYSTEMS_TYPE_MAP_TCC

namespace typesystems {

template <
    typename Tuple
  , typename... Keys >
template <typename... Ts>
  type_map<Tuple, Keys...>
::type_map (
  Ts... _ts
)
: tup (_ts...) {
/*static_assert (
  sizeof...(Us) == sizeof...(Ts)
, "" );*/
}

template <
    typename Tuple
  , typename... Keys >
  type_map<Tuple, Keys...>
::type_map (
  Tuple & _tup
)
: tup (_tup) {
}

/* get */
template <
  typename Key
, typename Tuple
, typename... Keys >
auto
get (
  type_map<Tuple, Keys...> & _con
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
  type_map<Tuple, Keys...> & _con
)
-> decltype (std::get<Key>(_con.tup))
{
return std::get<Key> (_con.tup);
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

} /* typesystems */
#endif

