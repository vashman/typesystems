// Write to type buffer.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_OWRITER_HPP
#define TYPESYSTEMS_OWRITER_HPP

#include "typebuffer.hpp"
#include "bits/owriter_base.hpp"
#include "bits/owriter_container.hpp"

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
class owriter
  : public bits::owriter_base {
public:
  typedef T type;

  typedef typename
  type_traits::remove_cv<T>::type
  value_type;

  virtual
  ~owriter(
  );

  void
  put(
    value_type const &
  , typebuffer_container const &
  , owriter_container const &
  ) const;

protected:
  /* ctor */
  owriter( 
    std::size_t _refs = 0
 );

  virtual void
  do_put(
    value_type const &
  , typebuffer_container const &
  , owriter_container const &
  ) const = 0;
};

/* use_writer */
template <typename T>
owriter<T> &
use_writer(
  owriter_container const &
);

/* rewrite */
template <typename T>
void
rewrite(
  T const &
, typebuffer_container const &
, owriter_container const &
);

} /* typesystems */
#include "bits/owriter.tcc"
#include "bits/writer_exception.hpp"

#undef type_traits
#endif
