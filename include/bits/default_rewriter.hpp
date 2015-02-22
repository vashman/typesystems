// Default rewriters that simply input/output the type.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_DEFAULT_REWRITER_HPP
#define TYPESYSTEMS_DEFAULT_REWRITER_HPP

#include "../put_rewriter.hpp"
#include "../get_rewriter.hpp"

namespace typesystems {
namespace bits {

template <typename T>
class default_rewriter_put : public typesystems::put_rewriter<T>{
public:
  explicit
  default_rewriter_put(
    std::size_t _refs = 0
  );

private:
  virtual bool
  do_rewrite(
    T const &
  , typebuffer_container const &
  ) const;

  static typesystems::explicit_typeid_type const array[1];
};

template <typename T>
class default_rewriter_get : public typesystems::get_rewriter<T>{
public:
  explicit
  default_rewriter_get(
    std::size_t _refs = 0
  );

private:
  virtual bool
  do_rewrite(
    T &
  , typebuffer_container const &
  ) const;

  virtual bool
  do_empty(
    typebuffer_container const &
  ) const;

  static typesystems::explicit_typeid_type const array[1];
};

template <typename T>
typesystems::explicit_typeid_type const default_rewriter_put<T>::array[]
  ={ typesystems::explicit_typeid<T>::raw_typeid() };

template <typename T>
typesystems::explicit_typeid_type const default_rewriter_get<T>::array[]
  ={ typesystems::explicit_typeid<T>::raw_typeid() };

/* default_rewriter_put ctor */
template <typename T>
default_rewriter_put<T>::default_rewriter_put(
  std::size_t _refs
)
 : typesystems::put_rewriter<T>(array, 0, _refs) {
}

/* default_rewriter_get ctor */
template <typename T>
default_rewriter_get<T>::default_rewriter_get(
  std::size_t _refs
)
 : typesystems::get_rewriter<T>(array, _refs){
}

/* default_rewrite_put do_rewrite */
template <typename T>
bool
default_rewriter_put<T>::do_rewrite(
  T const & _value
, typebuffer_container const & _buffer
) const {
  if (has_typebuffer<T>(_buffer)){
  typebuffer_interface<T> & _buff = use_typebuffer<T>(_buffer);
  _buff.push(_value);
  return true;
  }
return false;
}

/* default_rewrite_get do_rewrite */
template <typename T>
bool
default_rewriter_get<T>::do_rewrite(
  T & _value
, typebuffer_container const & _buffer
) const {
  if (has_typebuffer<T>(_buffer)){
  typebuffer_interface<T> & _buff = use_typebuffer<T>(_buffer);
  _value = _buff.next();
  return true;
  }
return false;
}

template <typename T>
bool
default_rewriter_get<T>::do_empty(
  typebuffer_container const & _buffer
) const {
return (use_typebuffer<T>(_buffer)).empty();
}

} /* bits */ } /* typesystems */
#endif
