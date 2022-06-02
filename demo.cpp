//////// file header /////////////////////////////////////
// name: Hadeid Mirza
// id: ahmirza@wisc.edu 
// brief description: This demo source file demoes the 
// functionality of the UnionFind data structure  
// references used: none
//////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <set>
#include "Graph.h"

using namespace std;

/**
 * The student class models a simple student with an id and name.
 */
class Student {
/**
 * Output stream operator for the Student class. 
 *
 * @param strm - an instance of the output stream operator
 * @param stud - a constant refernce to a student object 
 * @return a reference of an ostream instance
 */
 friend ostream& operator<<(ostream &strm, const Student &stud) {
    return strm << "student(" << stud.id << ", " << stud.name << ")";
  }
/**
 * less than operator for the Student class. 
 *
 * @param lhs - an instance of the student class
 * @param rhs - an instance of the student class
 * @return true if lhs is less than rhs, false otherwise
 */
 friend bool operator<(const Student &lhs, const Student &rhs) {
    return lhs.id < rhs.id;
  }
/**
 * equals comparator operator for the Student class. 
 *
 * @param lhs - an instance of the student class
 * @param rhs - an instance of the student class
 * @return true if lhs is equal to rhs, false otherwise
 */
 friend bool operator==(const Student &lhs, const Student &rhs) {
    return lhs.id == rhs.id;
  }
/**
 * not equals comparison operator for the Student class. 
 *
 * @param lhs - an instance of the student class
 * @param rhs - an instance of the student class
 * @return true if lhs is not equal to rhs, false otherwise
 */
 friend bool operator!=(const Student &lhs, const Student &rhs) {
    return lhs.id != rhs.id;
  }

public:
/**
 * default constructor for Student class 
 */
 Student() = default;
 /**
 * parameterized constructor for the Student class. 
 *
 * @param id - the id of the student
 * @param name - the name of the student
 */ 
 Student(int id, string name): id(id), name(name) {}
  
private:
  int id;
  string name;  
};

int main(){
  Student marc(0, "Marc");
  Student kyle(1, "Kyle");
  Student hemant(2, "Hemant");
  Student shanmathi(3, "Shanmathi");
  Student kate(4, "Kate");	
  Student lol(6, "lol");
  set<Student> vertices{ marc, kyle, hemant, shanmathi, kate };
  vector<Edge<Student>> edges{ {marc, kyle}, {marc, hemant}, {kyle, shanmathi}, {kyle, kate} };
  Graph<Student> graph(vertices, edges);
  cout << graph.containsCycle() << "\n"; //No cycle
  graph.addEdge({hemant, shanmathi});
  cout << graph.containsCycle() << "\n"; //Cycle

  // Additional test containing cycle.
  int one = 1;
  int two = 2;
  int three = 3; 
  int four = 4;
  int five = 5;
  set<int> verticesNew{one, two, three, four, five};
  vector<Edge<int>> edgesNew{{one, two}, {two, three}, {one, four}, {four, five}, {three, four}};
  Graph<int> graphNew(verticesNew, edgesNew);
  cout<< graphNew.containsCycle() << "\n";
 
  // additional test full binary tree
  int six = 6;
  int seven = 7;
  int eight = 8;
  int nine = 9;
  int ten = 10; 
  int eleven = 11;
  int twelve = 12;
  int thirteen = 13;
  int fourteen = 14; 
  int fifteen = 15; 
  
  set<int> vertices_two{one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen};
  vector<Edge<int>> edges_two{{one, two}, {one, three}, {two, four}, {two, five}, {three, six}, {three, seven}, {four, eight}, 
							  {four, nine}, {five, ten}, {five, eleven}, {six, twelve}, {six, thirteen}, {seven, fourteen}, {seven, fifteen}};
  Graph<int> binaryTree(vertices_two, edges_two);
  cout<< binaryTree.containsCycle() << "\n";


}
