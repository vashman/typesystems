#include <iostream>
#include "../../include/explicit_typeid.hpp"

using typesystems::explicit_typeid;

int main(){

typedef int some_type;

  /* true statement */
  if (explicit_typeid<int>::compare<some_type>()){
  std::cout << "some_type is a int." << std::endl;
  }

/* the equivilent of the above */
explicit_typeid<int>::compare<int>();

return 0;
}
