// explicit_typeid template instance

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_QUALIFIED_TYPEID_TCC
#define TYPESYSTEMS_QUALIFIED_TYPEID_TCC

namespace typesystems {

/* ctor */
template <typename T>
qualified_typeinfo::qualified_typeinfo (
  bits::make_id<T> const &
)
: qualification (bits::get_qualifier<T>())
, id (typeid (T)) {
}


} /* typesystems */
#endif
