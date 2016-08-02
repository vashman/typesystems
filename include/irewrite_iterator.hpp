//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_IREWRITE_ITERATOR_HPP
#define TYPESYSTEMS_IREWRITE_ITERATOR_HPP

#include <iterator>
#include "type_map.hpp"

namespace typesystems {

/* irewriter iterator */
template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
class irewrite_iterator {

typedef std::input_iterator_tag
  iterator_catagory;
typedef T value_type;
typedef std::size_t difference_type;
typedef T* pointer;
typedef T& reference;

IteratorMap iterator_map;
Writer writer;
WriteCheck check;

T temp;

public:

/* ctor */
irewrite_iterator (
  IteratorMap
, Writer
, WriteCheck
);

/* ctor copy*/
irewrite_iterator (
  irewrite_iterator <
    T, IteratorMap, Writer, WriteCheck >
  const &
) = default;

/* operator copy assignment */
irewrite_iterator <
  T, IteratorMap, Writer, WriteCheck > &
operator = (
  irewrite_iterator <
    T, IteratorMap, Writer, WriteCheck >
  const &
) = default;

/* ctor move */
irewrite_iterator (
  irewrite_iterator <
    T, IteratorMap, Writer, WriteCheck >
  &&
) = default;

/* operator move assignment */
irewrite_iterator <
  T, IteratorMap, Writer, WriteCheck > &
operator = (
  irewrite_iterator <
    T, IteratorMap, Writer, WriteCheck >
  &&
) = default;

/* dtor */
~irewrite_iterator () = default;

T&
operator * ();

T*
operator -> ();

irewrite_iterator <
  T, IteratorMap, Writer, WriteCheck > &
operator ++ ();

irewrite_iterator <
  T, IteratorMap, Writer, WriteCheck >
operator ++ (int);

bool
operator == (
  irewrite_iterator <
    T, IteratorMap, Writer, WriteCheck >
  const &
) const;

}; /* irewrite iterator */

template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
bool
operator != (
  irewrite_iterator <
    T, IteratorMap, Writer, WriteCheck >
  const &
, irewrite_iterator <
    T, IteratorMap, Writer, WriteCheck >
  const &
);

template <
  typename T
, typename IteratorMap
, typename Writer
, typename WriteCheck >
auto
make_irewrite_iterator (
  IteratorMap
, Writer
, WriteCheck
)
-> irewrite_iterator <
  T, IteratorMap, Writer, WriteCheck >;

} /* typesystems */
#endif
#include "./bits/irewrite_iterator.tcc"

