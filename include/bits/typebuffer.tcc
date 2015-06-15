// typebuffer template implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_BITS_TYPEBUFFER_TCC
#define TYPESYSTEMS_BITS_TYPEBUFFER_TCC

namespace typesystems {

/* dtor */
template <typename T>
typebuffer<T>::~typebuffer (
){
}

/* pop */
template <typename T>
void
typebuffer<T>::pop(
){
this->do_pop();
}

/* next */
template <typename T>
typename typebuffer<T>::value_type
typebuffer<T>::next(
){
typename typebuffer<T>::value_type
value(this->front());
this->pop();
return value;
}

/* top */
template <typename T>
typename typebuffer<T>::value_type &
typebuffer<T>::front(
){
return this->do_front();
}

/* back */
template <typename T>
typename typebuffer<T>::value_type &
typebuffer<T>::back(
){
return this->do_back();
}

/* push */
template <typename T>
void
typebuffer<T>::push(
  typename typebuffer<T>
  ::value_type const & _var
){
this->do_push(_var);
}

#if __cplusplus >= 201103L
/* typebuffer_interface push */
template <typename T>
void
typebuffer<T>::push(
  typename typebuffer<T>::value_type &&
  _var
){
this->do_push(_var);
}
#endif

/* set_typebuffer */
template <typename T, typename Buffer>
void
set_typebuffer(
  typebuffer_container & _buffer
){
_buffer.c[
  explicit_typeid<T>::raw_typeid()
] = new Buffer();
}

/* clear */
template <typename T>
void
clear(
  typebuffer_container const & _c
){
  if (! has_typebuffer<T>(_c)){
  throw std::bad_cast();
  }
(_c.c.at(
  explicit_typeid<T>::raw_typeid())
)->clear();
}

/* has_typebuffer */
template <typename T>
bool
has_typebuffer(
  typebuffer_container const & _unit
){
return (
  _unit.c.find(
    explicit_typeid<T>::raw_typeid()
  )
!=
  _unit.c.end()
);
}

/* use_typebuffer */
template <typename T>
typebuffer<T> &
use_typebuffer(
  typebuffer_container const & _buffer
){
bits::typebuffer_base * buff = nullptr;
buff = _buffer.c.at(
  explicit_typeid<T>::raw_typeid()
);
  if (buff != nullptr){
  return
  static_cast<typebuffer<T> &>(* buff);
  }
throw std::bad_cast();
}

/* empty */
template <typename T>
bool
empty(
  typebuffer_container const & _buffer
){
return
(
_buffer.c.at(explicit_typeid<T>
::raw_typeid())
)->empty();
}

} /* typesystems */
#endif
