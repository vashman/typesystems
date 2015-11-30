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
template <
  typename T
, typename InputIter
, typename Typelist
>
iwriter<T,InputIter,Typelist>::iwriter (
  std::size_t _ref
)
: bits::iwriter_base (_ref) {
}

/* dtor */
template <
  typename T
, typename InputIter
, typename Typelist
>
iwriter<T,InputIter,Typelist>::~iwriter(
){
}

/* read */
template <
  typename T
, typename InputIter
, typename Typelist
>
void
iwriter<T,InputIter,Typelist>::get (
  typename iwriter<T,InputIter,Typelist>
  ::value_type & _value
, InputIter _iter
, Typelist const & _typelist
, iwriter_container const & _writer
) const {
this->do_get(
  _value
, _iter
, _typelist
, _writer
);
}

/* empty */
template <
  typename T
, typename InputIter
, typename Typelist
>
bool
iwriter<T,InputIter,Typelist>::empty (
  InputIter _iter
, Typelist const & _typelist
, iwriter_container const & _writer
) const {
return this->
do_empty(_iter, _typelist, _writer);
}

/* rewrite */
template <
  typename T
, typename InputIter
, typename Typelist
>
void
rewrite(
  T & _var
, InputIter _iter
, InputIter _end
, Typelist _type
, Typelist _type_end
, iwriter_container const & _writer
){
  if (
    _type_end
  !=
    find (
      _type
    , _type_end
    , explicit_typeid<T>
    )
  ){
  _var = *_iter;
  } else {
    if (! has_writer<T>(_writer)){
    throw
    std::runtime_error("No Buffer!");
    }
  auto& writer = use_writer<T>(_writer);
  writer.get(_var, _iter, _end, _writer);
  }
}

/* empty */
template <
  typename T
, typename InputIter
, typename Typelist
>
bool
empty (
  InputIter _iter
, InputIter _end
, iwriter_container const & _writer
){
  /* if another writer is present for
     the type, check if that writer is
     empty.
  */
  if (has_writer<T>(_writer)){
  auto &
  writer = use_writer<T>(_writer);
  return writer.empty(_iter, _writer);
  }
/* The iterator containes the type in
   question directly, so query it to see
   if there are any.
*/
return (_iter != _end);
}

/* use_iwriter */
template <
  typename T
, typename InputIter
, typename Typelist
>
iwriter<T,InputIter,Typelist> &
use_writer(
  iwriter_container const & _con
){
bits::iwriter_base * ptr = nullptr;
ptr = _con.at (
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
