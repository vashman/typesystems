//

#ifndef TYPESYSTEMS_WRITER_TCC
#define TYPESYSTEMS_WRITER_TCC

#include <utility>
#include <algorithm>
#include "../type_traits.hpp"

namespace typesystems {

/* make writer */
template <
  typename T
, typename InputIterator
, typename Function >
iwriter <T,InputIterator>
make_iwriter (
  Function _func
){
return iwriter <T,InputIterator> (
  new std::function <
    bool
    (T&, InputIterator, InputIterator) >
  (_func)
);
}

/* make writer */
template <
  typename T
, typename OutputIterator
, typename Function >
owriter <T,OutputIterator>
make_owriter (
  Function _func
){
return owriter <T,OutputIterator> (
  new std::function <
    bool (T const &, OutputIterator) >
  (_func)
);
}

/* make writer */
template <
  typename T
, typename InputIterator
, typename Function >
iwriter <T,InputIterator>
make_iwriter (
  Function _func
, InputIterator const & // unused
){
return
make_iwriter<T,InputIterator> (_func);
}

/* make writer */
template <
  typename T
, typename OutputIterator
, typename Function >
owriter <T,OutputIterator>
make_owriter (
  Function _func
, OutputIterator const & // unused
){
return
make_owriter <T,OutputIterator> (_func);
}

/* use input writer */
template <
  typename T, typename InputIterator >
bool
use_iwriter (
  T & _var
, InputIterator _iter
, InputIterator _end
, iwriter <T,InputIterator> & _writer
){
return _writer (_var, _iter, _end);
}

/* use input writer */
template <
  typename T, typename InputIterator >
bool
use_iwriter (
  T & _var
, InputIterator _iter
, InputIterator _end
, iwriter_base & _writer
){
auto t (
  static_cast<iwriter<T,InputIterator>>
  (_writer) );

return
use_iwriter (
  _var
, _iter
, _end
, t
);
}

/* use output writer */
template <
  typename T, typename OutputIterator >
bool
use_owriter (
  T const & _var
, OutputIterator _iter
, owriter<T,OutputIterator> & _writer
){
return _writer (_var, _iter);
}

/* use output writer */
template <
  typename T, typename OutputIterator >
bool
use_owriter (
  T const & _var
, OutputIterator _iter
, owriter_base & _writer
){
auto t =  static_cast<owriter<T,OutputIterator>>
  (_writer);

return
use_owriter (
  _var
, _iter
, t);
}

} /* typesystems */
#endif

