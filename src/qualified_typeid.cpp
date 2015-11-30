//

#ifndef TYPESYSTEMS_qualified_typeinfo_CPP
#define TYPESYSTEMS_qualified_typeinfo_CPP

#include "../include/qualified_typeid.hpp"

namespace typesystems {

qualified_typeinfo &
qualified_typeinfo::operator= (
  qualified_typeinfo const & _type
){
  if (*this != _type){
  this->id = _type.id;
  this->qualification = _type.qualification;
  }
return *this;
}

/* equality operator */
bool
qualified_typeinfo::operator== (
  qualified_typeinfo const & _type
) const {
return (
  (_type.qualification == this->qualification)
&&
 (_type.id == this->id)
);
}

/* equality operator */
bool
qualified_typeinfo::operator!= (
  qualified_typeinfo const & _type
) const {
return !(*this == _type);
}

/* equality operator */
bool
qualified_typeinfo::operator== (
  std::type_info const & _type
) const {
return (
  (std::type_index(_type) == this->id)
&&
 (bits::qualified_type::none ==  this->qualification)
);
}

/* equality operator */
bool
qualified_typeinfo::operator!= (
  std::type_info const & _type
) const {
return !(this->id == _type);
}

bool
qualified_typeinfo::operator < (
  qualified_typeinfo const & _type
) const {
  return _type.id < this->id;
/* unfinshed !!! */
}

} /* typesystems */
#endif
