//

#ifndef TYPESYSTEMS_BITS_IS_ANY_HPP
#define TYPESYSTEMS_BITS_IS_ANY_HPP

#include <type_traits>

namespace typesystems {
namespace bits {

template<typename T, typename... Ts>
struct is_any : std::false_type {};

template<typename T, typename U>
struct is_any<T, U>
  : std::is_same<T, U> {};

template<typename T, typename U, typename... Ts>
struct is_any<T, U, Ts...>
    : std::integral_constant <
    bool
  , std::is_same<T,U>::value
|| is_any<T, Ts...>::value >{};

} /* bits */ } /* typesystems */
#endif

