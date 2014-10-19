// A custom class used to demostrate rewriting.

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
