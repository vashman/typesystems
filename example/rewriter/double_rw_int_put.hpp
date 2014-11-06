//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <limits>
#include <iomanip>
#include <cmath>
#include "../../include/put_rewriter.hpp"

class double_rw_int_put : public typesystems::put_rewriter<double>{
public:
  explicit
  double_rw_int_put(
    std::size_t _refs = 0
  );

  virtual bool
  do_rewrite(
    double const & _value
  , typesystems::typebuffer_container const & _buffers
  ) const;

private:
  static typesystems::explicit_typeid_type const array[1];
};

/**/
double_rw_int_put::double_rw_int_put(
  std::size_t _refs
)
  : typesystems::put_rewriter<double> (
      array
    , static_cast<std::size_t>(1)
    , _refs) {
}

/**/
bool
double_rw_int_put::do_rewrite(
  double const & _value
, typesystems::typebuffer_container const & _buffers
) const {
  /* check if the int buffer is present */
  if (typesystems::has_typebuffer<int>(_buffers) == false){
  return false;
  }
/* split the value before and after the decimal */
double chara;
double manti = std::modf(_value, & chara);
typesystems::typebuffer_interface<int> & buffer
    = typesystems::use_typebuffer<int>(_buffers);

try {
  while (std::numeric_limits<int>::max() < chara){
  buffer.push(static_cast<int>(chara - std::numeric_limits<int>::max()));
  chara -= std::numeric_limits<int>::max();
  }
buffer.push(static_cast<int>(chara));
    
  while (std::numeric_limits<int>::max() < manti){
  buffer.push(static_cast<int>(manti - std::numeric_limits<int>::max()));
  manti -= std::numeric_limits<int>::max();
   }
buffer.push(static_cast<int>(manti));
  } catch (...){
  return false;
  }
return true;
}

/**/
typesystems::explicit_typeid_type const double_rw_int_put::array[]
  = {
     typesystems::explicit_typeid<int>::raw_typeid()
  };
