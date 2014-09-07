// unqiue copyable type_id that, does not check against polymorphic types.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEMS_EXPLICIT_TYPEID_HPP
#define TYPESYSTEMS_EXPLICIT_TYPEID_HPP

#include "./bits/total_typeid.hpp"

namespace typesystems{

typedef typesystems::bits::total_typeid::id_type explicit_typeid_type;

/* explicit_typeid
*/
template <typename T>
class explicit_typeid{
public:
  typedef T value_type;

#if __cplusplus >= 201103L
  explicit
  explicit_typeid() = default;

  explicit_typeid(explicit_typeid const &) = default;

  explicit_typeid &
  operator=(explicit_typeid const &) = default;

  explicit_typeid(explicit_typeid &&) = default;

  explicit_typeid &
  operator=(explicit_typeid &&) = default;

 ~explicit_typeid() = default;
#endif

  template <typename T2>
  static bool
  compare(explicit_typeid<T2> const &);

  template <typename T2>
  static bool
  compare();

  static bool
  raw_compare(explicit_typeid_type const &);

  static explicit_typeid_type
  raw_typeid();

	static explicit_typeid_type const id;
};

} /* typesystems */

#include "bits/explicit_typeid.tcc"
#endif
