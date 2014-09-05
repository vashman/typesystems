// typebuffer_container type

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEMS_BITS_TYPEBUFFER_MAP_HPP
#define TYPESYSTEMS_BITS_TYPEBUFFER_MAP_HPP

#include <map>

namespace typesystems {
namespace bits {

/* buffer_unit_container */
class typebuffer_map{
public:
#if __cplusplus >= 201103L
  typebuffer_map() = default;

  typebuffer_map(typebuffer_map const &) = delete;

  typebuffer_map &
  operator=(typebuffer_map const &) = delete;

  typebuffer_map(typebuffer_map &&) = delete;

  typebuffer_map &
  operator=(typebuffer_map &&) = delete;
#endif

  ~typebuffer_map();

  typedef std::map<total_typeid::id_type
          , typesystems::bits::typebuffer_base *> map_type;

  typedef typename map_type::iterator map_iterator;
  typedef typename map_type::const_iterator map_const_iterator;

  /*
  */
  class iterator{
  public:
    typedef iterator self_type;
    typedef typename map_type::mapped_type value_type;
    typedef typename map_type::mapped_type & reference;
    typedef typename map_type::mapped_type * pointer;
    typedef std::forward_iterator_tag iterator_catagory;
    typedef int difference_type;

    explicit
    iterator(typename map_type::iterator);

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
    typedef typename map_type::mapped_type value_type;
    typedef typename map_type::mapped_type & reference;
    typedef typename map_type::mapped_type * pointer;
    typedef std::forward_iterator_tag iterator_catagory;
    typedef int difference_type;

    explicit
    const_iterator(typename map_type::const_iterator);

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

  map_type c;
};

} /* bits */ } /* typesystems */
#endif
