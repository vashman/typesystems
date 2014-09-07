// 

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEMS_EXPLICIT_TYPEID_TCC
#define TYPESYSTEMS_EXPLICIT_TYPEID_TCC

namespace typesystems {

template <typename T>
explicit_typeid_type const explicit_typeid<T>::id
    = typesystems::bits::total_typeid::next_id();

/* explicit_typeid compare */
template <typename T>
template <typename T2>
bool
explicit_typeid<T>::compare(
  explicit_typeid<T2> const & _id
){
return explicit_typeid<T>::id == explicit_typeid<T2>::id;
}

/* explicit_typeid compare */
template <typename T>
template <typename T2>
bool
explicit_typeid<T>::compare(
){
return explicit_typeid<T>::id == explicit_typeid<T2>::id;
}

/* explicit_typeid raw_compare */
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
