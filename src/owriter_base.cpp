// Source for writer base.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_BITS_OWRITER_BASE_CPP
#define TYPESYSTEMS_BITS_OWRITER_BASE_CPP

#include "../include/bits/owriter_base.hpp"

namespace typesystems {
namespace bits {

/* ctor */
owriter_base::owriter_base(
  std::size_t _refs
)
: refs (_refs) {
}

/* dtor */
owriter_base::~owriter_base(
){
}

} /* bits */ } /* typesystems */
#endif
