#include <string>
#include <vector>
#include <iostream>
#include "../../include/typebuffer.hpp"

using typesystems::typebuffer_container;
using typesystems::set_typebuffer;
using typesystems::empty;

int main(){
typebuffer_container con1;
set_typebuffer<std::string, std::vector<std::string> >(con1);

  if (empty<std::string>(con1) == true){
  std::cout << "the buffer con1 does not have any std::string"
    << std::endl;
  }
return 0;
}
