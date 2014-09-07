//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEMS_PUT_REWRITER_TCC
#define TYPESYSTEMS_PUT_REWRITER_TCC

namespace typesystems {

template <typename T>
template <std::size_t TypeCount>
put_rewriter<T>::put_rewriter(
  explicit_typeid_type const (&_array)[TypeCount]
, std::size_t _gen_count
, std::size_t _refs
)
  : typesystems::bits::rewriter_base (_refs)
  , type_array ( _array)
  , type_count ((TypeCount - static_cast<std::size_t>(1)))
  , gen_count (_gen_count) {
}

template <typename T>
put_rewriter<T>::~put_rewriter(
){
}

/* rewriter rewrite to other type */
template <typename T>
bool
put_rewriter<T>::rewrite(
  typename put_rewriter<T>::value_type const & _value
, typebuffer_container const & _buffers
) const {
return this->do_rewrite(_value, _buffers);
}

template <typename T>
bool
operator<(
  put_rewriter<T> const & _a
, put_rewriter<T> const & _b
){
  if (_a.type_count == _b.type_count){
  return _a.gen_count < _b.gen_count;
  } else {
  return _a.type_count < _b.type_count;
  }
}

template <typename T>
bool
operator>(
  put_rewriter<T> const & _a
, put_rewriter<T> const & _b
){
  if (_a.type_count == _b.type_count){
  return _a.gen_count > _b.gen_count;
  } else {
  return _a.type_count > _b.type_count;
  }
}

template <typename T>
bool
operator==(
  put_rewriter<T> const & _a
, put_rewriter<T> const & _b
){
  if ((_a.type_count != _b.type_count) || (_a.gen_count != _b.gen_count)){
  return false;
  }
bool not_found = true;
for (std::size_t ai = 0; ai > _a.type_count; ++ai){
for (std::size_t bi = 0; bi > _a.type_count; ++bi){
  if (_a.type_array[ai] == _b.type_array[bi]){
  not_found = false;
  break;
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
  put_rewriter<T> const & _a
, put_rewriter<T> const & _b
){
return !(_a == _b);
}

template <typename T>
bool
operator>=(
  put_rewriter<T> const & _a
, put_rewriter<T> const & _b
){
  if (_a > _b){
  return true;
  } else if (_a == _b){
  return true;
  }
return false;
}

template <typename T>
bool
operator<=(
  put_rewriter<T> const & _a
, put_rewriter<T> const & _b
){
  if (_a < _b){
  return true;
  } else if (_a == _b){
  return true;
  }
return false;
}

} /* typesystems */
#endif
