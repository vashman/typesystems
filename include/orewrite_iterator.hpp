//

//          Copyright Sundeep S. Sangha 2015 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_OREWRITE_ITERATOR_HPP
#define TYPESYSTEMS_OREWRITE_ITERATOR_HPP

#include <iterator>
#include "type_map.hpp"

namespace typesystems {

/* irewriter iterator */
template <
  typename T
, typename IteratorMap
, typename Writer >
class orewrite_iterator {

typedef std::output_iterator_tag
  iterator_catagory;
typedef T value_type;
typedef std::size_t difference_type;
typedef T* pointer;
typedef T& reference;

IteratorMap iterator_map;
Writer writer;

public:

/* ctor */
orewrite_iterator (
  IteratorMap
, Writer
);

/* ctor copy*/
orewrite_iterator (
  orewrite_iterator <
    T, IteratorMap, Writer >
  const &
) = default;

/* operator copy assignment */
orewrite_iterator <
  T, IteratorMap, Writer > &
operator = (
  orewrite_iterator <
    T, IteratorMap, Writer >
  const &
) = default;

/* ctor move */
orewrite_iterator (
  orewrite_iterator <
    T, IteratorMap, Writer >
  &&
) = default;

/* operator move assignment */
orewrite_iterator <
  T, IteratorMap, Writer > &
operator = (
  orewrite_iterator <
    T, IteratorMap, Writer >
  &&
) = default;

/* dtor */
~orewrite_iterator () = default;

orewrite_iterator <
  T, IteratorMap, Writer > &
operator * ();

orewrite_iterator <
  T, IteratorMap, Writer > &
operator ++ ();

orewrite_iterator <
  T, IteratorMap, Writer >
operator ++ (int);

orewrite_iterator <
  T, IteratorMap, Writer > &
operator = (
  T const &
);

}; /* orewrite iterator */

template <
  typename T
, typename IteratorMap
, typename Writer >
auto
make_orewrite_iterator (
  IteratorMap _itermap
, Writer _writermap
)
-> orewrite_iterator <
  T, IteratorMap, Writer >;

} /* typesystems */
#endif
#include "./bits/orewrite_iterator.tcc"

