// dtor for typebuffer_map

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEMS_TYPEBUFFER_MAP_CPP
#define TYPESYSTEMS_TYPEBUFFER_MAP_CPP

#include "../include/bits/typebuffer_map.hpp"

namespace typesystems {
namespace bits {

/* buffer_unit_container dtor
Needs to delete all typebuffer pointers because every buffer unit
manages there own.
*/
typebuffer_map::~typebuffer_map(){
for (typebuffer_container::map_iterator iter = this->c.begin()
    , iend = this->c.end(); iter != iend; ++iter
    ){
delete iter->second;
}
}

typebuffer_map::iterator
typebuffer_map::begin(
){
return typebuffer_map::iterator(this->c.begin());
}

typebuffer_map::iterator
typebuffer_map::end(
){
return typebuffer_map::iterator(this->c.end());
}

typebuffer_map::const_iterator
typebuffer_map::begin(
) const {
return typebuffer_map::const_iterator(this->c.begin());
}

typebuffer_map::const_iterator
typebuffer_map::end(
) const {
return typebuffer_map::const_iterator(this->c.end());
}

/* typebuffer_map iterator */

/* typebuffer_map::iterator ctor */
typebuffer_map::iterator::iterator(
  typename typebuffer_map::map_type::iterator _iter
)
  : iter (_iter) {
}

typename typebuffer_map::iterator::self_type
typebuffer_map::iterator::operator++(
){
++this->iter;
return *this;
}

typename typebuffer_map::iterator::self_type
typebuffer_map::iterator::operator++(
  int 
){
typename typebuffer_map::iterator::self_type i = *this;
this->iter++;
return i;
}

typename typebuffer_map::iterator::reference
typebuffer_map::iterator::operator*(
){
return this->iter->second;
}

typename typebuffer_map::iterator::pointer
typebuffer_map::iterator::operator->(
){
return &this->iter->second;
}

bool
typebuffer_map::iterator::operator==(
  typename typebuffer_map::iterator::self_type const & _iter
) const {
return _iter.iter == this->iter;
}

bool
typebuffer_map::iterator::operator!=(
  typename typebuffer_map::iterator::self_type const & _iter
) const {
return _iter.iter != this->iter;
}

/* typebuffer_map const_iterator */

/* typebuffer_map::const_iterator ctor */
typebuffer_map::const_iterator::const_iterator(
  typename typebuffer_map::map_type::const_iterator _iter
)
  : iter (_iter) {
}

typename typebuffer_map::const_iterator::self_type
typebuffer_map::const_iterator::operator++(
){
++this->iter;
return *this;
}

typename typebuffer_map::const_iterator::self_type
typebuffer_map::const_iterator::operator++(
  int 
){
typename typebuffer_map::const_iterator::self_type i = *this;
this->iter++;
return i;
}

typename typebuffer_map::const_iterator::value_type const &
typebuffer_map::const_iterator::operator*(
){
return this->iter->second;
}

typename typebuffer_map::const_iterator::value_type const *
typebuffer_map::const_iterator::operator->(
){
return &this->iter->second;
}

bool
typebuffer_map::const_iterator::operator==(
  typename typebuffer_map::const_iterator::self_type const & _iter
) const {
return _iter.iter == this->iter;
}

bool
typebuffer_map::const_iterator::operator!=(
  typename typebuffer_map::const_iterator::self_type const & _iter
) const {
return _iter.iter != this->iter;
}

} /* bits */ } /* typeystems */
#endif
