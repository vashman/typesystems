// provide adapter to create buffers for types.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_TYPEBUFFER_HPP
#define TYPESYSTEMS_TYPEBUFFER_HPP

#include <memory>
#include "explicit_typeid.hpp"
#include "bits/typebuffer_base.hpp"
#include "bits/typebuffer_map.hpp"

#if __cplusplus >= 201103L
#include <type_traits>
#define type_traits ::std

#else
#include <boost/type_traits.hpp>
#define type_traits ::BOOST
#endif

namespace typesystems {

/* typebuffer_interface
Generic interface for type, provided via typebuffer. The functions clear
and empty are defined in the typesystem::bits::typebuffer_base class.
*/
template <typename T>
class typebuffer_interface : public typesystems::bits::typebuffer_base {
public:
  typedef typename type_traits::remove_cv<T>::type value_type;

#if __cplusplus >= 201103L
  typebuffer_interface(
  ) = default;

  typebuffer_interface(
    typebuffer_interface<T> const &
  ) = default;

  typebuffer_interface<T> &
  operator=(
    typebuffer_interface<T> const &
  ) = default;

  typebuffer_interface(
    typebuffer_interface<T> &&
  ) = default;

  typebuffer_interface<T> &
  operator=(
    typebuffer_interface<T> &&
  ) = default;
#endif

  virtual
  ~typebuffer_interface();

  void
  push(
    value_type const &
  );

#if __cplusplus >= 201103L
  void
  push(
    value_type &&
  );
#endif

  void
  pop();

  value_type
  next(); // get copy of next contents and remove from container.

private:
  virtual void
  do_push(
    value_type const &
  ) = 0;

#if __cplusplus >= 201103L
  virtual void
  do_push(
    value_type &&
  ) = 0;
#endif

  virtual void
  do_pop() = 0;

  virtual value_type
  do_next() = 0;
};

/* typebuffer
Sequence container adapter where all types are treated as T.
*/
template <typename T, typename Sequence>
class typebuffer : public typebuffer_interface<T>{
public:
  typedef typename Sequence::value_type value_type;
  typedef typename Sequence::reference reference;
  typedef typename Sequence::const_reference const_reference;
  typedef typename Sequence::size_type size_type;
  typedef Sequence container_type;

  typebuffer(
    container_type const & _ctnr = container_type()
  );

  typebuffer(
    typebuffer const &
  );

  typebuffer &
  operator=(
    typebuffer const &
  );

#if __cplusplus >= 201103L
  typebuffer(
    typebuffer &&
  );

  typebuffer &
  operator=(
    typebuffer &&
  );
#endif

  ~typebuffer();

  Sequence &
  get_container();

protected:
/* name and protected level is specified in standard [23.2.3.1] */
  Sequence c;

private:
  virtual void
  do_clear();

  virtual bool
  do_empty() const;

  virtual void
  do_push(
    typename typebuffer_interface<T>::value_type const &
  );

#if __cplusplus >= 201103L
  virtual void
  do_push(
    typename typebuffer_interface<T>::value_type &&
  );
#endif

  virtual typename typebuffer_interface<T>::value_type
  do_next();

  virtual void
  do_pop();
};

/* typebuffer_container
*/
typedef typesystems::bits::typebuffer_map typebuffer_container;

/* typesystem::clear

Iterates through a buffer unit and uses the typebuffer_base class to
call the container clear function. This function must gurantee no
changes to the buff_map itself.
*/
void
clear(
  typebuffer_container const &
);

/* type specfic functions */
/* typesystem::empty<T>

This function iterates through the buffer map and when the
static_typeid for T is matached, the function calls the empty function of
the typebuffer_base class. If the buffer for the type is not found returns
true, for empty;
*/
template <typename T>
bool
empty(
  typebuffer_container const &
);

/* typesystem::clear<T>

Will iterate through the buffer map and if static_typeid for
T matches the id in the buffer,  will call the clear member function
for the typebuffer_base class.
*/
template <typename T>
void
clear(
  typebuffer_container const &
);

/* typesystem::has_typebuffer

Iterates through the buffer map and if the static_typeid from the
typebuffer_interface of T matches that in the buffer, returns true.
*/
template <typename T>
bool
has_typebuffer(
  typebuffer_container const &
);

/* typesystem::has_typebuffer

*/
template <typename T, typename Sequence>
bool
has_typebuffer(
  typebuffer_container const &
);

/* typesystem::use_typebuffer

Iterates through the buffer map and if the static_typeid from the
typebuffer_interface of T matches that of the one in the buffer,
returns a cast of the pointer to T.
*/
template <typename T>
typebuffer_interface<T> &
use_typebuffer(
  typebuffer_container const &
);

/* typesystem::use_typebuff

Iterates through the buffer map and matches the 
*/
template <typename T, typename Sequence>
typebuffer<T, Sequence> &
use_typebuffer(
  typebuffer_container const &
);

/* typesystem::set_typebuff

Adds a typebuffer using the Sequence container and Sequence::value_type to
the buffmap.
*/
template <typename T, typename Sequence>
void
set_typebuffer(
  typebuffer_container &
);

/* typesystem::set_typebuff copy

*/
template <typename T, typename Sequence>
void
set_typebuffer(
  typebuffer_container &, Sequence const &
);

/* typesystem::set_typebuff move

*/
#if __cplusplus >= 201103L
template <typename T, typename Sequence>
void
set_typebuffer(
  typebuffer_container &, Sequence &&
);
#endif

} /* typesystems */
#include "bits/typebuffer.tcc"

#undef type_traits
#endif
