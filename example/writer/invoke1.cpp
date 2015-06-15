//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>
#include <string>
#include "../../include/owriter.hpp"
#include "../../include/explicit_typeid.hpp"

#include "../../src/iwriter_base.cpp"
#include "../../src/owriter_base.cpp"
#include "../../src/total_typeid.cpp"
#include "../../src/typebuffer_map.cpp"
#include "../../src/typebuffer.cpp"
#include "../../include/typebuffer_queue.hpp"

#include "person_writer.hpp"

using typesystems::owriter;
using typesystems::owriter_container;
using typesystems::add_writer;
using typesystems::use_writer;
using typesystems::typebuffer_container;
using typesystems::has_typebuffer;
using typesystems::use_typebuffer;
using typesystems::set_typebuffer;
using typesystems::typebuffer;
using typesystems::typebuffer_queue;
using typesystems::typebuffer;
using typesystems::empty;

int main() try {
typebuffer_container buffer;
set_typebuffer<
  std::string
, typebuffer_queue<std::string>
> (buffer);

set_typebuffer<
  int const
, typebuffer_queue<int>
> (buffer);

owriter_container writers;
add_writer<person_writer>(writers);

person alice(24, "Alice");

owriter<person> & writer
= use_writer<person>(writers);

/* demote the single person type into base types */
writer.put(alice, buffer, writers);

typebuffer<std::string> &
buff1 = use_typebuffer<std::string>
(buffer);

typebuffer<int const> &
buff2 = use_typebuffer<int const>
(buffer);

std::cout
<< buff1.next()
<< " : "
<< buff2.next()
<< std::endl;

return 0;
} catch (
  typesystems::no_buffer const & _e
) {
std::cerr << _e.what();
return 1;

} catch (...) {
std::cerr << "";
return 1;
}
