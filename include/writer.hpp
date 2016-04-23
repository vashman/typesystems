//

#ifndef TYPESYSTEMS_WRITER_HPP
#define TYPESYSTEMS_WRITER_HPP

#include <memory>

namespace typesystems {

template <
  typename T, typename OutputIterator >
class owriter;

template <
  typename T, typename InputIterator >
class iwriter;

/* writer base type
  Typeless storage of writer.
*/
typedef
std::shared_ptr<void> iwriter_base;

typedef
std::shared_ptr<void> owriter_base;

/* output writer */
template <
  typename T, typename OutputIterator >
class owriter {

std::shared_ptr <
std::function < 
  bool (T const &, OutputIterator) >
> func;

public:

/* ctor */
owriter () = default;

/* ctor */
owriter (
  std::function < bool (
    T const &, OutputIterator) > * _func
)
: func (_func) {
}

/* ctor */
explicit
owriter (
  owriter_base & _writer
)
: func ( std::static_pointer_cast <
  std::function < bool (
    T const &, OutputIterator)> >
   (_writer)
){
  if (! _writer) throw std::bad_cast();
}

operator owriter_base() const {
  return std::static_pointer_cast <void>
  (this->func);
}

/* ctor copy */
owriter (
  owriter<T,OutputIterator> const &
) = default;

/* copy assignment */
owriter<T,OutputIterator> &
operator = (
  owriter<T,OutputIterator> const &
) = default;

/* move assignment */
owriter<T,OutputIterator> &
operator = (
  owriter<T,OutputIterator> &&
) = default;

/* ctor move */
owriter (
  owriter<T,OutputIterator> &&
) = default;

/* dtor */
~owriter() = default;

bool
operator ()(
  T const & _var
, OutputIterator _output
) const {
return (*this->func)(_var, _output);
}

}; /* owriter */

/* input writer */
template <
  typename T, typename InputIterator >
class iwriter {

std::shared_ptr<
std::function < 
  bool (
    T&, InputIterator, InputIterator) >
> func;

public:

/* ctor */
iwriter () = default;

/* ctor */
iwriter (
  std::function < bool (
    T&, InputIterator, InputIterator) >
  * _func
) : func (_func) {
}

/* ctor */
explicit
iwriter (
  iwriter_base & _writer
) : func (std::static_pointer_cast <
    std::function < bool (
      T&, InputIterator, InputIterator)>
  > (_writer)
  )
{
  if (! _writer) throw std::bad_cast();
}

operator iwriter_base() const {
  return std::static_pointer_cast <void>
  (this->func);
}

/* ctor copy */
iwriter (
  iwriter<T,InputIterator> const &
) = default;

/* copy assignment */
iwriter<T,InputIterator> &
operator = (
  iwriter<T,InputIterator> const &
) = default;

/* move assignment */
iwriter<T,InputIterator> &
operator = (
  iwriter<T,InputIterator> &&
) = default;

/* ctor move */
iwriter (
  iwriter<T,InputIterator> &&
) = default;

/* dtor */
~iwriter() = default;

bool
operator ()(
  T & _var
, InputIterator _begin
, InputIterator _end
) const {
return (*this->func)(_var,_begin,_end);
}

}; /* input writer */

/* make writer */
template <
  typename T
, typename InputIterator
, typename Function >
iwriter <T,InputIterator>
make_iwriter (
  Function
);

/* make writer */
template <
  typename T
, typename OutputIterator
, typename Function >
owriter <T,OutputIterator>
make_owriter (
  Function
);

/* make writer */
template <
  typename T
, typename InputIterator
, typename Function >
iwriter <T,InputIterator>
make_iwriter (
  Function
, InputIterator const &
);

/* make writer */
template <
  typename T
, typename OutputIterator
, typename Function >
owriter <T,OutputIterator>
make_owriter (
  Function
, OutputIterator const &
);

/* use input writer */
template <
  typename T, typename InputIterator >
bool
use_iwriter (
  T &
, InputIterator
, InputIterator
, iwriter <T,InputIterator> &
);

/* use input writer */
template <
  typename T, typename InputIterator >
bool
use_iwriter (
  T &
, InputIterator
, InputIterator
, iwriter_base &
);

/* use output writer */
template <
  typename T, typename OutputIterator >
bool
use_owriter (
  T const &
, OutputIterator
, owriter<T,OutputIterator> &
);

/* use output writer */
template <
  typename T, typename OutputIterator >
bool
use_owriter (
  T const &
, OutputIterator
, owriter_base &
);

} /* typesystems */
#include "./bits/writer.tcc"
#endif

