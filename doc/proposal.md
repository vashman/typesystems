Copyright Sundeep S. Sangha 2013 - 2014.

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
Representing external typesystems within a c++ program, by staticly
determing type identificaton of unknwon types. Providing a buffering zone
for compatable types, and creating a mechanism for expressing type
convertions. From unknown types to a similar type or array of types in
order to pass variables between two compatiable typesystems.

3 Motivation and Scope
==========================================================================
When dealing with external programs, may it be databases, scripting
languages the typesystem and/or the types being used may differ completly.
This means that when interfaceing with these external programs, the client
must provide tight coupling between their own typesystem and that of the
program.

The interface between the two can consist of; conversion of type and data
information, a mechanism for passing types between them which may need to
be asynarious, and possibly identification of type infomation.

4 Impact on the Standard
==========================================================================
none, pure extenstion.

5 Desgin Descions
==========================================================================
1 Type Identification
--------------------------------------------------------------------------
The class `explicit_typeid` provides id types for a type that is explicity
decalred as a template parameter by the user. Seperate id are generated
for types with type qualifiers, in order to preserve any extra information
about the type.

2 Storing Types
--------------------------------------------------------------------------
In order to store types a common interface is required to input and
retrive arbitraty typed data. The interface is broken into 3 parts to form
a container adapter with which the container provides the storage
mechanism for the data. The adapter provides an interface that works based
on the type information of the stored class where each part provides
differnt funcality based on the type information provide.

The `typebuffer_container`
* no iterators

The `typebuffer_interface`
* copies all io, deals with proxy objects
* virtual functions to operate on the container

The `typebuffer`
* adapter to change the underlying container
* provide access to the underlying container to use container funcality
  when useful

3 Rewriting Types and Data
--------------------------------------------------------------------------
* spliting get and put
* storing type information about the process
* comparing rewriters based upon most stright forward method

4 Typesystem
--------------------------------------------------------------------------
* no templates
* no state
* joing data storage and data converstion

6 Technical Specifications
==========================================================================
1 Header `<explicit_typeid.hpp>` synopsis
--------------------------------------------------------------------------
```c++
typedef explicit_typeid_type;

template <typename T>
class explicit_typeid {
public:
  typedef T type;

#if __cplusplus >= 201103L
  explicit
  explicit_typeid() = delete;

  explicit_typeid(
    explicit_typeid const &
  ) = delete;

  explicit_typeid &
  operator=(
    explicit_typeid const &
  ) = delete;

  explicit_typeid(
    explicit_typeid &&
  ) = delete;

  explicit_typeid &
  operator=(
    explicit_typeid &&
  ) = delete;

 ~explicit_typeid() = delete;
#endif

  template <typename T2>
  static bool
  compare();

  static bool
  raw_compare(
    explicit_typeid_type const &
  );

  static explicit_typeid_type
  raw_typeid();
};
```

### Class template explicit\_typeid
Provides the static members to compare explicit type ids, and generate
explicit type ids for the types used.

#### explicit typeid compare

2 Header `<typebuffer.hpp>` synopsis
--------------------------------------------------------------------------
```c++
namespace typesystems {

template <typename T>
class typebuffer_interface {
public:
  typedef typename type_traits::remove_cv<T>::type value_type;

#if __cplusplus >= 201103L
  typebuffer_interface(
  ) = default;

  typebuffer_interface(
    typebuffer_interface<T> const &
  ) = default;

  typebuffer_interface<T> &
  operator=(
    typebuffer_interface<T> const &
  ) = default;

  typebuffer_interface(
    typebuffer_interface<T> &&
  ) = default;

  typebuffer_interface<T> &
  operator=(
    typebuffer_interface<T> &&
  ) = default;
#endif

  virtual
  ~typebuffer_interface();

  void
  push(
    value_type const &
  );

#if __cplusplus >= 201103L
  void
  push(
    value_type &&
  );
#endif

  void
  pop();

  value_type
  next(); // get copy of next contents and remove from container.

private:
  virtual void
  do_push(
    value_type const &
  ) = 0;

#if __cplusplus >= 201103L
  virtual void
  do_push(
    value_type &&
  ) = 0;
#endif

  virtual void
  do_pop() = 0;

  virtual value_type
  do_next() = 0;
};

template <typename T, typename Sequence>
class typebuffer : public typebuffer_interface<T>{
public:
  typedef typename Sequence::value_type value_type;
  typedef typename Sequence::reference reference;
  typedef typename Sequence::const_reference const_reference;
  typedef typename Sequence::size_type size_type;
  typedef Sequence container_type;

  typebuffer(
    container_type const & _ctnr = container_type()
  );

  typebuffer(
    typebuffer const &
  );

  typebuffer &
  operator=(
    typebuffer const &
  );

#if __cplusplus >= 201103L
  typebuffer(
    typebuffer &&
  );

  typebuffer &
  operator=(
    typebuffer &&
  );
#endif

  ~typebuffer();

  Sequence &
  get_container();

protected:
/* name and protected level is specified in standard [23.2.3.1] */
  Sequence c;

private:
  virtual void
  do_clear();

  virtual bool
  do_empty() const;

  virtual void
  do_push(
    typename typebuffer_interface<T>::value_type const &
  );

#if __cplusplus >= 201103L
  virtual void
  do_push(
    typename typebuffer_interface<T>::value_type &&
  );
#endif

  virtual typename typebuffer_interface<T>::value_type
  do_next();

  virtual void
  do_pop();
};

typedef typebuffer_container;

void
clear(
  typebuffer_container const &
);

/* type specfic functions */
/* typesystem::empty<T>

This function iterates through the buffer map and when the
static_typeid for T is matached, the function calls the empty function of
the typebuffer_base class. If the buffer for the type is not found returns
true, for empty;
*/
template <typename T>
bool
empty(
  typebuffer_container const &
);

/* typesystem::clear<T>

Will iterate through the buffer map and if static_typeid for
T matches the id in the buffer,  will call the clear member function
for the typebuffer_base class.
*/
template <typename T>
void
clear(
  typebuffer_container const &
);

/* typesystem::has_typebuffer

Iterates through the buffer map and if the static_typeid from the
typebuffer_interface of T matches that in the buffer, returns true.
*/
template <typename T>
bool
has_typebuffer(
  typebuffer_container const &
);

/* typesystem::has_typebuffer

*/
template <typename T, typename Sequence>
bool
has_typebuffer(
  typebuffer_container const &
);

/* typesystem::use_typebuffer

Iterates through the buffer map and if the static_typeid from the
typebuffer_interface of T matches that of the one in the buffer,
returns a cast of the pointer to T.
*/
template <typename T>
typebuffer_interface<T> &
use_typebuffer(
  typebuffer_container const &
);

/* typesystem::use_typebuff

Iterates through the buffer map and matches the 
*/
template <typename T, typename Sequence>
typebuffer<T, Sequence> &
use_typebuffer(
  typebuffer_container const &
);

/* typesystem::set_typebuff

Adds a typebuffer using the Sequence container and Sequence::value_type to
the buffmap.
*/
template <typename T, typename Sequence>
void
set_typebuffer(
  typebuffer_container &
);

/* typesystem::set_typebuff copy

*/
template <typename T, typename Sequence>
void
set_typebuffer(
  typebuffer_container &, Sequence const &
);

/* typesystem::set_typebuff move

*/
#if __cplusplus >= 201103L
template <typename T, typename Sequence>
void
set_typebuffer(
  typebuffer_container &, Sequence &&
);
#endif

} /* typesystems */
```

### Class template typebuffer\_interface
#### typebuffer\_interface constructors
#### typebuffer\_interface destructor
#### typebuffer\_interface modifiers

### Class template typebuffer

3 Header `<get_rewriter.hpp>` synopsis
--------------------------------------------------------------------------
```c++
namespace typesystems{

template <typename T>
class get_rewriter {
public:
  typedef typename type_traits::remove_cv<T>::type value_type;
  explicit_typeid_type const * const type_array;
  std::size_t const type_count;

  virtual
  ~get_rewriter(
  );

  bool
  rewrite(
    value_type &
  , typebuffer_container const &
  ) const;

  bool
  empty(
    typebuffer_container const &
  ) const;

protected:
  template <std::size_t TypeCount>
  explicit
  get_rewriter(
    explicit_typeid_type const (&)[TypeCount]
  , std::size_t _refs = 0
  );

  virtual bool
  do_rewrite(
    value_type &
  , typebuffer_container const &
  ) const = 0;

  virtual bool
  do_empty(
    typebuffer_container const &
  ) const = 0;
};

template <typename T>
bool
operator<(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator>(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator==(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator!=(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator>=(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

template <typename T>
bool
operator<=(
  get_rewriter<T> const &
, get_rewriter<T> const &
);

} /* typesystems */
```

### Class template get\_rewriter
#### get\_rewriter constructors
#### get\_rewriter destructor

4 Header `<put_rewriter.hpp>` synopsis
--------------------------------------------------------------------------
```c++
namespace typesystems {

template <typename T>
class put_rewriter {
public:
  typedef typename type_traits::remove_cv<T>::type value_type;
  explicit_typeid_type const * const type_array;
  std::size_t const type_count;
  std::size_t const gen_count;

  virtual
  ~put_rewriter(
  );

  bool
  rewrite(
    value_type const &
  , typebuffer_container const &
  ) const;

protected:
  template <std::size_t TypeCount>
  put_rewriter(
    explicit_typeid_type const (&)[TypeCount]
  , std::size_t 
  , std::size_t _refs = 0
 );

  virtual bool
  do_rewrite(
    value_type const &
  , typebuffer_container const &
  ) const = 0;
};

template <typename T>
bool
operator<(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator>(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator==(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator!=(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator>=(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

template <typename T>
bool
operator<=(
  put_rewriter<T> const &
, put_rewriter<T> const &
);

} /* typesystems */
```

### Class template put\_rewriter

5 Header `<typesystem.hpp>` synopsis
--------------------------------------------------------------------------
```c++
namespace typesystems {

class typesystem{
public:
  typedef explicit_typeid_type id_type;

#if __cplusplus >= 201103L
  typesystem(
  ) = default;

  typesystem(
    typesystem const &
  ) = default;

  typesystem &
  operator=(
    typesystem const &
  ) = default;

  typesystem(
    typesystem &&
  ) = default;

  typesystem &
  operator=(
    typesystem &&
  ) = default;
#endif

  ~typesystem();

  template <typename T>
  bool
  put_rewrite(
    T const &
  ) const;

  template <typename T>
  bool
  get_rewrite(
    T &
  ) const;

private:
  typebuffer_container typebuffers;

  std::map<explicit_typeid_type, typesystems::bits::rewriter_base *>
    put_rewriters;

  std::map<explicit_typeid_type, typesystems::bits::rewriter_base *>
    get_rewriters;

  template <typename T>
  friend bool
  has_put_rewriter(typesystem const &);

  template <typename T>
  friend put_rewriter<T>&
  use_put_rewriter(typesystem const &);

  template <typename T>
  friend bool
  has_get_rewriter(typesystem const &);

  template <typename T>
  friend get_rewriter<T>&
  use_get_rewriter(typesystem const &);

  template <typename T>
  friend bool
  set_put_rewriter(typesystem const &);

  template <typename T>
  friend bool
  set_get_rewriter(typesystem const &);

  template <typename T, typename Sequence>
  friend void
  set_typebuffer(typesystem &);

  template <typename T>
  friend bool
  empty(typesystem const &);

  template <typename T>
  friend void
  clear(typesystem &);
};

template <typename T>
bool
empty(
  typesystem const &
);

template <typename T>
void
clear(
  typesystem &
);

template <typename T>
bool
has_put_rewriter(
  typesystem const &
);

template <typename T>
bool
has_get_rewriter(
  typesystem const &
);

template <typename T>
put_rewriter<T> &
use_put_rewriter(
  typesystem const &
);

template <typename T>
get_rewriter<T> &
use_get_rewriter(
  typesystem const &
);

template <typename T, typename Sequence>
void
set_typebuffer(
  typesystem const &
);

template <typename Rewriter>
bool
set_put_rewriter(
  typesystem const & _typesys
);

template <typename Rewriter>
bool
set_get_rewriter(
  typesystem const & _typesys
);

} /* typesystems */
```

### Class typesystem
#### typesystem constructors
#### typesystem destructor
#### typesystem assignment
#### typesystem modifiers
