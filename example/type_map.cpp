#include "../include/type_map.hpp"

using typesystems::type_map;
using typesystems::type_map_iterator;
using typesystems::get;

int main() {
type_map<int, int, char, double> con;

type_map_iterator<int,int,char,double>
iter (typesystems::begin(con));

type_map_iterator<int,int,char,double>
itere (typesystems::end(con));

// auto t (get<int>(con));

return 0;
}