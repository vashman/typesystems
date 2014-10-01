// explicit_typeid template instace

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_EXPLICIT_TYPEID_TCC
#define TYPESYSTEMS_EXPLICIT_TYPEID_TCC

namespace typesystems {

template <typename T>
explicit_typeid_type const explicit_typeid<T>::id
    = typesystems::bits::total_typeid::next_id();

/* explicit_typeid static compare */
template <typename T>
template <typename T2>
bool
explicit_typeid<T>::compare(
){
return explicit_typeid<T>::id == explicit_typeid<T2>::raw_typeid();
}

/* explicit_typeid static raw_compare */
template <typename T>
bool
explicit_typeid<T>::raw_compare(
  explicit_typeid_type const & _value
){
return explicit_typeid<T>::id == _value;
}

/* explcit_typeid raw typeid */
template <typename T>
explicit_typeid_type
explicit_typeid<T>::raw_typeid(
){
return explicit_typeid<T>::id;
}

} /* typesystems */
#endif
