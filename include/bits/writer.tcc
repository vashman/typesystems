//

#ifndef TYPESYSTEMS_WRITER_TCC
#define TYPESYSTEMS_WRITER_TCC

#include <utility>
#include <algorithm>
#include "../type_traits.hpp"
#include "../typelist.hpp"

namespace typesystems {

/* set input writer */
template <
  typename T
, typename BufferIter
, typename WriterIter
>
iwriter_base_type
make_iwriter (
  iwriter_function<T,BufferIter, WriterIter> * _func
){
return iwriter_base_type(_func);
}

/* set output writer */
template <
  typename T
, typename OutputIter
, typename WriterIter
>
owriter_base_type
make_owriter (
  owriter_function<T,OutputIter,WriterIter> * _func
){
return owriter_base_type(_func);
}

/* use_iwriter */
template <
  typename T
, typename BufferIter
, typename WriterIter
, typename Typeid
>
iwriter_type<T,BufferIter,WriterIter>
use_iwriter (
  iwriter_base_type & _writer
, Typeid const & _type
){
  if (
    !_writer
  ||
    qualified_typeid<T>() != _type
  )
  throw std::bad_cast();

return std::static_pointer_cast <
  iwriter_function<T,BufferIter,WriterIter>
> (_writer);
}

/* use_owriter */
template <
  typename T
, typename OutputIter
, typename WriterIter
, typename Typeid
>
owriter_type<T,OutputIter,WriterIter>
use_owriter (
  owriter_base_type & _writer
, Typeid const & _type
){
  if (
    !_writer
  ||
    qualified_typeid<T>() != _type
  )
  throw std::bad_cast();

return std::static_pointer_cast <
  owriter_function<T,OutputIter,WriterIter>
> (_writer);

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
>
void
rewrite_dispatch (
  T & _var
, BufferIter _buffer
, BufferIter _buffer_end
, WriterIter _writer
, WriterIter _writer_end
, std::false_type const
){
WriterIter iter = get_writer<T>(_writer, _writer_end);
  if (iter == _writer_end) throw ;
auto writer = use_iwriter<T,BufferIter,WriterIter>(iter);

  if (false == writer(_var, _buffer, _buffer_end, _writer, _writer_end)){
  throw ;
  }
}

/ * input rewrite
  If the container type is present,
  write the type.
* /
template <
  typename T
, typename BufferIter
, typename WriterIter
>
void
rewrite_dispatch (
  T & _var
, BufferIter _buffer
, BufferIter _buffer_end
, WriterIter _writer
, WriterIter _writer_end
, std::true_type const
){
_var = *_buffer++;
}

/ * output rewrite dispatch * /
template <
  typename T
, typename BufferOutput
, typename WriterIter
>
void
rewrite_dispatch (
  T const & _var
, BufferOutput _output
, WriterIter _writer
, WriterIter _writer_end
, std::true_type const
){
*_output = _var;
}

/ * output rewrite dispatch * /
template <
  typename T
, typename BufferOutput
, typename WriterIter
>
void
rewrite_dispatch (
  T const & _var
, BufferOutput _output
, WriterIter _writer
, WriterIter _writer_end
, std::false_type const
){
auto iter = get_writer<T>(_writer, _writer_end);
  if (iter == _writer_end) throw ;
auto writer = use_owriter<T,BufferOutput,WriterIter>(iter);
writer(_var, _output, _writer, _writer_end);
}

} / * bits * /

/ * rewrite input * /
template <
  typename T
, typename BufferIter
, typename WriterIter
>
void
rewrite (
  T & _var
, BufferIter _buffer
, BufferIter _buffer_end
, WriterIter _writer
, WriterIter _writer_end
){
bits::rewrite_dispatch (
  _var
, _buffer
, _buffer_end
, _writer
, _writer_end
, use_typelist<has_type, T, get_typelist<typename BufferIter::value_type>>::value 
);
}

/ * rewrite output * /
template <
  typename T
, typename BufferOutput
, typename WriterIter
>
void
rewrite (
  T const & _var
, BufferOutput _output
, WriterIter _writer
, WriterIter _writer_end
){
bits::rewrite_dispatch (
  _var
, _output
, _writer
, _writer_end
, use_typelist<has_type, T, get_typelist<typename BufferOutput::value_type>>::value 
);
}*/

} /* typesystems */
#endif
