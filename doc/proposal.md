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
1. `writer.hpp` {new header}
2. `type_traits.hpp` {pure extenstion}
3. `qualified_typeid.hpp` {new header}
4. `type_map.hpp` {new header}

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
* Loopup of X via a type.

3 Rewriting Types and Data
--------------------------------------------------------------------------
* Sepeartion of input and output methods.
* Client customization of methods.
* Iterators used to read and write the data.
* The number of types and the number of instaces of those types is arbartary.

6 Technical Specifications
==========================================================================
1 Header `<writer.hpp>` synopsis
--------------------------------------------------------------------------
```c++
typedef /* unspecified */ writer_base_type;

template <typename BufferIter, typename OutputIter >
using writer_function = /* unspecified */

template <typename BufferIter, typename OutputIter >
struct writer_type {

// constructor
writer_type (writer_function <BufferIter,OutputIter > *);
explicit writer_type (writer_base_type &);
writer_type (writer_type &&);
writer_type (writer_type const &);

// destructor
~writer_type();

operator writer_base_type() const;

writer_type & operator = (writer_type const &);
writer_type & operator = (writer_type &&);

bool operator () (BufferIter, BufferIter, OutputIter);

std::shared_ptr < writer_function <BufferIter, OutputIter > > ptr;
}; /* writer_type */

template <typename BufferIter, typename OutputIter, typename Function >
writer_type<BufferIter,OutputIter> make_writer (Function);

template <typename BufferIter, typename OutputIter >
writer_type <BufferIter, OutputIter> use_writer (writer_base_type &);

template <typename BufferIter, typename OutputIter >
writer_type <BufferIter, OutputIter> 
use_writer (writer_type<BufferIter,OutputIter> &);
```

### Class template `writer`

2 Header `<type_map.hpp>` synopsis
--------------------------------------------------------------------------
```c++
template <typename Key, typename T, typename... Ts >
T & get (type_map<T,Ts...> &);

template <std::size_t Key, typename T, typename... Ts >
T & get (type_map<T,Ts...> &);

template <typename T, typename... Ts>
class type_map {
public:

typename type_map<T,Ts...>::iterator begin ();
typename type_map<T,Ts...>::iterator end ();

class iterator {
public:

// constructors
explicit iterator (type_map<T,Ts...> &);
explicit iterator ();
iterator (iterator const &);
iterator (iterator &&);

// destructor
~iterator();

// assignment
iterator & operator = (iterator const &);
iterator & operator = (iterator &&);

// modifiers
iterator operator ++ ();
iterator & operator ++ (int const);
iterator operator -- ();
iterator & operator -- (int const);
iterator operator + (int) const;
iterator operator + (iterator const &) const;
iterator operator - (int) const;
iterator operator - (iterator const &) const;
iterator & operator += (int const);
iterator & operator += (iterator const &);
iterator & operator -= (int const);
iterator & operator -= (iterator const &);

// comparison
bool operator < (iterator const &) const;
bool operator > (iterator const &) const;
bool operator >= (iterator const &) const;
bool operator <= (iterator const &) const;
bool operator == (iterator const &) const;
bool operator != (iterator const &) const;

// observers
T & operator * ();
T * operator -> ();
T & operator [] (int);

}; /* type map iterator */
}; /* type_map */

```

### Class template `type_map`
A homogeneous container that provides look up of an element via a
*type key*.

#### `type_map` constructor
2. Effects:
  Creates a new `type_map`.

#### `type_map` destructor
1. Pre-Conditions:
  Instance of `type_map`.

2. Effects:
  Destorys a `type_map` and calls the destructor of all contained
  types including key types.

3. Post-Conditions:
  All iterators to the type map instance are invalidated.

#### `type map` copy constructor
1. Effects:
  Creates a copy of the `type_map` and all contained elements include
  key types.

2. Requires:
  Instance of `type_map`.

#### `type map` move constructor
1. Pre-Conditions:

2. Effects:
Creates a new `type_map`.

3. Post-Conditions:

4. Requires:

#### `type map` copy operator
1. Pre-Conditions:

2. Effects:

3. Post-Conditions:

4. Requires:

5. Throws:

6. Exception Safty:

7. Returns:

#### `type map` move operator
1. Pre-Conditions:

2. Effects:

3. Post-Conditions:

4. Requires:

#### `type map` begin
1. Pre-Conditions:

2. Effects:

3. Post-Conditions:

4. Requires:

#### `type map` end
1. Pre-Conditions:

2. Effects:

3. Post-Conditions:

4. Requires:

### begin (type map)
1. Pre-Conditions:

2. Effects:

3. Post-Conditions:

4. Requires:

### end (type map)
1. Pre-Conditions:

2. Effects:

3. Post-Conditions:

4. Requires:

### Class template type map `iterator`
Random access iterator for **type map**.

#### `iterator` constructor
1. Post-Conditions:
  type map instance is not destoryed.

2. Requires:
  Instance of type map.

#### `iterator` copy constructor
1. Pre-Conditions:

2. Effects:

3. Post-Conditions:

4. Requires:
  Instance of `type_map::iterator`.

#### `iterator` move constructor
1. Requires:
  Instance of `type_map::iterator`.

#### `iterator` destructor
1. Pre-Conditions:

2. Effects:
  Destorys the instance of iterator.

3. Post-Conditions:
  `type_map` is not affected.

4. Throws:
  Nothing.

#### `iterator` copy operator
1. Returns:
  Copy of iterator at postion.

2. Requires:
  Instance of `type_map::iterator`.

#### `iterator` move operator
1. Returns:
  *this

2. Requires:
  Instance of `type_map::iterator`.

#### `iterator` post-increment operator
1. Pre-Conditions:
  N < size of type map.

2. Effects:
  Changes the postion of the iterator to N + 1.

3. Post-Conditions:
  N !> 0

4. Returns:
  A copy of *this before N + 1.
  
#### `iterator` pre-increment operator
1. Pre-Conditions:
  N < size of type map.

2. Effects:
  Changes the postion of the iterator to N + 1.

3. Post-Conditions:
  N !> 0

4. Returns:
  *this

#### `iterator` pre-deincrement operator
1. Pre-Conditions:
  N > 0

2. Effects:
  Changes the postion of the iterator to N - 1.

3. Post-Conditions:
  N !< 0

4. Returns:
  *this

#### `iterator` post-deincrement operator
1. Pre-Conditions:
  N > 0

2. Effects:
  Changes the postion of the iterator to N - 1.

3. Post-Conditions:
  N !< 0

4. Returns:
  A copy of *this before N - 1.

#### `iterator` equality operator
1. Pre-Conditions:
  type map instance for iterator has not been destroyed.

2. Returns:
  Boolean value.

3. Post-Conditions:
  type map and iterator are not modified.

4. Requires:
  Two type map iterators for the same instance of a type map.

#### `iterator` un-equality operator
1. Pre-Conditions:
  type map instance for iterator has not been destroyed.

2. Returns:
  Boolean value.

3. Post-Conditions:
  type map and iterator are not modified.

4. Requires:
  Two type map iterators for the same instance of a type map.

#### `iterator` greater-than operator
1. Pre-Conditions:
  type map instance for iterator has not been destroyed.

2. Returns:
  Boolean value.

3. Post-Conditions:
  type map and iterator are not modified.

4. Requires:
  Two type map iterators for the same instance of a type map.

#### `iterator` less-than operator
1. Pre-Conditions:
  type map instance for iterator has not been destroyed.

2. Returns:
  Boolean value.

3. Post-Conditions:
  type map and iterator are not modified.

4. Requires:
  Two type map iterators for the same instance of a type map.

#### `iterator` greater-than or equal too operator
1. Pre-Conditions:
  type map instance for iterator has not been destroyed.

2. Returns:
  Boolean value.

3. Post-Conditions:
  type map and iterator are not modified.

4. Requires:
  Two type map iterators for the same instance of a type map.

#### `iterator` less-than or equal too operator
1. Pre-Conditions:
  type map instance for iterator has not been destroyed.

2. Returns:
  Boolean value.

3. Post-Conditions:
  type map and iterator are not modified.

4. Requires:
  Two type map iterators for the same instance of a type map.

#### `iterator` defrerence operator
1. Returns:
  Refernce to T at index location.

#### `iterator` defrerence pointer operator
1. Returns:
  Pointer to T at index location.

#### `iterator` subscript operator
1. Pre-Conditions:
  Index < size of type_map.

2. Returns:
  Refernce to T at index location.

3. Requires:
  A size_t index number.

4. Throws:
  std::out_of_range when index > size of type map.

5. Exception Safty:
  All operations and container remain vaild after exception is thrown.