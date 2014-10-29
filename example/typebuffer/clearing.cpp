#include <string>
#include <vector>
#include <iostream>
#include "../../include/typebuffer.hpp"

using typesystems::typebuffer_container;
using typesystems::set_typebuffer;
using typesystems::clear;

int main(){
typebuffer_container con1;
set_typebuffer<std::string, std::vector<std::string> >(con1);
set_typebuffer<int, std::vector<int> >(con1);

/* clear std::string data in the buffer */
clear<std::string>(con1);

/* clear all data in the buffer */
clear(con1);

return 0;
}
