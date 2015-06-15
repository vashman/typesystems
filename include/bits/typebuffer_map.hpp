// typebuffer_container type

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_BITS_TYPEBUFFER_MAP_HPP
#define TYPESYSTEMS_BITS_TYPEBUFFER_MAP_HPP

#include <map>
#include "../explicit_typeid.hpp"
#include "typebuffer_base.hpp"

namespace typesystems {
namespace bits {

/* buffer_unit_container */
class typebuffer_map {
public:
#if __cplusplus >= 201103L
  typebuffer_map() = default;

  typebuffer_map(
    typebuffer_map const &
  ) = delete;

  typebuffer_map &
  operator=(
    typebuffer_map const &
  ) = delete;

  typebuffer_map(
    typebuffer_map &&
  ) = delete;

  typebuffer_map &
  operator=(
    typebuffer_map &&
  ) = delete;
#endif

  ~typebuffer_map();

  typedef std::map<
    typesystems::explicit_typeid_type
  , typesystems::bits::typebuffer_base *
  > map_type;

  typedef map_type::iterator
  map_iterator;
  typedef map_type::const_iterator
  map_const_iterator;

  /*
  */
  class iterator{
  public:
    typedef iterator self_type;
    typedef map_type::mapped_type
    value_type;
    typedef map_type::mapped_type &
    reference;
    typedef map_type::mapped_type *
    pointer;
    typedef std::forward_iterator_tag
    iterator_catagory;
    typedef int difference_type;

    explicit
    iterator(map_type::iterator);

    self_type
    operator++();

    self_type
    operator++(int);

    reference
    operator*();

    pointer
    operator->();

    bool
    operator==(self_type const &) const;

    bool
    operator!=(self_type const &) const;

  private:
    map_type::iterator iter;
  };

  /*
  */
  class const_iterator{
  public:
    typedef const_iterator self_type;
    typedef map_type::mapped_type
    value_type;
    typedef map_type::mapped_type &
    reference;
    typedef map_type::mapped_type *
    pointer;
    typedef std::forward_iterator_tag
    iterator_catagory;
    typedef int difference_type;

    explicit
    const_iterator(
      map_type::const_iterator
    );

    self_type
    operator++();

    self_type
    operator++(int);

    value_type const &
    operator*();

    value_type const *
    operator->();

    bool
    operator==(self_type const &) const;

    bool
    operator!=(self_type const &) const;

  private:
    map_type::const_iterator iter;
  };

  iterator
  begin();

  iterator
  end();

  const_iterator
  begin() const;

  const_iterator
  end() const;

  map_type c;
};

} /* bits */ } /* typesystems */
#endif
