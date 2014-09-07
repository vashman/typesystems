//

//

#include <iostream>
#include <string>
#include <vector>
#include "../../../include/put_rewriter.hpp"
#include "../../../include/explicit_typeid.hpp"

#include "../../../src/rewriter_base.cpp"
#include "../../../src/total_typeid.cpp"
#include "../../../src/typebuffer_map.cpp"
#include "../../../src/typebuffer.cpp"

using std::string;
using std::vector;
using typesystems::put_rewriter;
using typesystems::typebuffer_container;
using typesystems::has_typebuffer;
using typesystems::use_typebuffer;
using typesystems::set_typebuffer;
using typesystems::typebuffer_interface;
using typesystems::typebuffer;
using typesystems::empty;

class person {
public:
  person(int age, string name);

  string name;
  int const age;
};

class person_rw_put : public put_rewriter<person>{
public:
  person_rw_put(
    std::size_t _refs = 0
  )
    : put_rewriter<person>(
      array
      , static_cast<std::size_t>(2)
      , _refs) {
  }

private:
  virtual bool
  do_rewrite(
    person const & _person
  , typebuffer_container const & _buffers
  ) const {
    if (!has_typebuffer<int const>(_buffers)
       || !has_typebuffer<string>(_buffers)
    ){
    return false;
    }
  typebuffer_interface<int const> & buff1
      = use_typebuffer<int const>(_buffers);
  typebuffer_interface<string> & buff2
      = use_typebuffer<string>(_buffers);

  buff1.push(_person.age);
  buff2.push(string(_person.name));
  return true;
  }

  static typesystems::explicit_typeid_type const array[2];
};

typesystems::explicit_typeid_type const person_rw_put::array[]
  = { typesystems::explicit_typeid<string>::raw_typeid()
   , typesystems::explicit_typeid<int const>::raw_typeid()
   };

int main(){
typebuffer_container buffer;
set_typebuffer<string, vector<string> >(buffer);
set_typebuffer<int const, vector<int> >(buffer);

put_rewriter<person> * rw = new person_rw_put(1);

person alice(24, "Alice");

rw->rewrite(alice, buffer);

typebuffer<string, vector<string> > & buff1
  = use_typebuffer<string, vector<string> >(buffer);
typebuffer<int const, vector<int> > & buff2
  = use_typebuffer<int const, vector<int> >(buffer);

std::cout << buff1.next() << " : " << buff2.next() << std::endl;
return 0;
}

person::person(int _age, string _name) : name(_name), age(_age){}
