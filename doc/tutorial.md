Typesystems Tutorial
==========================================================================
`
   typesystem                                              
+------------------------------------------+               
|                                          |               
|                        +------------+    |               
|                        | typebuffer | 2  |               
|           +------------+------------+ <----------+       
|           |                              |       |       
|           |                              |       |       
|           v3                             |       |       
| +---------+------------+ 5               | +-----+-----+ 
| | typebuffer_interface | <--+            | | container | 
| +-----------+----------+    |            | +-----------+ 
|             |               |            |           ^1  
|             |    +----------+-----+      |           |   
|             |    |  put_rewriter  | 4    |        +--+--+
|             |    +----------------+ <-------------+  T  |
|             |                            |        +--+--+
|             |                            |           ^7  
|             |  6 +-----------------+     |           |   
|             +--> |   get_rewriter  +-----------------+   
|                  +-----------------+     |               
|                                          |               
+------------------------------------------+               
`
figure 1: overview of typesystems, without type ids.
1. A container for type 'T' is created.
2. The container is used by the typebuffer adapter.
3. The typebuffer_interface is used to access the adapter.
4. The rewriter then exams 'T' and converts it if necessary.
5. The typebuffer_interface is used to store 'T'.
6. The typebuffer_interface is used to retrieve 'T'.
7. A rewriter exams 'U' and converts it to 'T' if necessary.

1. [Explicit Typeid Tutorial](./explicit_typeid_tutorial.md)
2. [Typebuffer Tutorial](./typebuffer_tutorial.md)
3. [Rewriter Tutorial](./rewriter_tutorial.md)
4. [Typesystem Tutorial](./typesystem_tutorial.md)
