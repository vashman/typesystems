//

#ifndef TYPESYSTEMS_TYPE_MAP_TCC
#define TYPESYSTEMS_TYPE_MAP_TCC

namespace typesystems {

/* ctor begin */
template <typename T, typename... Ts>
  type_map<T,Ts...>
::iterator
::iterator (
  type_map<T,Ts...> & _con
)
: con (& _con)
, index (0) {
}

/* ctor end */
template <typename T, typename... Ts>
  type_map<T,Ts...>
::iterator
::iterator ()
: con (nullptr)
, index (sizeof...(Ts)) {
}

template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
type_map<T,Ts...>::begin (){
return typename type_map<T,Ts...>
::iterator(*this);
}

template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
type_map<T,Ts...>::end (){
return typename type_map<T,Ts...>
::iterator();
}

/* begin */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
begin (
  type_map<T,Ts...> & _con
){
return _con.begin();
}

/* end */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
end (
  type_map<T,Ts...> const &
){
return typename
type_map<T,Ts...>::iterator();
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

/* iterator */
/*template <typename T, typename... Ts>
type_map<T,Ts...>::iterator &
operator ++ (){

return *this;
}*/

template <typename T, typename... Ts>
T&
  type_map<T,Ts...>
::iterator
::operator * (){
return bits::check_tuple <
  sizeof...(Ts) - 1, T, Ts... >
::get(this->index,*this->con);
}

template <
  int N, typename T, typename... Ts >
T&
bits::check_tuple<N,T,Ts...>::get (
  int const & _index
, std::tuple<std::tuple<Ts,T>...> & _map
){
  if (_index == N)
  return get<1>(get<N>(_map));

return bits::check_tuple<N-1,T,Ts...>
::get(_index,_map);
}

template <typename T, typename... Ts>
T&
bits::check_tuple<0,T,Ts...>::get (
  int const & _index
, std::tuple<std::tuple<Ts,T>...> & _map
){
  if (_index != 0)
  throw "out of range";
return get<1>(get<0>(_map));
}

} /* typesystems */
#endif

