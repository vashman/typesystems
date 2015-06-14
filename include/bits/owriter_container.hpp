// Container for writers.

#ifndef TYPESYSTEMS_OWRITER_CONTAINER_HPP
#define TYPESYSTEMS_OWRITER_CONTAINER_HPP

#include "../explicit_typeid.hpp"
#include "../owriter.hpp"
#include "owriter_base.hpp"
#include <map>

namespace typesystems {

typedef std::map<
  explicit_typeid_type
, bits::owriter_base *
> owriter_container;

template <typename Writer>
void
add_writer(owriter_container &);

template <typename T>
void
remove_writer(owriter_container &);

/* has_writer */
template <typename T>
bool
has_writer(
  owriter_container const &
);

template <typename Writer>
void
add_writer(owriter_container & _con){
_con[
  explicit_typeid<typename Writer::type>
  ::raw_typeid()
] = new Writer ();
}

template <typename T>
void
remove_writer(owriter_container & _con){
_con.erase(
  _con.find(
    explicit_typeid<T>::raw_typeid()
  )
);
}

/* has_writer */
template <typename T>
bool
has_writer(
  owriter_container const & _con
){
auto iter = _con.find(
  explicit_typeid<T>::raw_typeid()
);
return iter != _con.end();
}

} /* typesystems */
#endif
