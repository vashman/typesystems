Copyright Sundeep S. Sangha 2013 - 2016.

Distributed under the Boost Software License, Version 1.0.
 (See accompanying file `../LICENSE_1_0.txt` or copy at
       `http://www.boost.org/LICENSE_1_0.txt`)

1 Table of Contents
==========================================================================
1. Table of Contents
2. Introduction
3. Motivation and Scope
4. Impact on the Standard
5. Desgin Descions
    1. Type Identification
    2. Storing Types
    3. Rewriting Types and Data
    4. Typesystem
6. Technical Specifications

2 Introduction
==========================================================================
The goal is to represent external typesystems within a c++ program. The
other typesystem is represendted and utilized by the core application
through the following 2 concepts.

Identification of types, invloves providing methods for determing type
identificaton / information of unknown types.

Storing unknown types and type infromation. Then rewriting the types into
equivelient representtions in the other typesystem.

3 Motivation and Scope
==========================================================================
When dealing with external programs, may it be databases, scripting
languages; the typesystem and/or the types being used may differ completly
from the types used by the client. This means that when interfaceing with
these external programs, the client must provide tight coupling between
their own typesystem and that of the program.

The following does not cover the sepeartion / de-coupling of the
typesystem, but rather the interface between the differnt typesystems. The
interface between the two can consist of; conversion of type and data
information, a method of identification of differnt types.

4 Impact on the Standard
==========================================================================
1. writer.hpp {new header}
2. type_traits.hpp {pure extenstion}
3. qualified_typeid.hpp {new header}
4. type_map.hpp {new header}

5 Desgin Descions
==========================================================================

1 Type Identification
--------------------------------------------------------------------------
The libray uses templates to carry type information. When this is not
possible run-time information may be used as a subsitute.

The class `qualified_typeid` provides id types for a type RTTI types while
preservering qualifiers. Thus a seperate id is generated for types with
type qualifiers, in order to preserve any extra information about the type.

2 Storing Types
--------------------------------------------------------------------------
* Type infromation should not have to be earsed to store a type.
* The storage mechanism should not be bound to a particular interface.
* The number of types and the number of instaces of those types is arbartary.

3 Rewriting Types and Data
--------------------------------------------------------------------------
* Sepeartion of input and output methods.
*

6 Technical Specifications
==========================================================================
1 Header `<writer.hpp>` synopsis
--------------------------------------------------------------------------
```c++
namespace typesystems {

typedef
/* unspecified */ writer_base_type;

template <
  typename BufferIter
, typename OutputIter >
using writer_function = // unspecified

template <
  typename BufferIter
, typename OutputIter >
struct writer_type {

writer_type (
  writer_function <
    BufferIter,OutputIter > *
);

explicit
writer_type (
  writer_base_type &
);

operator writer_base_type() const;

writer_type (
  writer_type const &
) = default;

writer_type &
operator = (
  writer_type const &
) = default;

writer_type &
operator = (
  writer_type &&
) = default;

writer_type (
  writer_type &&
) = default;

~writer_type() = default;

bool
operator () (
  BufferIter
, BufferIter
, OutputIter
);

std::shared_ptr < writer_function <
  BufferIter, OutputIter > > ptr;
}; /* writer_type */

template <
  typename BufferIter
, typename OutputIter
, typename Function >
writer_type<BufferIter,OutputIter>
make_writer (
  Function
);

template <
  typename BufferIter
, typename OutputIter >
writer_type <BufferIter, OutputIter>
use_writer (
  writer_base_type &
);

template <
  typename BufferIter
, typename OutputIter >
writer_type <BufferIter, OutputIter>
use_writer (
  writer_type<BufferIter,OutputIter> &
);

} /* typesystems */
```

### Class template `writer`

2 Header `<type_map.hpp>` synopsis
```c++
namespace typesystems {

template <
  typename Key
, typename T
, typename... Ts >
T&
get (
  type_map<T,Ts...> &
);

template <
  std::size_t Key
, typename T
, typename... Ts >
T &
get (
  type_map<T,Ts...> &
);

template <typename T, typename... Ts>
class type_map {

public:

class iterator
{

protected:

explicit
iterator (
  type_map<T,Ts...> *
, int
);

public:

explicit
iterator (
  type_map<T,Ts...> &
);

explicit
iterator ();

iterator (
  iterator const &
) = default;

iterator (
  iterator &&
) = default;

iterator &
operator = (
  iterator const &
) = default;

iterator &
operator = (
  iterator &&
) = default;

iterator
operator ++ ();

iterator &
operator ++ (
  int const
);

iterator
operator -- ();

iterator &
operator -- (
  int const
);

iterator
operator + (int) const;

iterator
operator + (
  iterator const &
) const;

iterator
operator - (
  int
) const;

iterator
operator - (
  iterator const &
) const;

iterator &
operator += (
  int const
);

iterator &
operator += (
  iterator const &
);

iterator &
operator -= (
  int const
);

iterator &
operator -= (
  iterator const &
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

T &
operator * ();

T *
operator -> ();

T &
operator [] (
  int
);

}; /* type map iterator */

typename type_map<T,Ts...>::iterator
begin ();

typename type_map<T,Ts...>::iterator
end ();

}; /* type_map */

} /* typesystems */
```

### Class template `type_map`
A hetrogenous container that provides look up of an element via a
*type key*.

#### `type_map` constructor
1. Pre-Conditions:

2. Effects:
  Creates a new `type_map`.

3. Post-Conditions:

4. Requires:

#### `type_map` destructor
1. Pre-Conditions:
  Instance of `type_map`.

2. Effects:
  Destorys a `type_map` and calls the destructor of all contained
  types including key types.

3. Post-Conditions:

4. Requires:

#### `type map` copy constructor
1. Pre-Conditions:
  Instance of `type_map`.

2. Effects:
  Creates a copy of the `type_map` and all contained elements include
  key types.

3. Post-Conditions:


4. Requires:

#### `type map` move constructor
1. Pre-Conditions:

2. Effects:
Creates a new `type_map`.

3. Post-Conditions:

4. Requires:

#### `type map` copy operator
#### `type map` move operator
#### `type map` begin
#### `type map` end

### begin (type map)
### end (type map)

### Class template type map `iterator`
Random access iterator for **type map**.

#### `iterator` constructor
#### `iterator` copy constructor
#### `iterator` move constructor
#### `iterator` destructor
#### `iterator` copy operator
#### `iterator` move operator
#### `iterator` post-increment operator
#### `iterator` pre-increment operator
#### `iterator` pre-deincrement operator
#### `iterator` post-deincrement operator
#### `iterator` equality operator
#### `iterator` un-equality operator
#### `iterator` greater-than operator
#### `iterator` less-than operator
#### `iterator` greater-than or equal too operator
#### `iterator` less-than or equal too operator
#### `iterator` defrerence operator
#### `iterator` defrerence pointer operator
#### `iterator` subscript operator