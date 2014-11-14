Typebuffer Tutorial
==========================================================================
Copyright Sundeep S. Sangha 2013 - 2014.

Distributed under the Boost Software License, Version 1.0.
 (See accompanying file `../LICENSE_1_0.txt` or copy at
       `http://www.boost.org/LICENSE_1_0.txt`)

All examples can be found in the [example/typebuffer](../example/
typebuffer) directory.

1 Table of Contents
==========================================================================
1. Table of Contents
2. Introduction
3. Creating Typebuffers
  1. Basic Creation
  2. Copy Container Construction
  3. Qualified Types
  4. Accessing the Underlying Container
4. Typebuffer Interface
  1. Create an Typebuffer Interface
  2. Adding / Removing values from Typebuffer Interface
5. Typebuffer Container
  1. Description
  2. Creating a Container Instance
  3. Adding Typebuffers to a Container
  4. Checking Container for Typebuffer
  5. Retriving a Typebuffer from a Container
  6. Checking if a buffer is empty
  7. Clearing data in a buffer

2 Introduction
==========================================================================
Typebuffers are container adapters, which use virtual functions to push
and pop from the underlying container.

3 Creating Typebuffers
==========================================================================
1 Basic Creation
--------------------------------------------------------------------------
[example: create.cpp](../example/typebuffer/create.cpp)

```c++
typebuffer<int, std::vector<int> > buffer;
```

2 Copy Container Concstruction
--------------------------------------------------------------------------
[example: create.cpp](../example/typebuffer/create.cpp)

```c++
typebuffer<int, std::vector<int> > copied_buffer (vec);
```

3 Qualified Types
--------------------------------------------------------------------------
[example: qualified.cpp](../example/qualified.cpp)

```c++
typebuffer<int const, vector<int> > cbuff;
```

4 Accessing the Underlying Container
--------------------------------------------------------------------------
[example: raw_container.cpp](../example/typebuffer/raw_container.cpp)

```c++
std::vector<int> & con = buffer.get_container();
con.resize(12);
```

4 Typebuffer Interface
==========================================================================
1 Create an Typebuffer Interface
--------------------------------------------------------------------------
[example: ](../example/typebuffer/interface.cpp)

```c++
typebuffer_interface<char> * char_buff
  = new typebuffer<char, std::vector<char> >();
```

2 Adding / Removing values from Typebuffer Interface
--------------------------------------------------------------------------
[example: ](../example/typebuffer/interface.cpp)

```c++
char_buff.push(value);
```

5 Typebuffer Container
==========================================================================
1 Description
--------------------------------------------------------------------------
A container for typebuffers regradless of value type or container type.

2 Creating a Container Instance
--------------------------------------------------------------------------
[example: container.cpp](../example/typebuffer/container.cpp)

```c++
typebuffer_container container_1;
```

3 Adding Typebuffers to a Container
--------------------------------------------------------------------------
[example: container.cpp](../example/typebuffer/container.cpp)

```c++
set_typebuffer<int, std::vector<int> >(container_1);
```

4 Checking Container for Typebuffer
--------------------------------------------------------------------------
[example: container.cpp](../example/typebuffer/container.cpp)

```c++
has_typebuffer<int>(container_1);
```

5 Retriving a Typebuffer from a Container
--------------------------------------------------------------------------
[example: container.cpp](../example/typebuffer/container.cpp)

```c++
use_typebuffer<int>(container_1);
```

6 Checking if a buffer is empty
--------------------------------------------------------------------------
[example: empty.cpp](../example/typebuffer/empty.cpp)

```c++
  if (empty<std::string>(con1) == false){
```

7 Clearing data in a buffer
--------------------------------------------------------------------------
[example: clearing.cpp](../example/typebuffer/clearing.cpp)

```c++
clear<std::string>(con1);

clear(con1);
```
