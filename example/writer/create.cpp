//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../../include/iwriter.hpp"
#include "../../include/owriter.hpp"
#include "person_writer.hpp"

using typesystems::owriter;
using typesystems::iwriter;

int main(){
iwriter<person> *
  rwp = new person_writer();

owriter<person> *
  rwg = new person_writer();
return 0;
}
