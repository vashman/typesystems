#ifndef TYPESYSTEMS_WRITER_EXCEPTION_CPP
#define TYPESYSTEMS_WRITER_EXCEPTION_CPP

#include "../include/bits/writer_exception.hpp"

namespace typesystems {
/* ctor */
no_buffer::no_buffer(
)
: std::runtime_error ("No buffer!") {
}

} /* typesystems */
#endif
