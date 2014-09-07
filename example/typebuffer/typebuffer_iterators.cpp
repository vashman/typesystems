#include <iostream>
#include <vector>
#include "../../src/typebuffer.cpp"
#include "../../src/typebuffer_map.cpp"
#include "../../src/total_typeid.cpp"

using std::cout;
using std::endl;
using std::vector;
using typesystems::typebuffer_container;
using typesystems::set_typebuffer;

int main(){
typebuffer_container buffer;

set_typebuffer<int, vector<int> >(buffer);
set_typebuffer<char, vector<char> >(buffer);

typebuffer_container::iterator b = buffer.begin(); 

if (b == buffer.end()){
cout << "end eached right away" << endl;
}

for (; b != buffer.end(); ++b){
cout << "end not reached" << endl;
}

return 0;
}
