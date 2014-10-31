#include <vector>
#include <iostream>
#include "../include/typebuffer.hpp"
#include "person.hpp"
#include "rwperson.hpp"
#include "../include/get_rewriter.hpp"

using typesystems::get_rewriter;

int main(){
typebuffer_container con;
set_typebuffer<int, std::vector<int> >(con);
set_typebuffer<char *, std::vector<> >(con);

/* fill the infomation directly */
typebuffer_interface<int> & buf1 = use_typebuffer<int>(con);
buf.push(24);
buf.push(32);
buf.push(42);

/* add only 2 items so the extra int will be ignored */
typebuffer_interface<> & buf2 = use_typebuffer<>(con);
buf2.push("probi");
buf2.push("otic");

get_rewriter<person> * rwg = new person_rw_get();

/**/
bool rv = rwg->empty<person>();

return 0;
}
