//

//          Copyright Sundeep S. Sangha 2013 - 2014.

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
