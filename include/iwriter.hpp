// write data to type buffer.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_IWRITER_HPP
#define TYPESYSTEMS_IWRITER_HPP

#include "typebuffer.hpp"
#include "bits/iwriter_base.hpp"
#include "bits/iwriter_container.hpp"

#if __cplusplus >= 201103L
#include <type_traits>
#define type_traits ::std

#else
#include <boost/type_traits.hpp>
#define type_traits ::boost
#endif

namespace typesystems {

/* rewriter_interface */
template <typename T>
class iwriter
  : public bits::iwriter_base {
public:
  typedef T type;

  typedef typename type_traits
  ::remove_cv<T>::type value_type;

  virtual
  ~iwriter(
  );

  void
  get(
    value_type &
  , typebuffer_container const &
  , iwriter_container const &
  ) const;

  bool
  empty(
    typebuffer_container const &
  , iwriter_container const &
  ) const;

protected:
  /* get_writer ctor */
  explicit
  iwriter(std::size_t _refs = 0);

  virtual void
  do_get(
    value_type &
  , typebuffer_container const &
  , iwriter_container const &
  ) const = 0;

  virtual bool
  do_empty(
    typebuffer_container const &
  , iwriter_container const &
  ) const = 0;
};

/* use_iwriter */
template <typename T>
iwriter<T> &
use_writer(
  iwriter_container const &
);

/* rewrite */
template <typename T>
void
rewrite(
  T &
, typebuffer_container const &
, iwriter_container const &
);

/* empty */
template <typename T>
bool
empty(
  typebuffer_container const &
, iwriter_container const &
);



} /* typesystems */
#include "bits/iwriter.tcc"
#include "bits/writer_exception.hpp"

#undef type_traits
#endif
