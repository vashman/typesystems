//

//

#include <iostream>
#include <vector>
#include "../../src/typebuffer.cpp"
#include "../../src/typebuffer_map.cpp"
#include "../../src/total_typeid.cpp"

using std::cout;
using std::endl;
using std::vector;
using typesystems::typebuffer_container;
using typesystems::typebuffer;
using typesystems::typebuffer_interface;
using typesystems::set_typebuffer;
using typesystems::has_typebuffer;
using typesystems::use_typebuffer;
using typesystems::empty;
using typesystems::clear;

int main(){
typebuffer_container buffers;

set_typebuffer<int, vector<int> >(buffers);
set_typebuffer<char, vector<char> >(buffers);

  if (has_typebuffer<int>(buffers) == false){
  cout << "" << endl;
  return 1;
  }

  if (has_typebuffer<char>(buffers) == false){
  cout << "" << endl;
  return 1;
  }

typebuffer_interface<int> & int_buff = use_typebuffer<int>(buffers);
typebuffer_interface<char> & char_buff = use_typebuffer<char>(buffers);

int_buff.push(42);
char_buff.push('A');

// run 2 times
for (int i = 0; i<2; ++i){
cout << "loop count: " << i << endl;

  if (empty<int>(buffers)){
  cout << "there are no int types" << endl;
  } else {
  cout << "there are int types" << endl;
  } 

  if (empty<char>(buffers)){
  cout << "there are no char tyoes" << endl;
  } else {
  cout << "there are char types" << endl;
  }

  /* clear all buffers */
  clear(buffers);

}// end outer for

return 0;
}
