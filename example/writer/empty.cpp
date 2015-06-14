//

#include <vector>
#include <iostream>
#include <string>
#include "../../include/typebuffer.hpp"
#include "../../include/iwriter.hpp"
#include "person_writer.hpp"

using typesystems::typebuffer_container;
using typesystems::set_typebuffer;
using typesystems::use_typebuffer;
using typesystems::typebuffer_interface;
using typesystems::iwriter;
using typesystems::iwriter_container;

int main() try {
typebuffer_container con;
iwriter_container wcon;

set_typebuffer<int, std::vector<int> >
(con);

set_typebuffer<
  std::string
, std::vector<std::string>
>(con);

/* fill the infomation directly */
typebuffer_interface<int> &
  buf1 = use_typebuffer<int>(con);
buf1.push(24);
buf1.push(32);
buf1.push(42);

/* add only 2 items so the extra int will be ignored */
typebuffer_interface<std::string> &
buf2 = use_typebuffer<std::string>(con);
buf2.push("probi");
buf2.push("otic");

iwriter<person> *
  rwg = new person_writer();

/**/
bool rv = rwg->empty(con, wcon);

return 0;
} catch (
  typesystems::no_buffer const & _e
) {
std::cerr << _e.what();
return 1;

} catch (...) {
std::cerr << "Unknown exception thrown.\n";
return 1;
}
