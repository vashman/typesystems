#include <string>
#include <vector>
#include <iostream>
#include "../../include/typebuffer.hpp"
#include "../../include/typebuffer_adapter.hpp"

using typesystems::typebuffer_container;
using typesystems::typebuffer_adapter;
using typesystems::set_typebuffer;
using typesystems::clear;

int main(){
typebuffer_container con1;
set_typebuffer<
  std::string
, typebuffer_adapter<std::string>
>(con1);

set_typebuffer<
  int
, typebuffer_adapter<int>
>(con1);

/* clear std::string data in the buffer */
clear<std::string>(con1);

/* clear all data in the buffer */
clear(con1);

return 0;
}
