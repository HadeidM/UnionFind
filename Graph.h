//////// file header /////////////////////////////////////
// name: Hadeid Mirza
// id: ahmirza@wisc.edu (9082655383)
// brief description: Graph.h file contains all the function
// prototypes and definitions for the templated Graph class.  
// references used: none
//////////////////////////////////////////////////////////

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <set>
#include <utility>
#include "UnionFind.h"

template<typename T> using Edge = std::pair<T, T>;

/**
 * This class models a simple graph with edges and vertices
 */
template<typename T>
class Graph {

  using Edge = std::pair<T, T>;
  
private:
  std::set<T> vertices;
  std::vector<Edge> edges;
  
public:
  /**
   * Constructor for a graph object.
   *
   * @param v - the set of vertices of the graph
   * @param e - the set of edges in the graph
   */
  Graph(std::set<T> v, std::vector<Edge> e): vertices(v), edges(e) {}
  /**
   * Adds an edge to an existing graph object
   *
   * @param e - the new edge that is to be added to the graph
   */
  void addEdge(Edge e) { edges.push_back(e); };
   /**
   * Checks if a graph object contains a cycle 
   *
   * return a boolean value depending on the cycle existence
   */
   bool containsCycle();
};

  /**
   * Checks if a graph object contains a cycle. The algorithm  
   * checks every node and then unions two nodes together if their
   * roots are not the same. It keeps going until a cycle is found.
   * 
   * @return true if the graph contains a cycle, otherwise
   *         return false.
   */
template<typename T>
bool Graph<T>::containsCycle() {
  UnionFind<T> uFind(vertices);
  for (Edge &e: edges) {
    SetUF<T> &xRoot = uFind.find(e.first);
    SetUF<T> &yRoot = uFind.find(e.second);
    if (xRoot == yRoot)
      return true;
    uFind.unionOp(xRoot,yRoot);
  }
  return false;
}

#endif
