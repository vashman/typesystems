#include <iostream>
#include <vector>
#include "../../include/typebuffer.hpp"

using typesystems::typebuffer;

int main(){
// create typebuffer for int using a vector of ints
typebuffer<const int, std::vector<int> > cbuffer;
typebuffer<volatile int, std::vector<int> > vbuffer;

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
std::cout << "The answer is: " << (cbuffer.next() + vbuffer.next())
  << std::endl;

return 0;
}