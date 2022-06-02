<!-- FILE HEADER -->
<!-- NAME: HADEID MIRZA -->
<!-- ID: ahmirza@wisc.edu -->
<!-- REFERENCES:  NONE  -->

# Union-Find Data Structure

## Program Description 

 > This program demoes the functionality of the Union-Find data structure in C++. The UnionFind data structure can union two disjoin-sets or find the root of a set with a particular value. You can read more about the data structure [here](https://en.wikipedia.org/wiki/Disjoint-set_data_structure). This implementation uses **<em>union</em> by rank** and **<em>find</em> by path compression**. The demo uses a **graph** which has a containsCycle() method that uses Union-Find to check if there are cycles in the graph. To run this demo or use the data structure itself, you need to have the **g++ compiler** and **GNU Make** installed on your machine.  

## Compilation Instructions :
- Use `make build` to preprocess and compile demo executable
- Use `make clean` to remove executable and object files

## Run Instructions :
- Use `./UnionFindDemo` to run demo executable 
- You can also use `make` to **build and run** demo executable at the same time.

## Organization of code 
- The header files `SetUF.h`, `UnionFind.h`, and `Graph.h` contain all function definitions of the templated classes SetUF, UnionFind, and Graph.
- `demo.cpp` contains code that is used to demo the functionality of the data strucure


