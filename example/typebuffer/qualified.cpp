//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <vector>
#include "../../include/typebuffer.hpp"
#include "../../include/typebuffer_queue.hpp"

using typesystems::typebuffer;
using typesystems::typebuffer_queue;

int main(){
// create typebuffer for int using a vector of ints
typebuffer_queue<
  const int
, std::deque<int>
> cbuffer;

typebuffer_queue<
  volatile int
, std::deque<int>
> vbuffer;

/* use container specfic function by calling on the underlying container.
*/
const int a = 24;
volatile int b = 18;

// push ints to buffer
cbuffer.push(a);

// !!! have to cast to int?
vbuffer.push(int(b));

/* get next variable and print out sum.

The buffers next function
*/
std::cout
<< "The answer is: "
<< (cbuffer.next() + vbuffer.next())
<< std::endl;

return 0;
}
