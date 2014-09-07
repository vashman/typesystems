//

//          Copyright Sundeep S. Sangha 2013 - 2014.


#ifndef TYPESYSTEMS_GET_REWRITER_HPP
#define TYPESYSTEMS_GET_REWRITER_HPP

#include "explicit_typeid.hpp"
#include "typebuffer.hpp"
#include "bits/rewriter_base.hpp"

#if __cplusplus >= 201103L
#include <type_traits>
#define type_traits ::std

#else
#include <boost/type_traits.hpp>
#define type_traits ::BOOST
#endif

namespace typesystems{

/* rewriter_interface */
template <typename T>
class get_rewriter : public typesystems::bits::rewriter_base {
public:
  typedef typename type_traits::remove_cv<T>::type value_type;
  explicit_typeid_type const * const type_array;
  /* number to types used in rewriting excluding T. */
  std::size_t const type_count;

  template <std::size_t TypeCount>
  explicit
  get_rewriter(
    explicit_typeid_type const (&)[TypeCount]
  , std::size_t _refs = 0
  );

  virtual
  ~get_rewriter(
  );

  bool
  rewrite(
    value_type &
  , typebuffer_container const &
  ) const;

protected:
  virtual bool
  do_rewrite(
    value_type &
  , typebuffer_container const &
  ) const = 0;
};

template <typename T>
bool
operator<(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator>(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator==(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator!=(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator>=(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator<=(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

} /* typesystems */
#include "bits/get_rewriter.tcc"

#undef type_traits
#endif
