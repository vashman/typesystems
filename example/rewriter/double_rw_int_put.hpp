//

#include <limits>
#include <iomanip>
#include <cmath>

class double_rw_int_put : public typesystems::rewriter_put<double>{
public:
  explicit
  double_rw_int_put(
    std::size_t _refs = 0
  );

  virtual bool
  do_rewrite(
    double const & _value
  , typesystems::typebuffer_container const & _buffers
  ) const {
    /* check if the int buffer is present */
    if (typesystems::has_typebuffer<int>(_buffers) == false){
    return false;
    }
  /* split the value before and after the decimal */
  double dbl_int;
  double dbl_dec = modf(_value, & dbl_int);
  typesystems::typebuffer_interface<int> & buffer
      = typesystems::use_typebuffer<int>(_buffers);

  try {
    while (std::numeric_limits<int>::max() < dbl_int){
    buffer.push(static_cast<int>(dbl_int - std::numeric_limits<int>::max()));
    dbl_int -= std::numeric_limits<int>::max();
    }
    buffer.push(static_cast<int>(dbl_int));
    
    while (std::numeric_limits<int>::max() < dbl_dec){
    buffer.push(static_cast<int>(dbl_dec - std::numeric_limits<int>::max()));
    dbl_dec -= std::numeric_limits<int>::max();
    }
    buffer.push(static_cast<int>(dbl_dec));
  } catch (...){
  return false;
  }
  return true;
  }
};

double_rw_int_put(
  std::size_t _refs
)
  : typesystems::rewriter_put<double> (_refs) {
}

bool
do_rewrite(
  double const & _value
, typesystems::typebuffer_container const & _buffers
) const {
  /* check if the int buffer is present */
  if (typesystems::has_typebuffer<int>(_buffers) == false){
  return false;
  }
/* split the value before and after the decimal */
double dbl_int;
double dbl_dec = std::modf(_value, & dbl_int);
typesystems::typebuffer_interface<int> & buffer
    = typesystems::use_typebuffer<int>(_buffers);

try {
  while (std::numeric_limits<int>::max() < dbl_int){
  buffer.push(static_cast<int>(dbl_int - std::numeric_limits<int>::max()));
  dbl_int -= std::numeric_limits<int>::max();
  }
buffer.push(static_cast<int>(dbl_int));
    
  while (std::numeric_limits<int>::max() < dbl_dec){
  buffer.push(static_cast<int>(dbl_dec - std::numeric_limits<int>::max()));
  dbl_dec -= std::numeric_limits<int>::max();
   }
buffer.push(static_cast<int>(dbl_dec));
  } catch (...){
  return false;
  }
return true;
}
