// copyable type_id which also saves top-level qualifiers.

//          Copyright Sundeep S. Sangha 2013 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_qualified_typeinfo_HPP
#define TYPESYSTEMS_qualified_typeinfo_HPP

#include <typeinfo>
#include <typeindex>
#include "./bits/qualified_types.hpp"
#include "./bits/make_id.hpp"

namespace typesystems {
class qualified_typeinfo;

/* qualified_typeid
  Creates a new qualified type info.
*/
template <typename T>
qualified_typeinfo
qualified_typeid ();

/* qualified_typeinfo
*/
class qualified_typeinfo {
public:

/* ctor copy */
qualified_typeinfo (
  qualified_typeinfo const &
) = default;

/* assignment operator copy */
qualified_typeinfo &
operator= (
  qualified_typeinfo const &
);

/* ctor move */
qualified_typeinfo (
  qualified_typeinfo &&
) = default;

/* assignment operator move */
qualified_typeinfo &
operator= (
  qualified_typeinfo &&
) = default;

/* dtor */
~qualified_typeinfo() = default;

/* equality operator */
bool
operator== (
  qualified_typeinfo const &
) const;

/* equality operator */
bool
operator!= (
  qualified_typeinfo const &
) const;

/* equality operator */
bool
operator== (
  std::type_info const &
) const;

/* equality operator */
bool
operator!= (
  std::type_info const &
) const;

bool
operator < (
  qualified_typeinfo const &
) const;

bits::qualified_type qualification;
std::type_index id;

private:
  /* ctor */
  template <typename T>
  explicit
  qualified_typeinfo(
    bits::make_id<T> const &
  );

template <typename>
friend
qualified_typeinfo qualified_typeid ();
  
}; /* qualified_typeinfo */

/* qualified_typeid */
template <typename T>
qualified_typeinfo
qualified_typeid(
){
return qualified_typeinfo(bits::make_id<T>());
}

} /* typesystems */
#include "bits/qualified_typeid.tcc"
#endif
