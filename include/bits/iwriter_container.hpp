// Container for writers.

#ifndef TYPESYSTEMS_IWRITER_CONTAINER_HPP
#define TYPESYSTEMS_IWRITER_CONTAINER_HPP

#include "../explicit_typeid.hpp"
#include "../iwriter.hpp"
#include "iwriter_base.hpp"
#include <map>

namespace typesystems {

typedef std::map<
  explicit_typeid_type
, bits::iwriter_base *
> iwriter_container;

template <typename Writer>
void
add_writer(iwriter_container &);

template <typename T>
void
remove_writer(iwriter_container &);

template <typename T>
bool
has_writer(
  iwriter_container const &
);

template <typename Writer>
void
add_writer(iwriter_container & _con){
_con[
  explicit_typeid<typename Writer::type>
  ::raw_typeid()
] = new Writer ();
}

template <typename T>
void
remove_writer(iwriter_container & _con){
_con.erase(
  _con.find(
    explicit_typeid<T>::raw_typeid()
  )
);
}

template <typename T>
bool
has_writer(
  iwriter_container const & _con
){
auto iter = _con.find(
  explicit_typeid<T>::raw_typeid()
);
return iter != _con.end();
}

} /* typesystems */
#endif
