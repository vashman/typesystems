//
#include <vector>
#include <iterator>
#include <tuple>
#include <cassert>
#include "../include/irewrite_iterator.hpp"
#include "../include/orewrite_iterator.hpp"

using typesystems::make_orewrite_iterator;
using typesystems::make_irewrite_iterator;
using typesystems::make_type_map;
using typesystems::get;

template <typename It>
struct check_iter {

It const it;

check_iter (
  It _it
) : it (_it){
}

template <typename Map>
bool
operator ()(Map const & _map) const {
return (get<int>(_map) == this->it);
}
};

int main() {

std::vector<int> con;

auto oiter =
  make_orewrite_iterator <char> (
  make_type_map<int> (
    std::make_tuple (
      std::back_inserter(con)
    )
  )

, [] (
    char const & _var
  , decltype( make_type_map<int> (
    std::make_tuple (
      std::back_inserter(con)
    )
  )) & _map
  ){
  auto& iter = get<int>(_map);
  *iter = static_cast<int>(_var);
  ++iter;
  }
);

*oiter++ = 'A';
assert(con[0] == 65);

auto iiter =
  make_irewrite_iterator <char> (
  make_type_map<int> (
    std::make_tuple (begin(con))
  )

, [] ( decltype ( make_type_map<int> (
    std::make_tuple (begin(con))
  )) & _map
  ) -> char {
  auto& iter = get<int>(_map);
  return static_cast<char>(*iter++);
  }

, check_iter <decltype(end(con))>
  (end(con))
);

assert (iiter != iiter);

char ch = *iiter;
++iiter;
assert (ch == 'A');

return 0;
}
