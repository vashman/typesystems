#ifndef TYPESYSTEMS_REWRITER_EXCEPTION_CPP
#define TYPESYSTEMS_REWRITER_EXCEPTION_CPP

#include "../include/bits/rewriter_exception.hpp"

namespace typesystems {
/* ctor */
no_buffer::no_buffer(
)
: std::runtime_error ("No buffer!") {
}

} /* typesystems */
#endif
