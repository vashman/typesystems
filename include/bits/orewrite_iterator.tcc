//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_OREWRITE_ITERATOR_TCC
#define TYPESYSTEMS_OREWRITE_ITERATOR_TCC

namespace typesystems {

/* irewrite iterator ctor */
template <
  typename T
, typename IteratorMap
, typename Writer >
orewrite_iterator <
  T, IteratorMap, Writer >
::orewrite_iterator (
  IteratorMap _itermap
, Writer _writer
)
: iterator_map (_itermap)
, writer (_writer)
{}

template <
  typename T
, typename IteratorMap
, typename Writer >
orewrite_iterator <
  T, IteratorMap, Writer > &
  orewrite_iterator <
    T, IteratorMap, Writer >
::operator * (
){
return *this;
}

template <
  typename T
, typename IteratorMap
, typename Writer >
orewrite_iterator <
  T, IteratorMap, Writer > &
  orewrite_iterator <
    T, IteratorMap, Writer >
::operator ++ (
){
return *this;
}

template <
  typename T
, typename IteratorMap
, typename Writer >
orewrite_iterator <
  T, IteratorMap, Writer >
  orewrite_iterator <
    T, IteratorMap, Writer >
::operator ++ (
  int
){
auto temp_iter (*this);
return temp_iter;
}

template <
  typename T
, typename IteratorMap
, typename Writer >
orewrite_iterator <
  T, IteratorMap, Writer > &
  orewrite_iterator <
    T, IteratorMap, Writer >
::operator = (
  T const & _var
){
this->writer(_var, this->iterator_map);
return *this;
}

template <
  typename T
, typename IteratorMap
, typename Writer >
auto
make_orewrite_iterator (
  IteratorMap _itermap
, Writer _writer
)
-> orewrite_iterator <
  T, IteratorMap, Writer >
{
return
orewrite_iterator <
  T, IteratorMap, Writer >
(_itermap, _writer);
}

} /* typesystems */
#endif

