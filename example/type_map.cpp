//

//          Copyright Sundeep S. Sangha 2013 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "../include/type_map.hpp"

using typesystems::type_map;
using typesystems::get;

/* Found through ADL.
  using typesystems::begin;
  using typesystems::end;
*/

int main() {
type_map<int, int, char, double> con;

auto iter (begin(con));
auto iter_end (end(con));

int & t (get<char>(con));
int & t1 (get<int>(con));
int & t2 (get<double>(con));

int & t3 (get<0>(con));

--++iter++--;

iter += 2;
iter += iter_end;
iter = iter + 2;
iter = iter + iter_end;
iter -= 2;
iter -= iter_end;
iter = iter - 2;
iter = iter - iter_end;

*iter;
iter[1];

if (iter == iter_end)
{};
if (iter != iter_end)
{};
if (iter < iter_end)
{};
if (iter > iter_end)
{};
if (iter <= iter_end)
{};
if (iter >= iter_end)
{};

return 0;
}
