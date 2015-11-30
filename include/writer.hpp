//

#ifndef TYPESYSTEMS_WRITER_HPP
#define TYPESYSTEMS_WRITER_HPP

#include <memory>
#include "qualified_typeid.hpp"

namespace typesystems {

/* writer base type */
typedef
std::shared_ptr<void> iwriter_base_type;

typedef
std::shared_ptr<void> owriter_base_type;

/* writer function type */
template <
  typename T
, typename BufferIter
, typename WriterIter
>
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
, typename WriterIter
>
using owriter_function = std::function <
bool (
  T const &
, OutputIter
, WriterIter
, WriterIter
)>;

/* iwriter type
  Returns false if type could not be
  re-written.
*/
template <
  typename T
, typename BufferIter
, typename WriterIter
>
using iwriter_type = std::shared_ptr<
  iwriter_function <
    T
  , BufferIter
  , WriterIter
  >
>;

/* owriter type */ 
template <
  typename T
, typename OutputIter
, typename WriterIter
>
using owriter_type = std::shared_ptr<
  owriter_function <
    T
  , OutputIter
  , WriterIter
  >
>;

/* set_writer */
template <
  typename T
, typename BufferIter
, typename WriterIter
>
iwriter_base_type
make_iwriter (
  iwriter_function<T,BufferIter,WriterIter> *
);

/* make_writer */
template <
  typename T
, typename OutputIter
, typename WriterIter
>
owriter_base_type
make_owriter (
  owriter_function<T,OutputIter,WriterIter> *
);

/* use_iwriter */
template <
  typename T
, typename BufferIter
, typename WriterIter
, typename Typeid
>
iwriter_type<T,BufferIter,WriterIter>
use_iwriter (
  iwriter_base_type &
, Typeid const &
);

/* use_owriter */
template <
  typename T
, typename OutputIter
, typename WriterIter
, typename Typeid
>
owriter_type<T,OutputIter,WriterIter>
use_owriter (
  owriter_base_type &
, Typeid const &
);

/* rewrite 
template <
  typename T
, typename BufferIter
, typename WriterIter
>
void
rewrite (
  T &
, BufferIter
, BufferIter
, WriterIter
, WriterIter
);

/ * rewrite 
template <
  typename T
, typename OutputIter
, typename WriterIter
>
void
rewrite (
  T &
, OutputIter
, WriterIter
, WriterIter
);*/

} /* typesystems */
#include "./bits/writer.tcc"
#endif
