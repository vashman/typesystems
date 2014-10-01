//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_BITS_TOTAL_TYPEID_HPP
#define TYPESYSTEMS_BITS_TOTAL_TYPEID_HPP

#include <cstddef>
/*
using std::size_t
*/
#include <limits>
/*
using std::min
*/

namespace typesystems {
namespace bits{

/* total_typeid
typesystem total id provides the id type, and the method to increment the
type.
*/
class total_typeid{
public:
  typedef std::size_t id_type;

  /*
  Increments id and returns copy.
  */
  static id_type
  next_id();
private:
  static id_type total_id;
};

} /* bits */ } /* typesystems */
#endif
