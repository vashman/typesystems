#include <iostream>
#include "../../include/explicit_typeid.hpp"

using typesystems::explicit_typeid;

int main(){

  /* produce false */
  if (explicit_typeid<int>::compare<int const>()){
  } else {
  std::cout << "int and const int differ." << std::endl;
  }

  if (explicit_typeid<int>::compare<int volatile>()){
  std::cout << "int and volatile int are the same" << std::endl;
  } else {
  std::cout << "int and volatile int are differnt" << std::endl;
  }

return 0;
}
