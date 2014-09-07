#include <iostream>
#include <vector>
#include "../../src/typebuffer.cpp"

using std::cout;
using std::endl;
using std::vector;
using typesystems::typebuffer;

int main(){
// create typebuffer for int using a vector of ints
typebuffer<int, vector<int> > buffer;

// use container specfic function by calling on the underlying container.
buffer.c.resize(4);
buffer.c.push_back(99);

// push ints to buffer
buffer.push(21);
buffer.push(21);

// get copies of next type and print out sum
cout << "The answer is: " << (buffer.next() + buffer.next()) << endl;

return 0;
}
