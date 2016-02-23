//

#ifndef TYPESYSTEMS_QUALIFIED_TYPEID_CPP
#define TYPESYSTEMS_QUALIFIED_TYPEID_CPP

#include "../include/qualified_typeid.hpp"

namespace typesystems {

/* qualified_typeinfo assingment */
qualified_typeinfo &
qualified_typeinfo::operator = (
  qualified_typeinfo const & _type
){
  if (*this != _type){
  this->id = _type.id;
  this->qualification
    = _type.qualification;
  }
return *this;
}

/* equality operator */
bool
qualified_typeinfo::operator == (
  qualified_typeinfo const & _type
) const {
return (
  (_type.qualification
    == this->qualification)
&& (_type.id == this->id)
);
}

/* equality operator */
bool
qualified_typeinfo::operator != (
  qualified_typeinfo const & _type
) const {
return !(*this == _type);
}

/* equality operator */
bool
qualified_typeinfo::operator == (
  std::type_info const & _type
) const {
return (
  (bits::qualified_type::none
    ==  this->qualification)
&& (std::type_index(_type) == this->id)
);
}

/* equality operator */
bool
qualified_typeinfo::operator != (
  std::type_info const & _type
) const {
return !(this->id == _type);
}

/* equality operator */
bool
qualified_typeinfo::operator < (
  qualified_typeinfo const & _type
) const {
return (
  ( this->qualification 
  < _type.qualification )
&& (this->id < _type.id) );
}

} /* typesystems */
#endif

