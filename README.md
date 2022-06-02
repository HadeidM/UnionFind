<!-- FILE HEADER -->
<!-- NAME: HADEID MIRZA -->
<!-- ID: ahmirza@wisc.edu, 9082655383     -->
<!-- DESCRIPTION: This program demoes the functionality of the UnionFind data structure that I have implemented --> 
<!-- REFERENCES:  NONE  -->

## Program Description 

 > This program demoes the functionality of the UnionFind data structure. The UnionFind data structure can union two disjoin-sets or find the root of a set with a particular value. 
 
   This implementation uses **union by rank** and **find by path compression**.
  
   The demo uses a graph which in turn has a containsCycle() method that uses UnionFind to check if there are cycles in the graph.

## Compilation Instructions :
- Use `make build` to preprocess and compile demo executable
- Use `make clean` to remove executable and object files

## Run Instructions :
- Use `./UnionFindDemo` to run demo executable 
- You can also use `make` to **build and run** demo executable at the same time.

## Organization of code 
- The header files `SetUF.h`, `UnionFind.h`, and `Graph.h` contains all function definitions of the templated classes SetUF, UnionFind, and Graph.
- `demo.cpp` contains code that is used to demo the functionality of the data strucure


