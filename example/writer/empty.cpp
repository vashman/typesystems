//

#include <vector>
#include <iostream>
#include <string>
#include "../../include/typebuffer.hpp"
#include "../../include/typebuffer_queue.hpp"
#include "../../include/iwriter.hpp"
#include "person_writer.hpp"

using typesystems::typebuffer_container;
using typesystems::typebuffer_queue;
using typesystems::set_typebuffer;
using typesystems::use_typebuffer;
using typesystems::typebuffer;
using typesystems::iwriter;
using typesystems::iwriter_container;

int main() try {
typebuffer_container con;
iwriter_container wcon;

set_typebuffer<
  int
, typebuffer_queue<int>
> (con);

set_typebuffer<
  std::string
, typebuffer_queue<std::string>
> (con);

/* fill the infomation directly */
typebuffer<int> &
buf1 = use_typebuffer<int>(con);
buf1.push(24);
buf1.push(32);
buf1.push(42);

/* add only 2 items so the extra int will be ignored */
typebuffer<std::string> &
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
