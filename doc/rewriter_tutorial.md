Rewriter Tutorial
==========================================================================
Copyright Sundeep S. Sangha 2013 - 2014.

Distributed under the Boost Software License, Version 1.0.
 (See accompanying file `../LICENSE_1_0.txt` or copy at
       `http://www.boost.org/LICENSE_1_0.txt`)

All examples can be found in the [example/writer](../example/writer)
directory.

1 Table of Contents
==========================================================================
1. Table of Contents
2. Types of Converstions
3. Writer
5. Creating a Writer
6. Using a Writer


2. Scope
  1. Put Rewriter
  2. Get Rewriter
3. Defining an Rewriter
  1. Inheriting a rewriter type
  2. Assigning rewritable types
  3. Adding the rewrite function
4. Using an Rewriter
  1. Instaniating
  2. Invoking a Rewriter
  3. Checking if buffer is empty

2 Scope
==========================================================================
This document goes over both put and get rewriter, and how to use both in
conjuction to convert types and groups of in between each other. The
rewriters are meant to be used within the typesystem as a way of allowing
the client to customize how the typesystem handles similar and differnt
types.

Put Rewriter
--------------------------------------------------------------------------
The put rewriter is used to input data into the typesystem. The put
rewriter will hold the types and the total which are used in the rewriting
process. As well the number of types generated with every rewrite.

Get Rewriter
--------------------------------------------------------------------------
The get rewriter is used to retrive data from a typesystem. The rewriter
will take avaliable data from the typesystem and form data for the client.
The get rewriter store the types used in forming the client data, and will
always generate a single type from it.

4 Defining an Rewriter
==========================================================================
When defining a new rewriter, three main areas need to be addressed.

1 Inheriting a rewriter type
--------------------------------------------------------------------------
[example: rwperson.hpp](../example/rewriter/rwperson.hpp)

```c++
person_rw_put : public typesystems::put_rewriter<person>
```

2 Assigning rewritable types
--------------------------------------------------------------------------
[example: rwperson.hpp](../example/rewriter/rwperson.hpp)

```c++
static typesystems::explicit_typeid_type const array[2];
```

3 Adding the rewrite function
--------------------------------------------------------------------------
[example: rwperson.hpp](../example/rewriter/rwperson.hpp)

```c++
bool
person_rw_put::do_rewrite(
  person
)
```

4 Using an Rewriter
==========================================================================
1 Instaniating
--------------------------------------------------------------------------
[example: create.cpp][../example/rewriter/create.cpp]

```c++
put_rewriter<person> * rwp = new put_rewriter<person>(1);
get_rewriter<person> * rwg = new get_rewriter<person>(1);
```

2 Invoking a Rewriter
--------------------------------------------------------------------------
[example: invoke1.cpp](../example/rewriter/invoke1.cpp)

```c++
person alice(24, "Alice");

rwp->rewrite(alice, buffer);

person alice_clone(0, "");

rwg->rewrite(alice_clone, buffer);
```

3 Checking is a buffer is empty
--------------------------------------------------------------------------
[example: ](../example/rewriter/empty.cpp)

```c++
bool rv = rwg->empty<person>();
```
