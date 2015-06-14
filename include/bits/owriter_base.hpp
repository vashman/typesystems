// Used by writer container to hold
// pointers to writers.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_OWRITER_BASE_HPP
#define TYPESYSTEMS_OWRITER_BASE_HPP

#include <cstddef>

namespace typesystems {
namespace bits {

/* writer_base */
class owriter_base {
public:
  virtual
  ~owriter_base();

protected:
  owriter_base(std::size_t);

private:
  std::size_t refs;
};

} /* bits */ } /* typesystems */

#endif
