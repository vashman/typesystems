//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEMS_REWRITER_BASE_CPP
#define TYPESYSTEMS_REWRITER_BASE_CPP

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
