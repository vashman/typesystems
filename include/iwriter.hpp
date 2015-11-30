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
#include <type_traits>

namespace typesystems {

/* rewriter_interface */
template <
  typename T
, typename InputIter
, typename Typelist
>
class iwriter
  : public bits::iwriter_base {
public:

typedef T type;

typedef typename std
::remove_cv<T>::type value_type;

/* dtor */
virtual
~iwriter();

/* get */
void
get(
  value_type &
, InputIter
, Typelist const &
, iwriter_container const &
) const;

/* empty */
bool
empty(
  InputIter
, Typelist const &
, iwriter_container const &
) const;

protected:

/* get_writer ctor */
explicit
iwriter(
  std::size_t _refs = 0
);

/* do_get */
virtual void
do_get(
  value_type &
, InputIter
, Typelist const &
, iwriter_container const &
) const = 0;

/* do_empty */
virtual bool
do_empty(
  InputIter
, Typelist const &
, iwriter_container const &
) const = 0;
}; /* iwriter */

/* use_iwriter */
template <typename T>
iwriter<T> &
use_writer(
  iwriter_container const &
);

/* rewrite */
template <
  typename T
, typename InputIter
, typename Typelist
>
void
rewrite(
  T &
, InputIter
, Typelist const &
, iwriter_container const &
);

/* empty */
template <
  typename T
, typename InputIter
, typename Typelist
>
bool
empty(
  InputIter
, Typelist const &
, iwriter_container const &
);

} /* typesystems */
#include "bits/iwriter.tcc"
#include "bits/writer_exception.hpp"
#endif
