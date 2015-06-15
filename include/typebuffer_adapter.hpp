// Container adapter to create buffer.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_TYPEBUFFER_ADAPTER_HPP
#define TYPESYSTEMS_TYPEBUFFER_ADAPTER_HPP

#include <vector>
#include "typebuffer.hpp"

namespace typesystems {

/* typebuffer
  Sequence container adapter where all
  types are treated as T.
*/
template <
  typename T
, typename Sequence = std::vector<T>
>
class typebuffer_adapter
: public typebuffer<T> {
public:
  typedef T type;

  typedef typename Sequence::value_type
  value_type;

  typedef typename Sequence::reference
  reference;

  typedef typename Sequence
  ::const_reference const_reference;

  typedef typename Sequence::size_type
  size_type;

  typedef Sequence container_type;

  typebuffer_adapter(
    container_type const &
      _ctnr = container_type()
  );

  typebuffer_adapter(
    typebuffer_adapter const &
  );

  typebuffer_adapter &
  operator=(
    typebuffer_adapter const &
  );

#if __cplusplus >= 201103L
  typebuffer_adapter(
    typebuffer_adapter &&
  );

  typebuffer_adapter &
  operator=(
    typebuffer_adapter &&
  );
#endif

  ~typebuffer_adapter();

  Sequence &
  get_container();

protected:
/* name and protected level is
  specified in standard [23.2.3.1]
*/
  Sequence c;

private:
  virtual void
  do_clear();

  virtual bool
  do_empty() const;

  virtual void
  do_push(
    typename typebuffer<T>
    ::value_type const &
  );

#if __cplusplus >= 201103L
  virtual void
  do_push(
    typename typebuffer<T>
    ::value_type &&
  );
#endif

  virtual typename typebuffer<T>
  ::value_type &
  do_front();
  
  virtual typename typebuffer<T>
  ::value_type &
  do_back();

  virtual void
  do_pop();
};

} /* typesystems */
#include "bits/typebuffer_adapter.tcc"
#endif
