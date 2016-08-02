//

#ifndef TYPESYSTEMS_WRITER_HPP
#define TYPESYSTEMS_WRITER_HPP

#include <memory>

namespace typesystems {

template <typename T, typename TypeMap>
using input_writer =
  std::function <T(TypeMap const &)>;

template <typename T, typename TypeMap>
using output_writer =
  std::function <
    void (T const&, TypeMap const &) >

template <typename TypeMap>
using writer_check =
  std::function <bool(TypeMap const &)>;

} /* typesystems */
#endif

