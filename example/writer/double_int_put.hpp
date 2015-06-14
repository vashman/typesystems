//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <limits>
#include <iomanip>
#include <cmath>
#include "../../include/owriter.hpp"

class double_int_put
  : public typesystems
::owriter<double> {
public:
  explicit
  double_int_put();

  virtual void
  do_put(
    double const & _value
  , typesystems::typebuffer_container
    const & _buffer
  , typesystems::owriter_container
    const & _writer
  ) const;

private:
  void
  put_part(
    double & _value
  , typesystems::typebuffer_container
    const & _buffer
  , typesystems::owriter_container
    const & _writer
  );
};

/* ctor */
double_int_put::double_int_put()
: typesystems::owriter<double> () {
}

void
double_int_put::put_part(
  double & _value
, typesystems::typebuffer_container
  const & _buffer
, typesystems::owriter_container
  const & _writer
){
while (
  std::numeric_limits<int>::max()
<
  static_cast<int>(_value)
){
typesystems::rewrite(
  static_cast<int>(
    _value
  -
    std::numeric_limits<int>::max()
  )
, _buffer
, _writer
);
_value -= std::numeric_limits<int>::max();
}

typesystems::rewrite(
  static_cast<int>(_value)
, _buffer
, _writer
);
}

/**/
void
double_int_put::do_put(
  double const & _value
, typesystems::typebuffer_container
  const & _buffer
, typesystems::owriter_container
  const & _writer
) const {
/* split the value before and after the decimal */
double characteristic (_value);
double mantissa(
  std::modf(_value, & characteristic)
);
this->do_put(
  characteristic
, _buffer
, _writer
);
this->do_put(
  mantissa
, _buffer
, _writer
);
}
