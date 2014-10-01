//

//

#include <vector>
#include "../../include/typebuffer.hpp"

using typesystems::typebuffer;
using typesystems::typebuffer_interface;

int main(){

std::vector<int> vec;

/* create typebuffer for int using a vector of ints */
typebuffer<int, std::vector<int> > buffer;

/* copied container for new typebuffer */
typebuffer<int, std::vector<int> > copied_buffer(vec);

/* create a typebuffer_interface pointing to new typebuffer */
typebuffer_interface<char> * char_buff
  = new typebuffer<char, std::vector<char> >();

typebuffer_interface<int> * int_buff = &buffer;

return 0;
}
