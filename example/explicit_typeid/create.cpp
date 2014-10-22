//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../../include/explicit_typeid.hpp"

using typesystems::explicit_typeid;
using typesystems::explicit_typeid_type;

int main(){
explicit_typeid_type id = explicit_typeid<float>::raw_typeid();

return 0;
}
