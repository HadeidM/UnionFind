//////// file header /////////////////////////////////////
// name: Hadeid Mirza
// id: ahmirza@wisc.edu
// brief description: This header file contains all the 
// function definitions for the templated class UnionFind 
// references used: none
//////////////////////////////////////////////////////////

#ifndef _UF_
#define _UF_
	
#include <set>
#include <map>
#include "SetUF.h" 
#include <iostream>

/**
 * This class models the UnionFind data structure, it uses union by rank and
 * path compression finding for the singletons or SetUFs. 
 */
template <typename T>
class UnionFind {

	public:
	/**
	 * Parameterized constructor for the class. 
  	 * @param singletons - a set of elements of the T datatype
	 */
	UnionFind(const std::set<T> &singletons) {
		auto itr = singletons.cbegin();
		while (itr != singletons.cend()) {
			this->sets.insert({*itr, SetUF<T>(*itr)});
			++itr;
		}
	}
	/**
	 * Finds and returns the root of the set to which the input value belongs
     * 
	 * @param value - the value to query in the data structure
	 * @return the root of the set that has the input value
	 */
	SetUF<T>& find(const T value) const {
		if (this->sets.find(value) == sets.end()) {
			return const_cast<SetUF<T>&>(nullSet);
		}
		auto itr = const_cast<UnionFind<T>*>(this)->sets.find(value);
		if (*((itr->second).parent) != value) {
			(itr->second).parent = &(find(*((itr->second).parent)));
			return const_cast<SetUF<T>&>(*((itr->second).parent));
		} else {
			return itr->second;
		}
	}
	/**
	 * unions two sets together by considering the rank. Usually makes 
  	 * the higher rank parent the parent of the lower ranked set. If the 
 	 * ranks are the same, then increments the rank of one root and makes 
 	 * the other root the child of that root. 
 	 *
	 * @param x - an instance of the SetUF class
 	 * @param y - a SetUF object reference.
	 */
	void unionOp(SetUF<T> &x, SetUF<T> &y) { 
		if (this->sets.find(x.value) == this->sets.end()) {
			this->sets.insert({x.value, SetUF<T>(x.value)});
		} 
		if (this->sets.find(y.value) == this->sets.end()) {
			sets.insert({y.value, SetUF<T>(y.value)});
		} 
		SetUF<T>& xroot = this->find(x.value);
		SetUF<T>& yroot = this->find(y.value);
		if (xroot.value == yroot.value) {
			return;
		}
		if (xroot.rank < yroot.rank) {
			xroot.parent = &yroot;
		} else if (yroot.rank < xroot.rank) {
			yroot.parent = &xroot;
		} else {
			xroot.parent = &yroot;
			yroot.rank = yroot.rank + 1;
		}
	}
	/**
	 * Overloading of the UnionOp that takes a T datatype instance instead of a
 	 * SetUF instance
 	 *
 	 * @param x - the T datatype instance
	 * @param y - the SetUF<T> instance
	 */
	void unionOp(T x, SetUF<T> &y) {
		SetUF<T> newNode(x);
		unionOp(newNode, y);
	}
	/**
	 * Overloading of the UnionOp that takes a T datatype instance instead of a
 	 * SetUF instance
 	 *
 	 * @param x - the SetUF<T> instance
	 * @param y - the T datatype instance
	 */
	void unionOp(SetUF<T> &x, T y) {
		SetUF<T> newNode(y);
		unionOp(x, newNode);	
	}
	/**
	 * Overloaded UnionOp method that takes in both T datatype instances
 	 * 
	 * @param x - T datatype instance 
	 * @param y - T datatype instance
	 */
	void unionOp(T x, T y) {
		SetUF<T> newNode1(x);
		SetUF<T> newNode2(y);

		unionOp(newNode1, newNode2);
	}

	private:
	std::map<T,SetUF<T>> sets{};
	const static SetUF<T> nullSet;
};

template <typename T> const SetUF<T> UnionFind<T>::nullSet;
#endif
