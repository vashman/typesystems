//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>
#include "../../../include/put_rewriter.hpp"
#include ""
#include "../../../include/explicit_typeid.hpp"

#include "../../../src/rewriter_base.cpp"
#include "../../../src/total_typeid.cpp"
#include "../../../src/typebuffer_map.cpp"
#include "../../../src/typebuffer.cpp"

using typesystems::put_rewriter;
using typesystems::typebuffer_container;
using typesystems::has_typebuffer;
using typesystems::use_typebuffer;
using typesystems::set_typebuffer;
using typesystems::typebuffer_interface;
using typesystems::typebuffer;
using typesystems::empty;

int main(){
typebuffer_container buffer;
set_typebuffer<std::string, std::vector<string> >(buffer);
set_typebuffer<int const, std::vector<int> >(buffer);

put_rewriter<person> * rw = new person_rw_put(1);

person alice(24, "Alice");

/* demote the single person type into base types */
rw->rewrite(alice, buffer);

typebuffer<string, vector<string> > & buff1
  = use_typebuffer<string, vector<string> >(buffer);
typebuffer<int const, vector<int> > & buff2
  = use_typebuffer<int const, vector<int> >(buffer);

std::cout << buff1.next() << " : " << buff2.next() << std::endl;
return 0;
}
