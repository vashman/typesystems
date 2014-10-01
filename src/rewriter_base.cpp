//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_REWRITER_BASE_CPP
#define TYPESYSTEMS_REWRITER_BASE_CPP

#include "../include/bits/rewriter_base.hpp"

namespace typesystems {
namespace bits {

rewriter_base::rewriter_base(
  std::size_t _refs
)
  : refs (_refs) {
}

rewriter_base::~rewriter_base(
){
}

} /* bits */ } /* typesystems */
#endif
