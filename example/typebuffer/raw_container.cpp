//

//

#include <iostream>
#include <vector>
#include "../../include/typebuffer.hpp"

using typesystems::typebuffer;

int main(){

typebuffer<int, std::vector<int> > buffer;

/* retrive a referance to the container */
std::vector<int> & con = buffer.get_container();

/* use specfic function by calling on the underlying container. */
con.resize(4);
con.push_back(30);

// push ints to buffer
buffer.push(5);
buffer.push(7);

// get copies of next type and print out sum
std::cout << "The answer is: "
<< (buffer.next() + buffer.next() + buffer.next()) << std::endl;

return 0;
}
