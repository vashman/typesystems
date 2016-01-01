//

#ifndef TYPESYSTEMS_WRITER_HPP
#define TYPESYSTEMS_WRITER_HPP

#include <memory>
#include "qualified_typeid.hpp"

namespace typesystems {
  
/* writer base type
  Typeless storage of writer.
*/
typedef
std::shared_ptr<void> writer_base_type;

/* writer function type
  The type used to store the writer,
  using the call signature for the
  writer.
*/
template <
  typename BufferIter
, typename OutputIter >
using writer_function = std::function <
qualified_typeinfo (
  BufferIter, BufferIter, OutputIter )
>;

/* writer type
  The shared writer type implicity
  converts to a base writer type.
*/
template <
  typename BufferIter
, typename OutputIter >
struct writer_type {
/* ctor */
writer_type (
  writer_function <
    BufferIter,OutputIter > * _func
) : ptr (_func) {
}

/* ctor */
writer_type (
  writer_base_type & _writer
) : ptr (std::static_pointer_cast <
    writer_function <
      BufferIter, OutputIter >
  > (_writer)
  ) {
}

operator writer_base_type() const {
  return std::static_pointer_cast <void>
  (this->ptr);
}

/* ctor copy */
writer_type (
  writer_type const &
) = default;

/* copy assignment */
writer_type &
operator = (
  writer_type const &
) = default;

/* move assignment */
writer_type &
operator = (
  writer_type &&
) = default;

/* ctor move */
writer_type (
  writer_type &&
) = default;

/* dtor */
~writer_type() = default;

bool
operator () (
  BufferIter _begin
, BufferIter _end
, OutputIter _output
){
return
(*this->ptr)(_begin,_end,_output);
}

std::shared_ptr < writer_function <
  BufferIter, OutputIter > > ptr;
}; /* writer_type */

/* make writer */
template <
  typename BufferIter
, typename OutputIter
, typename Function >
writer_type<BufferIter,OutputIter>
make_writer (
  Function
);

/* use writer */
template <
  typename BufferIter
, typename OutputIter >
writer_type <BufferIter, OutputIter>
use_writer (
  writer_base_type &
);

/* use writer */
template <
  typename BufferIter
, typename OutputIter >
writer_type <BufferIter, OutputIter>
use_writer (
  writer_type<BufferIter,OutputIter> &
);

/* rewrite */
template <
  typename... Ts
, typename T
, typename BufferIter
, typename OutputIter
, typename WriterIter
, typename GetWriter >
qualified_typeinfo
rewrite (
  BufferIter, BufferIter
, OutputIter
, WriterIter, WriterIter
, GetWriter
);

} /* typesystems */
#include "./bits/writer.tcc"
#endif
