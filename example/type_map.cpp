//

//          Copyright Sundeep S. Sangha 2013 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../include/type_map.hpp"

using typesystems::type_map;
using typesystems::get;

int main() {
type_map <std::tuple<int,int,int>, int, char, double > con;

type_map <std::tuple<int, char, char>, int, char, float>
ctor (9, 'A', 'B');

int & t (get<char>(con));
int & t1 (get<int>(con));
int & t2 (get<double>(con));

int & t3 (get<0>(con));

char & t4 (get<char>(ctor));
char & t5 (get<float>(ctor));

return 0;
}
