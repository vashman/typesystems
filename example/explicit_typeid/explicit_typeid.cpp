#include <iostream>
#include "../../include/explicit_typeid.hpp"
#include "../../src/total_typeid.cpp"

using std::cout;
using std::endl;
using typesystems::explicit_typeid;

class A{
public:
  typedef int value_int;
};

int main(){
// make ids for basic types
explicit_typeid<char> id_char;
explicit_typeid<char const> cc;
explicit_typeid<int> id_int;
explicit_typeid<int volatile> iv;
explicit_typeid<A> id_A;
explicit_typeid<A> some_type;

//compare ids
  if (explicit_typeid<char>::compare(id_int)){
  cout << "char and int are the same" << endl;
  } else {
  cout << "char is not equal to int" << endl;
  }

  if (explicit_typeid<char>::compare(id_A)){
  cout << "char and class A are the same" << endl;
  } else {
  cout << "char is not equal to A" << endl;
  }

  if (explicit_typeid<A>::compare(some_type)){
  cout << "A is of type A" << endl;
  } else {
  cout << "A is not equal to A" << endl;
  }

  if ( ! explicit_typeid<char>::compare(cc)){
  cout << "char is not equal to const char" << endl;
  } else {
  cout << "const char and char are the same" << endl;
  }

  if (explicit_typeid<int>::compare(iv)){
  cout << "int and volatile int are the same" << endl;
  } else {
  cout << "int and volatile int are differnt" << endl;
  }

  if (explicit_typeid<int>::compare<typename A::value_int>()){
  cout << "int is equal to typedef int" << endl;
  } else {
  cout << "int and typedef of int are not the same" << endl;
  }
return 0;
}
