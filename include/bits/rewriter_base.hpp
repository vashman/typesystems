// rewriter base used to store pointers of rewriters

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

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
