//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../../include/explicit_typeid.hpp"

using typesystems::explicit_typeid;
using typesystems::explicit_typeid_type;

int main(){

/* get raw id */
explicit_typeid_type raw_id = explicit_typeid<int>::raw_typeid();

/* compare raw id to type */
explicit_typeid<char>::raw_compare(raw_id);

return 0;
}
