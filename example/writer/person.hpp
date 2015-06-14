// A custom class used to demostrate
// rewriting.

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

  person &
  operator=(
  person const &
  );

  std::string name;

  int
  get_age(
  ) const;

private:
  int age;
};

person::person(
  int _age
, std::string _name
)
: name(_name)
, age(_age) {
}

int
person::get_age() const {
return this->age;
}

person &
person::operator=(
  person const & _person
){
  if (&_person != this){
  this->name = _person.name;
  this->age = _person.age;
  }
return *this;
}
