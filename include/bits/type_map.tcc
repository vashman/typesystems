//

#ifndef TYPESYSTEMS_TYPE_MAP_TCC
#define TYPESYSTEMS_TYPE_MAP_TCC

namespace typesystems {

/* ctor begin */
template <typename T, typename... Ts>
  type_map_iterator<T,Ts...>
::type_map_iterator(
  type_map<T,Ts...> & _con
)
: con (&_con)
, index (0) {
}

/* ctor end */
template <typename T, typename... Ts>
  type_map_iterator<T,Ts...>
::type_map_iterator()
: con (nullptr)
, index (sizeof...(Ts)) {
}

template <typename T, typename... Ts>
type_map_iterator<T,Ts...>
begin (
  type_map<T,Ts...> & _con
){
return type_map_iterator<T,Ts...>(_con);
}

template <typename T, typename... Ts>
type_map_iterator<T,Ts...>
end (
  type_map<T,Ts...> const &
){
return type_map_iterator<T,Ts...>();
}

/* get */
template <
  typename Key
, typename T
, typename... Ts >
T&
get (
  type_map<T,Ts...> & _con
){
return
std::get<1> (
std::get<std::tuple<Key,T>>(_con) );
}

} /* typesystems */
#endif
