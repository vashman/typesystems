#ifndef TYPESYSTEMS_TYPELIST_HPP
#define TYPESYSTEMS_TYPELIST_HPP

#include <tuple>

namespace typesystems {

/* typlist type */
template <typename... Ts>
struct typelist {};

namespace bits {
struct end {};

/* get typelist */
template <typename... Ts>
struct get_typelist : typelist<Ts...> {};

/* get typelist from nested tuple */
template <typename... LHS, typename... RHS>
struct get_typelist<std::tuple<LHS...>, RHS...> : get_typelist<LHS...,RHS...> {};

/* use_typelist 
  end operation
*/
template <template <typename...> class Operation, typename... Ts>
struct use_typelist;

/* use_typelist 
  Take next typelist and prepend types.
*/
template <template <typename...> class Operation, typename... LHS, typename... RHS>
struct use_typelist <Operation, typelist<LHS...>, RHS...> : use_typelist<Operation,LHS...,RHS...> {};

/* use_typelist 
 end typelist
*/
template <template <typename...> class Operation, typename... Ts>
struct use_typelist <Operation, end, Ts...> : Operation<Ts...> {};

/* use_typelist
*/
template <template <typename...> class Operation, typename T, typename... Ts>
struct use_typelist <Operation, T, Ts...> : use_typelist<Operation,Ts...,T> {};

} /* bits */

template <typename... Ts>
using get_typelist = typename bits::get_typelist<Ts...>;

template <template <typename...> class Operation, typename... Ts>
using use_typelist = typename bits::use_typelist<Operation,Ts..., bits::end>;

} /* typelists */
#endif
