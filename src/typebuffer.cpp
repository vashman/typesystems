// typebuffer_base implementation

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEMS_TYPEBUFFER_BASE_CPP
#define TYPESYSTEMS_TYPEBUFFER_BASE_CPP

#include "../include/typebuffer.hpp"

namespace typesystems {
namespace bits {
/* typebuffer_base dtor */
typebuffer_base::~typebuffer_base(
){
}

/* typebuffer_base clear */
void
typebuffer_base::clear(
){
this->do_clear();
}

/* typebuffer_base empty */
bool
typebuffer_base::empty(
) const {
return this->do_empty();
}
} /* bits */

/* typesystem::clear */
void 
clear(
  typebuffer_container const & _unit
){
for (typebuffer_container::map_const_iterator iter = _unit.c.begin()
             , iend = _unit.c.end(); iter != iend; ++iter){
iter->second->clear();
}
}

} /* typesystems */
#endif
