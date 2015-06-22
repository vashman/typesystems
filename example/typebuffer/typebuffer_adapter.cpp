#include <iostream>
#include "../../include/typebuffer_adapter.hpp"

using std::cout;
using std::endl;
using typesystems::typebuffer_adapter;

void
print(
  typebuffer_adapter<int> &
);

int main (){
typebuffer_adapter<int> buff;
buff.push(45);
buff.push(12);

print (buff);
buff.pop();
print (buff);
cout
  << "next is: "
  << buff.next()
  << endl;
print(buff);

return 0;
}

void
print(
  typebuffer_adapter<int> & _buff
){
  if (_buff.empty()){
  cout << "Buffer empty" << endl;
  return;
  }
cout
<< _buff.front() << endl
<< _buff.back() << endl;
}
