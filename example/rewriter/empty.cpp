//

#include <vector>
#include <iostream>
#include <string>
#include "../../include/typebuffer.hpp"
#include "../../include/get_rewriter.hpp"
#include "rwperson.hpp"

using typesystems::typebuffer_container;
using typesystems::set_typebuffer;
using typesystems::use_typebuffer;
using typesystems::typebuffer_interface;
using typesystems::get_rewriter;

int main() try {
typebuffer_container con;

set_typebuffer<
  int const
, std::vector<int>
>(con);

set_typebuffer<
  std::string
, std::vector<std::string>
>(con);

/* fill the infomation directly */
typebuffer_interface<int const> &
  buf1 = use_typebuffer<int const>(con);
buf1.push(24);
buf1.push(32);
buf1.push(42);

/* add only 2 items so the extra int will be ignored */
typebuffer_interface<std::string> &
  buf2 = use_typebuffer<std::string>(
    con
  );
buf2.push("probi");
buf2.push("otic");

get_rewriter<person> *
  rwg = new person_rw_get();

/**/
bool rv = rwg->empty(con);

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
