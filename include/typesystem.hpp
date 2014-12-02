// typesystem or part of typesystem representation with io.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_TYPESYSTEM_HPP
#define TYPESYSTEMS_TYPESYSTEM_HPP

#include <map>
#include "explicit_typeid.hpp"
#include "typebuffer.hpp"
#include "put_rewriter.hpp"
#include "get_rewriter.hpp"
#include "bits/rewriter_base.hpp"

namespace typesystems {

/* typesystem
*/
class typesystem{
public:
  typedef explicit_typeid_type id_type;

#if __cplusplus >= 201103L
  typesystem(
  ) = default;

  typesystem(
    typesystem const &
  ) = default;

  typesystem &
  operator=(
    typesystem const &
  ) = default;

  typesystem(
    typesystem &&
  ) = default;

  typesystem &
  operator=(
    typesystem &&
  ) = default;
#endif

  ~typesystem();

  template <typename T>
  bool
  put_rewrite(
    T const &
  ) const;

  template <typename T>
  bool
  get_rewrite(
    T &
  ) const;

private:
  typebuffer_container typebuffers;

  std::map<explicit_typeid_type, typesystems::bits::rewriter_base *>
    put_rewriters;

  std::map<explicit_typeid_type, typesystems::bits::rewriter_base *>
    get_rewriters;

  template <typename T>
  friend bool
  has_put_rewriter(typesystem const &);

  template <typename T>
  friend put_rewriter<T>&
  use_put_rewriter(typesystem const &);

  template <typename T>
  friend bool
  has_get_rewriter(typesystem const &);

  template <typename T>
  friend get_rewriter<T>&
  use_get_rewriter(typesystem const &);

  template <typename T>
  friend bool
  set_put_rewriter(typesystem const &);

  template <typename T>
  friend bool
  set_get_rewriter(typesystem const &);

  template <typename T, typename Sequence>
  friend void
  set_typebuffer(typesystem &);

  template <typename T>
  friend typebuffer_interface<T> &
  use_typebuffer(typesystem &);

  template <typename T, typename Sequence>
  friend typebuffer<T,Sequence> &
  use_typebuffer(typesystem &);

  template <typename T>
  friend bool
  empty(typesystem const &);

  template <typename T>
  friend void
  clear(typesystem &);
};

/* typesystem::empty */
template <typename T>
bool
empty(
  typesystem const &
);

/* typesystem::clear */
template <typename T>
void
clear(
  typesystem &
);

/* typesystem::has_put_rewriter */
template <typename T>
bool
has_put_rewriter(
  typesystem const &
);

/* typesystem::has_get_rewriter */
template <typename T>
bool
has_get_rewriter(
  typesystem const &
);

/* typesystem::use_put_rewriter */
template <typename T>
put_rewriter<T> &
use_put_rewriter(
  typesystem const &
);

/* typesystem::use_get_rewriter */
template <typename T>
get_rewriter<T> &
use_get_rewriter(
  typesystem const &
);

/* typesystem::set_typebuffer */
template <typename T, typename Sequence>
void
set_typebuffer(
  typesystem const &
);

template <typename T>
typebuffer_interface<T> &
use_typebuffer(
  typesystem &
);

template <typename T, typename Sequence>
typebuffer<T,Sequence> &
use_typebuffer(
  typesystem &
);

/* typesystem::set_put_rewriter */
template <typename Rewriter>
bool
set_put_rewriter(
  typesystem const & _typesys
);

/* typesystem::set_get_rewriter */
template <typename Rewriter>
bool
set_get_rewriter(
  typesystem const & _typesys
);

} /* typesystems */
#include "./bits/typesystem.tcc"
#endif
