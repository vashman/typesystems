//

//          Copyright Sundeep S. Sangha 2013 - 2014.


#ifndef TYPESYSTEMS_BITS_TYPEBUFFER_TCC
#define TYPESYSTEMS_BITS_TYPEBUFFER_TCC

namespace typesystems {

/* typbuffer_interface dtor */
template <typename T>
typebuffer_interface<T>::~typebuffer_interface(
){
}

/* typebuffer_interface pop */
template <typename T>
void
typebuffer_interface<T>::pop(
){
this->do_pop();
}

/* typebuffer_interface next */
template <typename T>
typename typebuffer_interface<T>::value_type
typebuffer_interface<T>::next(
){
return this->do_next();
}

/* typebuffer_interface push */
template <typename T>
void
typebuffer_interface<T>::push(
typename typebuffer_interface<T>::value_type const & _var
){
this->do_push(_var);
}

#if __cplusplus >= 201103L
/* typebuffer_interface push */
template <typename T>
void
typebuffer_interface<T>::push(
typename typebuffer_interface<T>::value_type && _var
){
this->do_push(_var);
}
#endif

/* Typebuffer */
/* typebuffer ctor */
template <typename T, typename Sequence>
typebuffer<T,Sequence>::typebuffer(
  Sequence const & _cntr
)
  : typebuffer_interface<T> ()
  , c (_cntr){
}

/* typebuffer copy ctor */
template <typename T, typename Sequence>
typebuffer<T,Sequence>::typebuffer(
  typebuffer<T,Sequence> const & _buff
)
  : typebuffer_interface<T> (_buff)
  , c (_buff.c){
}

/* typebuffer copy operator */
template <typename T, typename Sequence>
typebuffer<T,Sequence> &
typebuffer<T,Sequence>::operator=(
  typebuffer<T,Sequence> const & _buff
){
  if (this != &_buff){
  this->c = _buff.c;
  }
return *this;
}

/* typebuffer move ctor */
template <typename T, typename Sequence>
typebuffer<T,Sequence>::typebuffer(
  typebuffer<T,Sequence> && _buff
)
  : typebuffer_interface<T> (_buff)
  , c (_buff.c){
}

#if __cplusplus >= 201103L
/* typebuffer move operator */
template <typename T, typename Sequence>
typebuffer<T,Sequence> &
typebuffer<T,Sequence>::operator=(
  typebuffer<T,Sequence> && _buff
){
this->c = _buff.c;
return *this;
}
#endif

/* typebuffer dtor */
template <typename T, typename Sequence>
typebuffer<T,Sequence>::~typebuffer(
){
}

/* typebuffer do_clear */
template <typename T, typename Sequence>
void
typebuffer<T,Sequence>::do_clear(
){
this->c.clear();
}

/* typebuffer do_empty */
template <typename T, typename Sequence>
bool
typebuffer<T,Sequence>::do_empty(
) const {
return this->c.empty();
}

/* typebuffer do_push copy */
template <typename T, typename Sequence>
void
typebuffer<T,Sequence>::do_push(
typename typebuffer_interface<T>::value_type const & _var
){
this->c.push_back(_var);
}

#if __cplusplus >= 201103L
/* typebuffer do_push move */
template <typename T, typename Sequence>
void
typebuffer<T,Sequence>::do_push(
typename typebuffer_interface<T>::value_type && _var
){
this->c.push_back(_var);
}
#endif

/* typebuffer do_next */
template <typename T, typename Sequence>
typename typebuffer_interface<T>::value_type
typebuffer<T,Sequence>::do_next(
){
typename typebuffer<T,Sequence>::value_type t = this->c.back();
this->c.pop_back();
return t;
}

/* typebuffer do_pop */
template <typename T, typename Sequence>
void
typebuffer<T,Sequence>::do_pop(
){
this->c.pop_back();
}

/* typesystem::empty buffer_unit */
template <typename T>
bool
empty(
  typebuffer_container const & _unit
){
  if (has_typebuffer<T>(_unit)){
  return (_unit.c.at(explicit_typeid<T>::raw_typeid()))->empty();
  }
throw std::bad_cast();
}

/* typesystem::clear */
template <typename T>
void
clear(
  typebuffer_container const & _unit
){
  if (has_typebuffer<T>(_unit)){
  (_unit.c[explicit_typeid<T>::raw_typeid()])->clear();
  }
throw std::bad_cast();
}

/* typesystem::has_typebuffer */
template <typename T>
bool
has_typebuffer(
  typebuffer_container const & _unit
){
return (_unit.c.find(explicit_typeid<T>::raw_typeid()) != _unit.c.end());
}

/* typesystem::has_typebuffer */
template <typename T, typename Sequence>
bool
has_typebuffer(
  typebuffer_container const & _unit
){
typebuffer_container::map_iterator iter
            = _unit.c.find(explicit_typeid<T>::raw_typeid());
  if (iter != _unit.c.end()){
  /* if types equal return true */
  return explicit_typeid<Sequence>::raw_compare(
               iter->second->container_id);
  }
return false;
}

/* typesystem::use_typebuffer */
template <typename T>
typebuffer_interface<T> &
use_typebuffer(
  typebuffer_container const & _unit
){
typesystems::bits::typebuffer_base * buff = nullptr;
buff = _unit.c.at(explicit_typeid<T>::raw_typeid());
  if (buff != nullptr){
  return static_cast<typebuffer_interface<T> & >(* buff);
  }
throw std::bad_cast();
}

/* typesystem::use_typebuffer */
template <typename T, typename Sequence>
typebuffer<T, Sequence> &
use_typebuffer(
  typebuffer_container const & _unit
){
typesystems::bits::typebuffer_base * buff = nullptr;
buff = _unit.c.at(explicit_typeid<T>::raw_typeid());
  if (buff != nullptr){
  return static_cast<typebuffer<T, Sequence> &>(* buff);
  }
throw std::bad_cast();
}

/* typesystem::set_typebuff */
template <typename T, typename Sequence>
void
set_typebuffer(
  typebuffer_container & _unit
){
_unit.c[explicit_typeid<T>::raw_typeid()] = new typebuffer<T, Sequence>();
(_unit.c[explicit_typeid<T>::raw_typeid()])->container_id
               = explicit_typeid<Sequence>::raw_typeid();
}

/* typesystem::set_typebuff copy */
template <typename T, typename Sequence>
void
set_typebuffer(
  typebuffer_container & _unit
, Sequence const & _c
){
_unit.c[explicit_typeid<T>::raw_typeid()]
                       = new typebuffer<T, Sequence>(_c);
(_unit.c[explicit_typeid<T>::raw_typeid()])->container_id
               = explicit_typeid<Sequence>::raw_typeid();
}

/* typesystem::set_typebuff move */
template <typename T, typename Sequence>
void
set_typebuffer(
  typebuffer_container & _unit
, Sequence && _c
){
_unit.c[explicit_typeid<T>::raw_typeid()]
        = new typebuffer<T, Sequence>(_c);
(_unit.c[explicit_typeid<T>::raw_typeid()])->container_id
               = explicit_typeid<Sequence>::raw_typeid();
}

} /* typesystems */
#endif
