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


UnionFind.o: SetUF.h UnionFind.h
Graph.o: Graph.h
Demo.o: UnionFind.o Graph.o

clean: 
	-rm *.o
	-rm UnionFindDemo

preprocess: Demo.o 
	$(CXX) -c -o Demo.o demo.cpp 

build: preprocess
	$(CXX) $(CXXFLAGS) -o UnionFindDemo Demo.o
