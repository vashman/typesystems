// typebuffer_container type

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef TYPESYSTEM_BITS_TYPEBUFFER_MAP_HPP
#define TYPESYSTEM_BITS_TYPEBUFFER_MAP_HPP

#include <map>

namespace typesystem{
namespace bits{
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

  typedef std::map<total_typeid::id_type, typesystem::bits::typebuffer_base *> map_type;

  map_type c;

  typedef map_type::iterator iterator;
  typedef map_type::const_iterator const_iterator;
};

} /* bits */ } /* typesystem */
#endif
