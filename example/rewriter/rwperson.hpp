//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>
#include "../../include/put_rewriter.hpp"
#include "../../include/get_rewriter.hpp"
#include "person.hpp"

/* put_rewriter for the person class */
class person_rw_put : public typesystems::put_rewriter<person>{
public:
  person_rw_put(
    std::size_t _refs = 0
  );

private:
  virtual bool
  do_rewrite(
    person const & _person
  , typesystems::typebuffer_container const & _buffers
  ) const;

  static typesystems::explicit_typeid_type const array[2];
};

/* get_rewriter for the person class */
class person_rw_get : public typesystems::get_rewriter<person>{
public:
  person_rw_get(
    std::size_t _refs = 0
  );

private:
  virtual bool 
  do_rewrite(
    person &
  , typesystems::typebuffer_container const &
  ) const;

  virtual bool
  do_empty(
    typesystems::typebuffer_container const &
  ) const;

  static typesystems::explicit_typeid_type const array[2];
};


person_rw_put::person_rw_put(
  std::size_t _refs
)
  : typesystems::put_rewriter<person>(
      array
    , static_cast<std::size_t>(2)
    , _refs) {
}

bool
person_rw_put::do_rewrite(
  person const & _person
, typesystems::typebuffer_container const & _buffers
) const {
  if (typesystems::has_typebuffer<int const>(_buffers) == false){
    if (typesystems::has_typebuffer<std::string>(_buffers) == false){
    return false;
    }
  }
typesystems::typebuffer_interface<int const> & buff1
    = typesystems::use_typebuffer<int const>(_buffers);
typesystems::typebuffer_interface<std::string> & buff2
    = typesystems::use_typebuffer<std::string>(_buffers);

buff1.push(_person.get_age());
buff2.push(std::string(_person.name));
return true;
}

typesystems::explicit_typeid_type const person_rw_put::array[]
  = {
     typesystems::explicit_typeid<std::string>::raw_typeid()
   , typesystems::explicit_typeid<int const>::raw_typeid()
  };

bool
person_rw_get::do_rewrite(
  person & _person
, typesystems::typebuffer_container const & _buffers
) const {
  if (typesystems::has_typebuffer<std::string>(_buffers) == false){
  return false;
  }
  if (typesystems::has_typebuffer<int const>(_buffers) == false){
  return false;
  }
typesystems::typebuffer_interface<std::string> & b1
  = typesystems::use_typebuffer<std::string>(_buffers);

typesystems::typebuffer_interface<int const> & b2
  = typesystems::use_typebuffer<int const>(_buffers);

/* operation should block with buffer is empty */
_person = person(b2.next(), b1.next());
return true;
}

bool
person_rw_get::do_empty(
  typesystems::typebuffer_container const & _buffers
) const {
return ( (typesystems::use_typebuffer<std::string>(_buffers)).empty() 
       && (typesystems::use_typebuffer<int const>(_buffers)).empty() );
}

typesystems::explicit_typeid_type const person_rw_get::array[]
  = {
  };
