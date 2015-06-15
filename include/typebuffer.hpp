// provide adapter to create buffers for types.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_TYPEBUFFER_HPP
#define TYPESYSTEMS_TYPEBUFFER_HPP

#include <memory>
#include <stdexcept>
#include "explicit_typeid.hpp"
#include "bits/typebuffer_base.hpp"
#include "bits/typebuffer_map.hpp"

#if __cplusplus >= 201103L
#include <type_traits>
#define type_traits ::std

#else
#include <boost/type_traits.hpp>
#define type_traits ::boost
#endif

namespace typesystems {

/* typebuffer
  Generic interface for type buffer.
*/
template <typename T>
class typebuffer : public typesystems
::bits::typebuffer_base {
public:
  typedef typename
  type_traits::remove_cv<T>::type
  value_type;

  virtual
  ~typebuffer();

  /* push
    Push value to top of stack
  */
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

  /* pop 
    Remove top stack element.  
  */
  void
  pop();

  /* next
    Return copy of next item in queue
    and remove the item from the queue.
  */
  value_type
  next();

  /* front
    Return reference to front element.  
  */
  value_type &
  front();
  
  /* back
    Return reference to back (last
    inserted element) of queue.
  */
  value_type &
  back();

protected:
#if __cplusplus >= 201103L
  typebuffer() = default;

  typebuffer(
    typebuffer<T> const &
  ) = default;

  typebuffer<T> &
  operator=(
    typebuffer<T> const &
  ) = default;

  typebuffer(
    typebuffer<T> &&
  ) = default;

  typebuffer<T> &
  operator=(typebuffer<T> &&) = default;
#endif

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

  virtual value_type &
  do_front() = 0;

  virtual value_type &
  do_back() = 0;
};

/* typebuffer_container */
typedef bits::typebuffer_map
typebuffer_container;

/* set_typebuffer */
template <typename T, typename Buffer>
void
set_typebuffer(
  typebuffer_container &
);

/* clear
  Erase all elements from all containers
  in the buffer.

  This function must guarantee no
  changes to the typebuffer container
  itself.
*/
void
clear(
  typebuffer_container const &
);

/* type specific functions */
/* empty
  This function iterates through the
  buffer map and when the static_typeid
  for T is matched, the function calls
  the empty function of the
  typebuffer_base class. If the buffer
  for the type is not found returns true
  , for empty;
*/
template <typename T>
bool
empty(
  typebuffer_container const &
);

/* clear<T>
  Will iterate through the buffer map and if static_typeid for
T matches the id in the buffer,  will call the clear member function
for the typebuffer_base class.
*/
template <typename T>
void
clear(
  typebuffer_container const &
);

/* has_typebuffer
  Iterates through the buffer map and if the static_typeid from the
typebuffer_interface of T matches that in the buffer, returns true.
*/
template <typename T>
bool
has_typebuffer(
  typebuffer_container const &
);

/* use_typebuffer
Iterates through the buffer map and if the static_typeid from the
typebuffer_interface of T matches that of the one in the buffer,
returns a cast of the pointer to T.
*/
template <typename T>
typebuffer<T> &
use_typebuffer(
  typebuffer_container const &
);

} /* typesystems */
#include "bits/typebuffer.tcc"

#undef type_traits
#endif
