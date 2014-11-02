// base class used to store pointers to typebuffers.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_TYPEBUFFER_BASE_HPP
#define TYPESYSTEMS_TYPEBUFFER_BASE_HPP

#include "../explicit_typeid.hpp"

namespace typesystems {
namespace bits{

/* typebuffer_base
Typebuffer base class provides gernic container operations for the
container.
*/
class typebuffer_base{
public:
#if __cplusplus >= 201103L
  explicit
  typebuffer_base() = default;

  typebuffer_base(typebuffer_base const &) = default;

  typebuffer_base &
  operator=(typebuffer_base const &) = default;

  typebuffer_base(typebuffer_base &&) = default;

  typebuffer_base &
  operator=(typebuffer_base &&) = default;
#endif

  virtual
  ~typebuffer_base();

  void
  clear();

  bool
  empty() const;

  typesystems::explicit_typeid_type container_id;

protected:
  virtual void
  do_clear() = 0;

  virtual bool
  do_empty() const = 0;
};

}/* bits */ } /* typesystems */
#endif
