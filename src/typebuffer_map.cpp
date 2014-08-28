// dtor for typebuffer_map

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEM_TYPEBUFFER_MAP_CPP
#define TYPESYSTEM_TYPEBUFFER_MAP_CPP

#include "../include/bits/typebuffer_map.hpp"

namespace typesystem{
namespace bits{
/* buffer_unit_container dtor 

Needs to delete all typebuffer pointers because every buffer unit
manages there own.
*/
typebuffer_map::~typebuffer_map(){
for (typebuffer_container::iterator iter = this->c.begin()
    , iend = this->c.end(); iter != iend; ++iter
    ){
delete iter->second;
}
}

} /* bits */ } /* typeystem */
#endif
