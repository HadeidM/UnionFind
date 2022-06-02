# // FILE HEADER //
# Name:        Hadeid Mirza
# Student ID:  9082655383, ahmirza@wisc.edu
# Description: This program demoes the functionality of the UnionFind data structure using graphs and 
#			   using a containsCycle method
# Sources:     None

CXX=g++
CXXFLAGS=-Wall

all: build 
	./UnionFindDemo


SetUF.o: SetUF.h 
Graph.o: Graph.h
UnionFind.o: SetUF.o Graph.o 

clean: 
	-rm *.o
	-rm UnionFindDemo

preprocess: UnionFind.o 
	$(CXX) -c -o UnionFind.o demo.cpp 

build: preprocess
	$(CXX) $(CXXFLAGS) -o UnionFindDemo UnionFind.o
