//

#ifndef TYPESYSTEMS_TYPE_TRAITS_HPP
#define TYPESYSTEMS_TYPE_TRAITS_HPP

#include <type_traits>

namespace typesystems {

namespace bits {
/* or_ */
template <typename... Conditions>
struct or_ : std::false_type {};

/* or_ */
template <
  typename Condition
, typename... Conditions >
struct or_<Condition,Conditions...>
: std::conditional <
  Condition::value
, std::true_type
, or_<Conditions...> >::type {
};

} /* bits */

/* has_type */
template <typename T, typename... Ts>
using has_type
= bits::or_<std::is_same<T,Ts>...>;

/* get type index */
template <typename T, typename... Ts>
struct get_type_index;

template <typename T, typename... Ts>
struct get_type_index<T, T, Ts...>
: std::integral_constant<std::size_t, 0>
{};

template <
    typename T
  , typename Tail
  , typename... Ts >
struct get_type_index<T, Tail, Ts...>
: std::integral_constant <
    std::size_t
  , 1 + get_type_index<T, Ts...>::value
>
{};

} /* typesystems */
#endif

