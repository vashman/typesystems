// get_writer template implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_IWRITER_TCC
#define TYPESYSTEMS_IWRITER_TCC

#include <stdexcept>

namespace typesystems {

/* ctor */
template <typename T>
iwriter<T>::iwriter(
  std::size_t _ref
)
: bits::iwriter_base (_ref) {
}

/* dtor */
template <typename T>
iwriter<T>::~iwriter(){
}

/* read */
template <typename T>
void
iwriter<T>::get(
  typename iwriter<T>::value_type &
   _value
, typebuffer_container const & _buffer
, iwriter_container const & _writer
) const {
this->do_get(_value, _buffer, _writer);
}

/* empty */
template <typename T>
bool
iwriter<T>::empty(
  typebuffer_container const & _buffer
, iwriter_container const & _writer
) const {
return this->do_empty(_buffer, _writer);
}

/* rewrite */
template <typename T>
void
rewrite(
  T & _var
, typebuffer_container const & _buffer
, iwriter_container const & _writer
){
  if (has_typebuffer<T>(_buffer)){
  auto &
  buff = use_typebuffer<T>(_buffer);
  _var = buff.next();
  } else {
    if (has_writer<T>(_writer)){
    auto &
    writer = use_writer<T>(_writer);
    writer.get(_var, _buffer, _writer);
    } else {
    throw
    std::runtime_error("No Buffer!");
    }
  }
}

/* empty */
template <typename T>
bool
empty(
  typebuffer_container const & _buffer
, iwriter_container const & _writer
){
  if (has_writer<T>(_writer)){
  auto &
  writer = use_writer<T>(_writer);
  return writer.empty(_buffer, _writer);
  }
return empty<T>(_buffer);
}

/* use_iwriter */
template <typename T>
iwriter<T> &
use_writer(
  iwriter_container const & _con
){
bits::iwriter_base * ptr = nullptr;
ptr = _con.at(
  explicit_typeid<T>::raw_typeid()
);
  if (ptr != nullptr){
  return
  static_cast<iwriter<T> &>(*ptr);
  }
throw std::bad_cast();
}

} /* typesystems */
#endif
