//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_IREWRITE_ITERATOR_TCC
#define TYPESYSTEMS_IREWRITE_ITERATOR_TCC

namespace typesystems {

/* irewrite iterator ctor */
template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
  irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
::irewrite_iterator (
  IteratorMap _itermap
, Writer _writer
, WriteCheck _check
)
: iterator_map (_itermap)
, writer (_writer)
, check (_check)
, temp (_writer(_itermap))
{}

template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
T&
irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
::operator * (
){
return this->temp;
}

template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
T*
irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
::operator -> (
){
return &this->temp;
}

template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
irewrite_iterator <T, IteratorMap, Writer, WriteCheck> &
  irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
::operator ++ (
){
this->temp = this->writer(this->iterator_map);
return *this;
}

template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
  irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
::operator ++ (
  int
){
auto temp_iter (*this);
this->temp = this->writer(this->iterator_map);
return temp_iter;
}

template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
bool
irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
::operator == (
  irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
  const &
) const {
return this->check(this->iterator_map);
}

template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
bool
operator != (
  irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
  const & _lhs
, irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
  const & _rhs
){
return !(_lhs == _rhs);
}

template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
make_irewrite_iterator (
  IteratorMap _itermap
, Writer _writer
, WriteCheck _check
){
return irewrite_iterator <T, IteratorMap, Writer, WriteCheck>
(_itermap, _writer, _check);
}

} /* typesystems */
#endif

