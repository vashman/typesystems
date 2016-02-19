// static counter class for explicit_type_id

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_BITS_QUALIFIED_TYPES_HPP
#define TYPESYSTEMS_BITS_QUALIFIED_TYPES_HPP

namespace typesystems {
namespace bits {

enum class qualified_type : int {
  const_type = 0x00
, volatile_type = 0x01
, none = 0x04
};

/* get_qualifier */
template <typename T>
qualified_type
get_qualifier (){
qualified_type temp;
temp = qualified_type::none;
return temp;
}

} /* bits */ } /* typesystems */
#endif

