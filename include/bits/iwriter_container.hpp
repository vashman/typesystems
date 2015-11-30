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

/* set_writer */
template <typename Writer>
void
set_writer(
  iwriter_container &
);

/* remove_writer */
template <typename T>
void
remove_writer(
  iwriter_container &
);

/* has_writer */
template <typename T>
bool
has_writer(
  iwriter_container const &
);

/* set_writer */
template <typename Writer>
void
set_writer(
  iwriter_container & _c
){
_c [
  explicit_typeid<typename Writer::type>
  ::raw_typeid()
] = new Writer ();
}

/* remove_writer */
template <typename T>
void
remove_writer(
  iwriter_container & _c
){
_c.erase( _c.find(
  explicit_typeid<T>::raw_typeid()
));
}

/* has_writer */
template <typename T>
bool
has_writer(
  iwriter_container const & _c
){
auto iter = _c.find(
  explicit_typeid<T>::raw_typeid()
);
return iter != _c.end();
}

} /* typesystems */
#endif
