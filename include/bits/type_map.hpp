//

//          Copyright Sundeep S. Sangha 2015 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef TYPESYSTEMS_BITS_TYPE_MAP_HPP
#define TYPESYSTEMS_BITS_TYPE_MAP_HPP

namespace typesystems {

/* type map */
template <typename Tuple, typename... Key>
struct type_map {

Tuple tup;

public:

type_map () = default;

template <typename... Ts>
type_map (
  Ts...
);

explicit
type_map (
  Tuple &&
);

type_map (
  type_map<Tuple, Key...> const &
) = default;

type_map (
  type_map<Tuple, Key...> &&
) = default;

~type_map () = default;

type_map<Tuple, Key...> &
operator = (
  type_map<Tuple, Key...> const &
) = default;

type_map<Tuple, Key...> &
operator = (
  type_map<Tuple, Key...> &&
) = default;

explicit
operator Tuple();

}; /* type_map */

} /* typesystems */
#endif

