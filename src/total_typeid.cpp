// 

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEMS_BITS_TOTAL_TYPEID_CPP
#define TYPESYSTEMS_BITS_TOTAL_TYPEID_CPP

#include "../include/bits/total_typeid.hpp"

namespace typesystems {
namespace bits {
/* total_typeid::total_id */
total_typeid::id_type total_typeid::total_id
                    = std::numeric_limits<total_typeid::id_type>::min();

/* total_typeid next_id */
total_typeid::id_type
total_typeid::next_id(
){
return total_typeid::total_id++;
}

} /* bits */ } /* typesystems */
#endif
