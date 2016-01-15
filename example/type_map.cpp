#include "../include/type_map.hpp"

using typesystems::type_map;
using typesystems::get;

int main() {
type_map<int, int, char, double> con;

auto iter (typesystems::begin(con));

auto itere (typesystems::end(con));

// auto t (get<int>(con));

--++iter++--;

iter += 2;
iter += itere;
iter = iter + 2;
iter = iter + itere;
iter -= 2;
iter -= itere;
iter = iter - 2;
iter = iter - itere;

*iter;
iter[1];

if (iter == itere)
{};
if (iter != itere)
{};
if (iter < itere)
{};
if (iter > itere)
{};
if (iter <= itere)
{};
if (iter >= itere)
{};

return 0;
}
