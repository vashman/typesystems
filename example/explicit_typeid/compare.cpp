#include <iostream>
#include "../../include/explicit_typeid.hpp"

using typesystems::explicit_typeid;

class A{};

class B : public A{};

int main(){

  if (explicit_typeid<char>::compare<int>()){
  std::cout << "char and int are the same" << std::endl;
  } else {
  std::cout << "char is not equal to int" << std::endl;
  }

  if (explicit_typeid<A>::compare<A>()){
  std::cout << "class A is the same as A." << std::endl;
  }

  if (explicit_typeid<A>::compare<B>()){
  } else {
  std::cout << "class A is not the same as B." << std::endl;
  }

return 0;
}
