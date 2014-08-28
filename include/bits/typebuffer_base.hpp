//

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEM_TYPEBUFFER_BASE_HPP
#define TYPESYSTEM_TYPEBUFFER_BASE_HPP

#include "../explicit_typeid.hpp"

namespace typesystem{ namespace bits{
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

  typesystem::explicit_typeid_type container_id;

protected:
  virtual void
  do_clear() = 0;

  virtual bool
  do_empty() const = 0;
};
}/* bits */ } /* typesystem */
#endif
