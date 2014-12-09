//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_PUT_REWRITER_HPP
#define TYPESYSTEMS_PUT_REWRITER_HPP

#include "explicit_typeid.hpp"
#include "typebuffer.hpp"
#include "bits/rewriter_base.hpp"

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
class put_rewriter : public typesystems::bits::rewriter_base {
public:
  typedef typename type_traits::remove_cv<T>::type value_type;
  explicit_typeid_type const * const type_array;
  /* number to types used in rewriting excluding T. */
  std::size_t const type_count;
  /* number of type generated when rewriting, with zero as infinite */
  std::size_t const gen_count;

  virtual
  ~put_rewriter(
  );

  bool
  rewrite(
    value_type const &
  , typebuffer_container const &
  ) const;

protected:
  /* put_rewriter ctor
  TypeCount is deduced as the array size of the array pass during
  construction. The array is the explicit_typeid's of the types the
  rewriter will use in the rewriting process.

  The 2nd parameter is the total count of generated types from the
  rewriting process.

  The 3rd parameter is the inital value of the internal referance counter,
  if the instance should not be deleted until the client calls delete it
  should be set to 1.
  */
  template <std::size_t TypeCount>
  put_rewriter(
    explicit_typeid_type const (&)[TypeCount]
  , std::size_t 
  , std::size_t _refs = 0
 );

  virtual bool
  do_rewrite(
    value_type const &
  , typebuffer_container const &
  ) const = 0;
};

template <typename T>
bool
operator<(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator>(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator==(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator!=(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator>=(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator<=(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

} /* typesystems */
#include "bits/put_rewriter.tcc"

#undef type_traits
#endif
