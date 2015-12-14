Copyright Sundeep S. Sangha 2013 - 2015.

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

3 Rewriting Types and Data
--------------------------------------------------------------------------
* spliting get and put
* storing type information about the process
* comparing rewriters based upon most stright forward method

6 Technical Specifications
==========================================================================
1 Header `<qualified_typeid.hpp>` synopsis
--------------------------------------------------------------------------
```c++
```

### Class template qualified\_typeid
Provides the static members to compare explicit type ids, and generate
explicit type ids for the types used.

#### explicit typeid compare

2 Header `<get_rewriter.hpp>` synopsis
--------------------------------------------------------------------------
```c++
```

### Class template get\_rewriter
#### get\_rewriter constructors
#### get\_rewriter destructor

4 Header `<put_rewriter.hpp>` synopsis
--------------------------------------------------------------------------
```c++
```

### Class template put\_rewriter
