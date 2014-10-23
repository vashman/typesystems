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
