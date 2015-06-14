// Source for writer base.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_BITS_IWRITER_BASE_CPP
#define TYPESYSTEMS_BITS_IWRITER_BASE_CPP

#include "../include/bits/iwriter_base.hpp"

namespace typesystems {
namespace bits {

/* ctor */
iwriter_base::iwriter_base(
  std::size_t _refs
)
: refs (_refs) {
}

/* dtor */
iwriter_base::~iwriter_base(
){
}

} /* bits */ } /* typesystems */
#endif
