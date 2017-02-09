//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../include/type_map.hpp"

using std::tuple;

using typesystems::type_map;
using typesystems::make_type_map;
using typesystems::type_map_cat;
using typesystems::get;

int main() {
type_map <tuple<int,int,int>, int, char, double > con;

type_map <tuple<int, char, char>, int, char, float>
ctor {9, 'A', 'B'};

auto tm = make_type_map<bool, double>(tuple<int, int>{});

auto tm2 = type_map_cat(ctor, tm);

int & t (get<char>(con));
int & t1 (get<int>(con));
int & t2 (get<double>(con));

int & t3 (get<0>(con));

char & t4 (get<char>(ctor));
char & t5 (get<float>(ctor));

return 0;
}
