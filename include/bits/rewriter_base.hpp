//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEMS_BITS_REWRITER_BASE_HPP
#define TYPESYSTEMS_BITS_REWRITER_BASE_HPP

#include <cstddef>

namespace typesystems {
namespace bits {

/* basic_normalizer
*/
class rewriter_base{
public:
  ~rewriter_base();

protected:
  rewriter_base(std::size_t);

private:
  std::size_t refs;
};

} /* bits */ } /* typesystems */
#endif
