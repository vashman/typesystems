//

#ifndef TYPESYSTEMS_TYPE_MAP_TCC
#define TYPESYSTEMS_TYPE_MAP_TCC

#include "get.hpp"

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

/* ctor begin at index */
template <typename T, typename... Ts>
  type_map<T,Ts...>
::iterator
::iterator (
  type_map<T,Ts...> * _con
, int _index
)
: con (_con)
, index (_index) {
}

/* iterator begin */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
type_map<T,Ts...>::begin (){
return typename type_map<T,Ts...>
::iterator(*this);
}

/* iterator end */
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
#if __cplusplus > 201103L
std::get<1> (
std::get<std::tuple<Key,T>>(_con.map) );
#elif __cplusplus == 201103L
std::get<1> (
bits::get<std::tuple<Key,T>>(_con.map));
#endif 
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
  type_map<T,Ts...>::iterator
::operator ++ (){
typename type_map<T,Ts...>
::iterator temp (*this);
++this->index;
return temp;
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator &
  type_map<T,Ts...>::iterator
::operator ++ (
  int const
){
++this->index;
return *this;
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
  type_map<T,Ts...>::iterator
::operator -- (
){
typename type_map<T,Ts...>
::iterator temp (*this);
--this->index;
return temp;
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator &
  type_map<T,Ts...>::iterator
::operator -- (
  int const
){
--this->index;
return *this;
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
  type_map<T,Ts...>::iterator
::operator + (
  int _value
) const {
return typename type_map<T,Ts...>
::iterator (
  this->con, this->index + _value );
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
  type_map<T,Ts...>::iterator
::operator + (
  typename type_map<T,Ts...>
  ::iterator const & _rhs
) const {
return typename type_map<T,Ts...>
::iterator (
 this->con, this->index + _rhs.index );
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
  type_map<T,Ts...>::iterator
::operator - (
  int _value
) const {
return typename type_map<T,Ts...>
::iterator (
  this->con, this->index - _value );
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator
  type_map<T,Ts...>::iterator
::operator - (
  typename type_map<T,Ts...>
  ::iterator const & _rhs
) const {
return typename type_map<T,Ts...>
::iterator (
  this->con, this->index - _rhs.index );
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator &
  type_map<T,Ts...>::iterator
::operator += (
  int const _value
){
this->index += _value;
return *this;
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator &
  type_map<T,Ts...>::iterator
::operator += (
 typename type_map<T,Ts...>
 ::iterator const & _rhs
){
this->index += _rhs.index;
return *this;
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator &
  type_map<T,Ts...>::iterator
::operator -= (
  int const _value
){
this->index -= _value;
return *this;
}

/* iterator */
template <typename T, typename... Ts>
typename type_map<T,Ts...>::iterator &
  type_map<T,Ts...>::iterator
::operator -= (
 typename type_map<T,Ts...>
 ::iterator const & _rhs
){
this->index -= _rhs.index;
return *this;
}

/* iterator */
template <typename T, typename... Ts>
bool
  type_map<T,Ts...>::iterator
::operator < (
 typename type_map<T,Ts...>
 ::iterator const & _rhs
) const {
return (this->index < _rhs.index);
}

/* iterator */
template <typename T, typename... Ts>
bool
  type_map<T,Ts...>::iterator
::operator > (
 typename type_map<T,Ts...>
 ::iterator const & _rhs
) const {
return (this->index > _rhs.index);
}

/* iterator */
template <typename T, typename... Ts>
bool
  type_map<T,Ts...>::iterator
::operator <= (
 typename type_map<T,Ts...>
 ::iterator const & _rhs
) const {
return (this->index <= _rhs.index);
}

/* iterator */
template <typename T, typename... Ts>
bool
  type_map<T,Ts...>::iterator
::operator >= (
 typename type_map<T,Ts...>
 ::iterator const & _rhs
) const {
return (this->index >= _rhs.index);
}

/* iterator */
template <typename T, typename... Ts>
bool
  type_map<T,Ts...>::iterator
::operator == (
 typename type_map<T,Ts...>
 ::iterator const & _rhs
) const {
return (this->index == _rhs.index);
}

/* iterator */
template <typename T, typename... Ts>
bool
  type_map<T,Ts...>::iterator
::operator != (
 typename type_map<T,Ts...>
 ::iterator const & _rhs
) const {
return (this->index != _rhs.index);
}

template <typename T, typename... Ts>
T &
  type_map<T,Ts...>::iterator
::operator * (){
return bits::check_tuple <
  sizeof...(Ts) - 1, T, Ts... >
::get(this->index,this->con->map);
}

template <typename T, typename... Ts>
T &
  type_map<T,Ts...>::iterator
::operator [] (
  int _index
){
this->index = _index;
return bits::check_tuple <
  sizeof...(Ts) - 1, T, Ts... >
::get(this->index,this->con->map);
}

template <typename T, typename... Ts>
T *
  type_map<T,Ts...>::iterator
::operator -> () {
return & bits::check_tuple <
  sizeof...(Ts) - 1, T, Ts... >
::get(this->index,this->con->map);
}

template <
  int N, typename T, typename... Ts >
T&
bits::check_tuple<N,T,Ts...>::get (
  int const _index
, std::tuple<std::tuple<Ts,T>...> & _map
){
  if (_index == N) {
  return std::get<1>(std::get<N>(_map));
  }

return bits::check_tuple<N-1,T,Ts...>
::get(_index,_map);
}

template <typename T, typename... Ts>
T&
bits::check_tuple<0,T,Ts...>::get (
  int const _index
, std::tuple<std::tuple<Ts,T>...> & _map
){
  if (_index != 0)
  throw "out of range";
return std::get<1>(std::get<0>(_map));
}

} /* typesystems */
#endif

