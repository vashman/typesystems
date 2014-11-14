Typesystem Tutorial
==========================================================================
Copyright Sundeep S. Sangha 2013 - 2014.

Distributed under the Boost Software License, Version 1.0.
 (See accompanying file `../LICENSE_1_0.txt` or copy at
       `http://www.boost.org/LICENSE_1_0.txt`)

All examples can be found in the [example/typesystem](../example/
typesystem) directory.

1 Table of Contents
==========================================================================
1. Table of Contents
2. Creating Typesystems
3. Adding a Type
4. Checking if a Type is Avaliable
5. Retriving a Rewriter Interface

2 Creating Typesystems
==========================================================================
[example: create.cpp](../exmaple/typesystem/create.cpp)

```c++
typesystem typesys;
```

3 Adding a Type
==========================================================================
[example: types.cpp](../exmaple/typesystem/types.cpp)

```c++
set_typebuffer<int, std::vector<int> >(typesys);
```

4 Checking if a Type is Avaliable
==========================================================================
Types can be represented by themeselves or a rewriter. ultimatly in only
matters if there is a rewriter that can be used to either get or put a
particular type of variable.

[example: rewriter.cpp](../example/typesystem/rewriter.cpp)

```c++
  if (has_put_rewriter(typesys) == true){

  if (has_get_rewriter(typesys) == true){
```

5 Retriving a Rewriter Interface
==========================================================================
[example: interface.cpp](../example/typesystem/interface.cpp)

```c++
get_rewriter<int> grw = use_get_rewriter<int>(typesys);

put_rewriter<char> prw = use_put_rewriter<char>(typesys);
```
