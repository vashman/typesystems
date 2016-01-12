//

#ifndef TYPESYSTEMS_TYPE_MAP_HPP
#define TYPESYSTEMS_TYPE_MAP_HPP

#include <tuple>
#include <iterator>

namespace typesystems {

/* type map */
template <typename T, typename... Ts>
using type_map
  = std::tuple<std::tuple<Ts,T>...>;

/**/
template <typename T, typename... Ts>
class type_map_iterator
: public std::iterator <
    std::random_access_iterator_tag
  , T >
{
type_map<T,Ts...> * con;
int index;

public:
/* ctor */
explicit
type_map_iterator (
  type_map<T,Ts...> &
);

/* ctor end */
explicit
type_map_iterator ();

/* ctor copy */
type_map_iterator (
  type_map_iterator<T,Ts...> const &
) = default;

/* ctor move */
type_map_iterator (
  type_map_iterator<T,Ts...> &&
) = default;

/* operator copy */
type_map_iterator<T,Ts...> &
operator = (
  type_map_iterator<T,Ts...> const &
) = default;

/**/
type_map_iterator<T,Ts...> &
operator = (
  type_map_iterator<T,Ts...> &&
) = default;

//
type_map_iterator<T,Ts...> &
operator ++ ();

//
type_map_iterator<T,Ts...> &
operator ++ (
  int
);

//
type_map_iterator<T,Ts...> &
operator -- ();

//
type_map_iterator<T,Ts...> &
operator -- (
  int
);

type_map_iterator<T,Ts...> &
operator + (
  int
);

type_map_iterator<T,Ts...> &
operator +(
  type_map_iterator<T,Ts...> const &
);

type_map_iterator<T,Ts...> &
operator - (
  int
);

type_map_iterator<T,Ts...> &
operator += (
  int
);

bool
operator < (
  type_map_iterator<T,Ts...> const &
) const;

bool
operator > (
  type_map_iterator<T,Ts...> const &
) const;

bool
operator >= (
  type_map_iterator<T,Ts...> const &
) const;

bool
operator <= (
  type_map_iterator<T,Ts...> const &
) const;

bool
operator == (
  type_map_iterator<T,Ts...> const &
) const;

bool
operator != (
  type_map_iterator<T,Ts...> const &
) const;

T&
operator *();

T*
operator ->();

operator []();

}; /* type_map_iterator */

/* begin */
template <typename T, typename... Ts>
type_map_iterator<T,Ts...>
begin (
  type_map<T,Ts...> &
);

/* end */
template <typename T, typename... Ts>
type_map_iterator<T,Ts...>
end (
  type_map<T,Ts...> const &
);

/* get */
template <
  typename Key
, typename T
, typename... Ts >
T&
get (
  type_map<T,Ts...> &
);

} /* typesystems */
#include "./bits/type_map.tcc"
#endif
