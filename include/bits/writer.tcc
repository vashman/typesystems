//

#ifndef TYPESYSTEMS_WRITER_TCC
#define TYPESYSTEMS_WRITER_TCC

#include <utility>
#include <algorithm>
#include "../type_traits.hpp"

namespace typesystems {

/* make writer */
template <
  typename BufferIter
, typename OutputIter
, typename Function >
writer_type<BufferIter,OutputIter>
make_writer (
  Function _func
){
return
writer_type <BufferIter,OutputIter> (
  new writer_function <
    BufferIter, OutputIter >(_func)
);
}

/* use writer */
template <
  typename BufferIter
, typename OutputIter >
writer_type <BufferIter, OutputIter>
use_writer (
  writer_base_type & _writer
){
  if (! _writer) throw std::bad_cast();

return writer_type<
  BufferIter, OutputIter >(_writer);
}

/* use writer */
template <
  typename BufferIter
, typename OutputIter >
writer_type <BufferIter, OutputIter>
use_writer (
  writer_type <BufferIter, OutputIter>
  & _writer
){
  if (! _writer) throw std::bad_cast();

return _writer;
}

/*namespace bits {
/ * input rewrite
  If the container type is not present, 
  rewrite the type.
* /
template <
  typename T
, typename BufferIter
, typename WriterIter
, typename Find >
bool
rewrite_dispatch (
  T & _var
, BufferIter _buffer
, BufferIter _buffer_end
, WriterIter _writer
, WriterIter _writer_end
, Find _find
, std::false_type const
){
WriterIter iter = _find (
  _writer
, _writer_end
, qualified_typeid<T>() );

  if (iter == _writer_end) return false;

auto writer = use_iwriter <
x  T, BufferIter, WriterIter, Find >
  (*iter);

return writer (
  _var, _buffer, _buffer_end, _writer
, _writer_end, _find );
}

/ * input rewrite
  If the container type is present,
  write the type.
* /
template <
  typename T
, typename BufferIter
, typename WriterIter
, typename Find >
bool
rewrite_dispatch (
  T & _var
, BufferIter _buffer
, BufferIter _buffer_end
, WriterIter const &
, WriterIter const &
, Find const &
, std::true_type const
){
  if (_buffer == _buffer_end)
  return false;
_var = *_buffer++;
return true;
}

/ * output rewrite dispatch * /
template <
  typename T
, typename BufferOutput
, typename WriterIter
, typename Find >
bool
rewrite_dispatch (
  T const & _var
, BufferOutput _output
/ * un-used types are not copied nor
modified. * /
, WriterIter const &
, WriterIter const &
, Find const &
, std::true_type const
){
*_output = _var;
return true;
}

/ * output rewrite dispatch * /
template <
  typename T
, typename BufferOutput
, typename Find
, typename WriterIter >
bool
rewrite_dispatch (
  T const & _var
, BufferOutput _output
, WriterIter _writer
, WriterIter _writer_end
, Find _find
, std::false_type const
){
WriterIter iter = _find (
  _writer
, _writer_end
, qualified_typeid<T>() );
  if (iter == _writer_end) return false;
  
auto writer = use_owriter <
  T, BufferOutput, WriterIter, Find >
  (*iter);
return writer(
  _var
, _output
, _writer
, _writer_end
, _find
);
}

} / * bits */

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
  BufferIter _begin, BufferIter _end
, OutputIter _output
, WriterIter _writer
, WriterIter _writer_end
, GetWriter _get_writer
){
  if (has_type<T,Ts...>::value){
    if (empty<T>(_begin, _end))
    return qualified_typeid<void>();
  *_output = *_begin;
  return qualified_typeid<T>();
  }
auto writer (
  use_writer<BufferIter,OutputIter> (
    _get_writer(
      _writer, _writer_end
    , qualified_typeid<T>() ) ));
return writer(_begin,_end,_output);
}

} /* typesystems */
#endif
