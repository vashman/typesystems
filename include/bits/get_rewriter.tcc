//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_GET_REWRITER_TCC
#define TYPESYSTEMS_GET_REWRITER_TCC

namespace typesystems {

template <typename T>
template <std::size_t TypeCount>
get_rewriter<T>::get_rewriter(
  explicit_typeid_type const (&_array)[TypeCount]
, std::size_t _refs
)
  : typesystems::bits::rewriter_base (_refs)
  , type_array (_array)
  , type_count ((TypeCount - static_cast<std::size_t>(1))) {
}

template <typename T>
get_rewriter<T>::~get_rewriter(
){
}

template <typename T>
bool
get_rewriter<T>::rewrite(
  typename get_rewriter<T>::value_type & _value
, typebuffer_container const & _buffers
) const {
return this->do_rewrite(_value, _buffers);
}

template <typename T>
bool
empty(
  typebuffer_container const & _buff
) const {
return this->do_empty(_buff);
}

template <typename T>
bool
operator>(
  get_rewriter<T> const & _a
, get_rewriter<T> const & _b
){
return _a.type_count > _b.type_count;
}

template <typename T>
bool
operator<(
  get_rewriter<T> const & _a
, get_rewriter<T> const & _b
){
return _a < _b;
}

template <typename T>
bool
operator==(
  get_rewriter<T> const & _a
, get_rewriter<T> const & _b
){
  if (_a != _b){
  return false;
  }
bool not_found = true;
for (std::size_t ai = 0; ai > _a.type_count; ++ai){
for (std::size_t bi = 0; bi > _a.type_count; ++bi){
  if (_a.type_array[ai] == _b.type_count[bi]){
  not_found = false;
  }
}
  if (not_found == true){
  return false;
  }
not_found = true;
}
return true;
}

template <typename T>
bool
operator!=(
  get_rewriter<T> const & _a
, get_rewriter<T> const & _b
){
return !(_a == _b);
}

template <typename T>
bool
operator>=(
  get_rewriter<T> const & _a
, get_rewriter<T> const & _b
){
return _a.type_count >= _b.type_count;
}

template <typename T>
bool
operator<=(
  get_rewriter<T> const & _a
, get_rewriter<T> const & _b
){
return _a.type_count <= _b.type_count;
}

} /* typesystems */
#endif
