#include "../include/type_map.hpp"

using typesystems::type_map;
using typesystems::get;

int main() {
type_map<int, int, char, double> con;

auto iter (typesystems::begin(con));

auto itere (typesystems::end(con));

// auto t (get<int>(con));

return 0;
}
