// typesystem template implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_TYPESYSTEM_TCC
#define TYPESYSTEMS_TYPESYSTEM_TCC

#include "default_rewriter.hpp"

namespace typesystems {

/* typesystem put_rewrite */
template <typename T>
bool
typesystem::put_rewrite(
  T const & _value_type
) const {
put_rewriter<T> & rw = use_put_rewriter<T>(*this);
return rw.rewrite(_value_type, this->typebuffers);
}

/* typesystem get_rewite */
template <typename T>
bool
typesystem::get_rewrite(
  T & _value_type
) const {
get_rewriter<T> & rw = use_get_rewriter<T>(*this);
return rw.rewrite(_value_type, this->typebuffers);
}

/* typesystems::has_put_rewriter */
template <typename T>
bool
has_put_rewriter(
  typesystem const & _typesys
){
return _typesys.put_rewriters.find(explicit_typeid<T>::raw_typeid())
        != _typesys.put_rewriters.end();
}

/* typesystems::has_get_rewriter */
template <typename T>
bool
has_get_rewriter(
  typesystem const & _typesys
){
return _typesys.get_rewriters.find(explicit_typeid<T>::raw_typeid())
      != _typesys.get_rewriters.end();
}

/* typesystems::use_put_rewriter */
template <typename T>
put_rewriter<T> &
use_put_rewriter(
  typesystem const & _typesys
){
typesystems::bits::rewriter_base * rw = nullptr;
rw = _typesys.put_rewriters.at(explicit_typeid<T>::raw_typeid());
  if (rw != nullptr){
  return static_cast<put_rewriter<T> &>(* rw);
  }
throw std::bad_cast();
}

/* typesystems::use_get_rewriter */
template <typename T>
get_rewriter<T> &
use_get_rewriter(
  typesystem const & _typesys
){
typesystems::bits::rewriter_base * rw = nullptr;
rw = _typesys.get_rewriters.at(explicit_typeid<T>::raw_typeid());
  if (rw != nullptr){
  return static_cast<get_rewriter<T> &>(* rw);
  }
throw std::bad_cast();
}

/* typesystems::set_typebuffer */
template <typename T, typename Sequence>
void
set_typebuffer(
  typesystem & _typesys
){
set_typebuffer<T,Sequence>(_typesys.typebuffers);
bool replace_get = false;
bool replace_put = false;
/* if has rewriter check its types and delete if not default */
  if (has_get_rewriter<T>(_typesys)){
  get_rewriter<T> & rw = use_get_rewriter<T>(_typesys);
    if (rw.type_count != 0){
    replace_get = true;
    typesystems::bits::rewriter_base * p
      = _typesys.get_rewriters[explicit_typeid<T>::raw_typeid()];
    delete p;
    }
  }

  if (has_put_rewriter<T>(_typesys)){
  put_rewriter<T> & rw = use_put_rewriter<T>(_typesys);
    if (rw.type_count != 0){
    replace_put = true;
    typesystems::bits::rewriter_base * p
      = _typesys.put_rewriters[explicit_typeid<T>::raw_typeid()];
    delete p;
    }
  }
/* create default put and get rewirter for type */
_typesys.put_rewriters[explicit_typeid<T>::raw_typeid()]
  = new typesystems::bits::default_rewriter_put<T>();
_typesys.get_rewriters[explicit_typeid<T>::raw_typeid()]
  = new typesystems::bits::default_rewriter_get<T>();
}

template <typename Rewriter>
bool
set_put_rewriter(
  typesystem const & _typesys
){
/* check if default rewriter is set, if so skip and return false.
If a rewriter is set but is not the default rewriter then delete and
procced.
*/
  if (has_put_rewriter<typename Rewriter::value_type>(_typesys)){
  put_rewriter<typename Rewriter::value_type> & rw
    = use_put_rewriter<typename Rewriter::value_type>(_typesys);
    if (rw.type_count == 0){
    return false;
    }
  typesystems::bits::rewriter_base * p
    = _typesys.put_rewriters[
        explicit_typeid<typename Rewriter::value_type>::raw_typeid()
    ];
  delete p;
  }
/* set new rewriter */
_typesys.put_rewriters[
  explicit_typeid<typename Rewriter::value_type>::raw_typeid()
] = new Rewriter();
return true;
}

template <typename Rewriter>
bool
set_get_rewriter(
  typesystem const & _typesys
){
/* check if default rewriter is set, if so skip and return false.
If a rewriter is set but is not the default rewriter then delete and
procced.
*/
  if (has_get_rewriter<typename Rewriter::value_type>(_typesys)){
  get_rewriter<typename Rewriter::value_type> & rw
    = use_get_rewriter<typename Rewriter::value_type>(_typesys);
    if (rw.type_count == 0){
    return false;
    }
  typesystems::bits::rewriter_base * p
    = _typesys.get_rewriters[
        explicit_typeid<typename Rewriter::value_type>::raw_typeid()
    ];
  delete p;
  }
/* set new rewriter */
_typesys.get_rewriters[
  explicit_typeid<typename Rewriter::value_type>::raw_typeid()
] = new Rewriter();
return true;
}

/* typesystem empty */
template <typename T>
bool
empty(
  typesystem const & _typesys
){
  if (has_get_rewriter<T>(_typesys)){
  return (use_get_rewriter<T>(_typesys)).empty(_typesys.typebuffers);
  }
return empty<T>(_typesys.typebuffers);
}

/* typesystem clear */
template <typename T>
void
clear(
  typesystem & _typesys
){
clear<T>(_typesys.typebuffers);
}

template <typename T, typename Sequence>
typebuffer<T,Sequence> &
use_typebuffer(
  typesystem & _typesys
){
return use_typebuffer<T,Sequence>(_typesys.typebuffers);
}

template <typename T>
typebuffer_interface<T> &
use_typebuffer(
  typesystem & _typesys
){
return use_typebuffer<T>(_typesys.typebuffers);
}

} /* typesystems */
#endif
