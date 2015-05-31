//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_TYPESYSTEM_CPP
#define TYPESYSTEMS_TYPESYSTEM_CPP

#include "../include/typesystem.hpp"

namespace typesystems {
static std::size_t total_norm_ids = 0;

/* Typesystem */
/* typesystem dtor */
typesystem::~typesystem(
){
/*for (auto iter = this->norm_map.begin(), iend = this->norm_map.end(); iter != iend; ++iter){
  if (--(iter->second->refs) == 0){
  delete iter->second;
  }
}*/
}

} /* typesystems */
#endif