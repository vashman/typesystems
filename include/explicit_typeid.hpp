// unqiue copyable type_id that, does not check against polymorphic types.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_EXPLICIT_TYPEID_HPP
#define TYPESYSTEMS_EXPLICIT_TYPEID_HPP

#include "./bits/total_typeid.hpp"

namespace typesystems {

typedef typesystems::bits::total_typeid::id_type explicit_typeid_type;

/* explicit_typeid
*/
template <typename T>
class explicit_typeid{
public:
  typedef T type;

#if __cplusplus >= 201103L
  explicit
  explicit_typeid() = delete;

  explicit_typeid(explicit_typeid const &) = delete;

  explicit_typeid &
  operator=(explicit_typeid const &) = delete;

  explicit_typeid(explicit_typeid &&) = delete;

  explicit_typeid &
  operator=(explicit_typeid &&) = delete;

 ~explicit_typeid() = delete;
#endif

  template <typename T2>
  static bool
  compare();

  static bool
  raw_compare(explicit_typeid_type const &);

  static explicit_typeid_type
  raw_typeid();

private:
	static explicit_typeid_type const id;
};

} /* typesystems */

#include "bits/explicit_typeid.tcc"
#endif
