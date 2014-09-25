Explicit Typeid Tutorial 
==========================================================================
All examples can be found in the [example/explicit\_typeid](../example/
explicit_typeid) directory.

1 Table of Contents
==========================================================================
1. Table of Contents
2. Creating Explicit Typeid
  1. Instanating The Class
  2. Instanating a Qualified Type
  3. Typedefs are not new Types
3. Comparing Explicit Type ids
  1. Compare Types
  2. Raw Compare

1 Creating Explicit Typeid
==========================================================================
1 Create a Explicit Typid for type
--------------------------------------------------------------------------
Explicit type id's are generated when a type is used to compare to another
type. Is it possible to create a `explicit_type_id` before hand by calling
the `raw_typeid` function which returns the `explicit_typeid_type`.

[exmaple: create.cpp](../example/explicit_typeid/create.cpp)
```c++
explicit_typeid_type id = explicit_typeid<float>::raw_typeid();
```

2 Instanating a Qualified Type
--------------------------------------------------------------------------
Added type qualifers like `const` and `volatile` create a new distinct id
from there non-qualified parts.

[example: qualified.cpp](../example/explicit_typeid/qulafied.cpp)

```c++
  /* produce false */
  if (explicit_typeid<int>::compare<int cont>())
```

3 Typedefs are not new Types
--------------------------------------------------------------------------
Creating a `typedef` of a type does not create a new explicit type id.

[example: typedef.cpp](../example/explicit_typeid/typedef.cpp)

```c++
typedef int some_type;

  /* true statement */
  if (explicit_typeid<some_type>::compare<some_type>())
```

2 Compare Explicit Type Ids
==========================================================================
1 Compare Types
--------------------------------------------------------------------------
Diffent types can be compared through the static member function `compare`
. The types beging compared can be deduced from a explicit_typeid
instance, or can be ma

[example: compare.cpp](../example/explicit_typeid/compare.cpp)

```c++
 if (explicit_typeid<A>::compare<A>())
```

2 Raw Compare
--------------------------------------------------------------------------
If the explicit_typeid has been converted into a raw id, the raw_compare
member function will compare an raw id to an explicit_typeid.

[example: raw_compare.cpp](../example/explicit_typeid/raw_compare.cpp)

```c++

explicit_typeid_type raw_id = int_id::raw_typeid();

explicit_typeid<char>::raw_compare(raw_id);
```
