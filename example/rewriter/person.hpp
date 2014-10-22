// A custom class used to demostrate rewriting.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <string>

class person {
public:
  person(
    int age
  , std::string name
  );

private:
  std::string name;
  int const age;
};

person::person(
  int _age
, string _name
)
  : name(_name)
  , age(_age) {
}
