//

//          Copyright Sundeep S. Sangha 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_REWRITER_EXCEPTION_HPP
#define TYPESYSTEMS_REWRITER_EXCEPTION_HPP

#include <stdexcept>
#include "../typebuffer.hpp"

namespace typesystems {
/**/
class no_buffer
: public std::runtime_error {
public:
  /* ctor */
  no_buffer();

  no_buffer(
    no_buffer const &
  ) = default;

  ~no_buffer() noexcept(true) = default;
};

/**/
template <typename T>
void
check_typebuffer(
  typebuffer_container const & _buffer
);

/**/
template <typename T>
void
check_typebuffer(
  typebuffer_container const & _buffer
){
  /* Check if the buffer is present. */
  if (! has_typebuffer<T>(_buffer)){
  throw no_buffer();
  }
}

} /* typesystems */
#endif
