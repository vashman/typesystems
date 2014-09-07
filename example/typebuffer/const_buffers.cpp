#include <iostream>
#include <vector>
#include "../../src/typebuffer.cpp"

using std::cout;
using std::endl;
using std::vector;
using typesystems::typebuffer;

int main(){
// create typebuffer for int using a vector of ints
typebuffer<const int, vector<int> > buffer;

// use container specfic function by calling on the underlying container.
const int a = 24;
const int b = 18;

// push ints to buffer
buffer.push(a);
buffer.push(b);

// get copies of next type and print out sum
cout << "The answer is: " << (buffer.next() + buffer.next()) << endl;

return 0;
}
