#include <iostream>
#include "../../include/typebuffer_queue.hpp"

using std::cout;
using std::endl;
using typesystems::typebuffer_queue;

void
print(
  typebuffer_queue<int> &
);

int main (){
typebuffer_queue<int> buff;
buff.push(45);
buff.push(12);
print (buff);

cout << endl;
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
  typebuffer_queue<int> & _buff
){
  if (_buff.empty()){
  cout << "Buffer empty" << endl;
  return;
  }
cout
<< _buff.front() << endl
<< _buff.back() << endl;
}
