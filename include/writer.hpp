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
std::shared_ptr<void> iwriter_base_type;

typedef
std::shared_ptr<void> owriter_base_type;

/* writer function type
  The type used to store the writer,
  using the call signature for the
  writer.
  
  Returns false if the re-writing could
  not be done. True otherwise.
*/
template <
  typename T
, typename BufferIter
, typename WriterIter >
using iwriter_function = std::function <
bool (
  T &
, BufferIter
, BufferIter
, WriterIter
, WriterIter
)>;

template <
  typename T
, typename OutputIter
, typename WriterIter >
using owriter_function = std::function <
bool (
  T const &
, OutputIter
, WriterIter
, WriterIter
)>;

/* iwriter type */
template <
  typename T
, typename BufferIter
, typename WriterIter >
using iwriter_type = std::shared_ptr <
  iwriter_function <
    T
  , BufferIter
  , WriterIter >
>;

/* owriter type */ 
template <
  typename T
, typename OutputIter
, typename WriterIter >
using owriter_type = std::shared_ptr<
  owriter_function <
    T
  , OutputIter
  , WriterIter
  >
>;

/* make input writer */
template <
  typename T
, typename BufferIter
, typename WriterIter >
iwriter_base_type
make_iwriter (
  iwriter_function <
    T, BufferIter, WriterIter > *
);

/* make output writer */
template <
  typename T
, typename OutputIter
, typename WriterIter >
owriter_base_type
make_owriter (
  owriter_function <
    T, OutputIter, WriterIter > *
);

/* use_iwriter */
template <
  typename T
, typename BufferIter
, typename WriterIter >
iwriter_type<T,BufferIter,WriterIter>
use_iwriter (
  iwriter_base_type &
);

/* use_owriter */
template <
  typename T
, typename OutputIter
, typename WriterIter >
owriter_type<T,OutputIter,WriterIter>
use_owriter (
  owriter_base_type &
);

/* rewrite */
template <
  typename T
, typename BufferIter
, typename WriterIter
, template <typename...> Typelist
, typename... Ts >
bool
rewrite (
  T &
, BufferIter
, BufferIter
, WriterIter
, WriterIter
, Typelist<Ts...> const &
);

/* rewrite */
template <
  typename T
, typename OutputIter
, typename WriterIter
, template <typename...> Typelist
, typename... Ts >
bool
rewrite (
  T &
, OutputIter
, WriterIter
, WriterIter
, Typelist<Ts...> const &
);

} /* typesystems */
#include "./bits/writer.tcc"
#endif
