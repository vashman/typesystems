#include <iostream>
#include <string>
#include "../../include/typebuffer.hpp"
#include "../../include/typebuffer_queue.hpp"
#include "person_writer.hpp"

using std::string;
using typesystems::typebuffer_queue;
using typesystems::typebuffer_container;
using typesystems::owriter_container;
using typesystems::rewrite;
using typesystems::owriter;
using typesystems::add_writer;
using typesystems::set_typebuffer;

int main(){
typebuffer_container buffer;
owriter_container owrite;
set_typebuffer<int, typebuffer_queue<int>>(buffer);
set_typebuffer<string, typebuffer_queue<string>>(buffer);
add_writer<person_writer>(owrite);

person p(23, "Alive Bob");
rewrite(p, buffer, owrite);
return 0;
}
