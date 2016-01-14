//

#ifndef TYPESYSTEMS_TYPE_MAP_HPP
#define TYPESYSTEMS_TYPE_MAP_HPP

#include <tuple>
#include <iterator>

namespace typesystems {
namespace bits {

template <
  int N, typename T, typename... Ts >
struct check_tuple {
/**/
static
T&
get (
  int const &
, std::tuple<std::tuple<Ts,T>...> &
);
}; /* check_tuple */

template <typename T, typename... Ts>
struct check_tuple <0,T,Ts...> {
/**/
static
T&
get (
  int const &
, std::tuple<std::tuple<Ts,T>...> &
);
}; /* check_tuple <0,T,Ts...> */

} /* bits */

/* type map */
template <typename T, typename... Ts>
class type_map {
std::tuple<std::tuple<Ts,T>...> map;

public:

/* type map iterator */
class iterator
: public std::iterator <
    std::random_access_iterator_tag
  , T >
{
type_map<T,Ts...> * con;
int index;

public:
/* ctor */
explicit
iterator (
  type_map<T,Ts...> &
);

/* ctor end */
explicit
iterator ();

/* ctor copy */
iterator (
  iterator const &
) = default;

/* ctor move */
iterator (
  iterator &&
) = default;

/* operator copy */
iterator &
operator = (
  iterator const &
) = default;

/**/
iterator &
operator = (
  iterator &&
) = default;

/*
iterator &
operator ++ ();

//
iterator &
operator ++ (
  int
);

//
iterator &
operator -- ();

//
iterator &
operator -- (
  int
);

iterator &
operator + (
  int
);

iterator &
operator +(
  iterator const &
);

iterator &
operator - (
  int
);

iterator &
operator += (
  int
);

bool
operator < (
  iterator const &
) const;

bool
operator > (
  iterator const &
) const;

bool
operator >= (
  iterator const &
) const;

bool
operator <= (
  iterator const &
) const;

bool
operator == (
  iterator const &
) const;

bool
operator != (
  iterator const &
) const;
*/
T&
operator *();
/*
T*
operator ->();

T&
operator [] (int);
*/
}; /* type_map_iterator */

template <
  typename Key
, typename T2
, typename... T2s >
friend
T&
get (type_map<T,Ts...> &);

typename type_map<T,Ts...>::iterator
begin ();

typename type_map<T,Ts...>::iterator
end ();

}; /* type_map */



/* get */
template <
  typename Key
, typename T
, typename... Ts >
T&
get (
  type_map<T,Ts...> &
);

/* get * / 
template <
  int Key
, typename T
, typename... Ts >
T&
get (
  type_map<T,Ts...> &
);*/

} /* typesystems */
#include "./bits/type_map.tcc"
#endif

