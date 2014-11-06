//

#include <vector>
#include "../../include/typesystem.hpp"

using typesystems::typesystem;
using typesystems::set_typebuffer;

int main() try {

typesystem typesys;

/* add int to the typesystem, and std::vector as the buffer container */
set_typebuffer<int, std::vector<int> >(typesys);

return 0;
} catch (...) {
return 1;
}
