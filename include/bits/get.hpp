//


#if __cplusplus == 201103L
#ifndef TYPESYSTEMS_BITS_GET_TUPLE_HPP
#define TYPESYSTEMS_BITS_GET_TUPLE_HPP

#include <tuple>

namespace typesystems {
namespace bits {

template <
  typename T
, std::size_t N
, std::size_t I
, typename... Ts >
struct get_tuple ;

template <
  typename T
, std::size_t N
, std::size_t I
, typename... Ts >
struct get_tuple <T,N,I,T,Ts...> {
static constexpr auto value = I;
};

template <
  typename T
, std::size_t N
, std::size_t I
, typename U
, typename... Ts >
struct get_tuple <T,N,I,U,Ts...> 
: get_tuple <T,N,I+1,Ts...> {};

template <typename T, typename... Ts>
T &
get (
  std::tuple<Ts...> & _tuple
){
//static_assert (is_any<>, "");
return std::get <
  get_tuple <
    T, sizeof...(Ts), 0, Ts... >::value
>(_tuple);
}

} /* bits */ } /* typesystems */
#endif
#endif

