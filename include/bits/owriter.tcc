// put_rewriter template implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_OWRITER_TCC
#define TYPESYSTEMS_OWRITER_TCC

namespace typesystems {

/* put_rewriter ctor */
template <typename T>
owriter<T>::owriter(
  std::size_t _ref
)
: bits::owriter_base (_ref) {
}

template <typename T>
owriter<T>::~owriter(
){
}

/* rewriter rewrite to other type */
template <typename T>
void
owriter<T>::put(
  owriter<T>::value_type const &
  _value
, typebuffer_container const & _buffer
, owriter_container const & _writer
) const {
this->do_put(_value, _buffer, _writer);
}

template <typename T>
void
rewrite(
  T const & _var
, typebuffer_container const & _buffer
, owriter_container const & _writer
){
  if (has_typebuffer<T>(_buffer)){
  auto &
  buff = use_typebuffer<T>(_buffer);
  buff.push(_var);
  } else {
    if (has_writer<T>(_writer)){
    auto &
    writer = use_writer<T>(_writer);
    writer.put(_var, _buffer, _writer);
    } else {
    throw "no buffer!";
    }
  }
}

/* use_writer */
template <typename T>
owriter<T> &
use_writer(
  owriter_container const & _con
){
bits::owriter_base * ptr = nullptr;
ptr = _con.at(
  explicit_typeid<T>::raw_typeid()
);
  if (ptr != nullptr){
  return
  static_cast<owriter<T> &>(*ptr);
  }
throw std::bad_cast();
}

} /* typesystems */
#endif
