// Write to type buffer.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_OWRITER_HPP
#define TYPESYSTEMS_OWRITER_HPP

#include <type_traits>
#include "bits/owriter_base.hpp"
#include "bits/owriter_container.hpp"

namespace typesystems {

/* rewriter_interface */
template <typename T, typename Output>
class owriter
  : public bits::owriter_base {
public:
  typedef T type;

  typedef typename
  std::remove_cv<T>::type value_type;

  virtual
  ~owriter();

  void
  put(
    value_type const &
  , owriter_container const &
  , Output &
  ) const;

protected:
  /* ctor */
  owriter( 
    std::size_t _refs = 0
 );

  virtual void
  do_put(
    value_type const &
  , owriter_container const &
  , Output &
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

#endif
