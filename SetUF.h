//////// file header /////////////////////////////////////
// name: Hadeid Mirza
// id: ahmirza@wisc.edu (9082655383)
// brief description: This header file contains all the 
// function definitions for the templated class SetUF 
// references used: none
//////////////////////////////////////////////////////////

#ifndef _SET_UF_
#define _SET_UF_
#include "UnionFind.h"

/**
 * A templated class SetUF models a set in the union find data
 * structure. It is a collection of items. They are similar to nodes
 * in a tree structure
 */
template<typename T> class UnionFind; 
template <typename T>
class SetUF {
    /**
     * UnionFind is the friend class of SetUF as it uses all the 
	 * private member variables of a setUF.
     */
	friend class UnionFind<T>;
	public:
	/**
	 * The default constructor for the SetUF class.
  	 */
	SetUF(): parent(this) {}
	/**
	 * Parameterized cosntructor for SetUF that takes in a value
     * for setting the private variable 'value' of this class
  	 * @param v - the value of the user-choice class.
	 */
	SetUF(T v): value(v), parent(this) {}
	/** 
	 * copy c-tor for the SetUF class
 	 * 
	 * @param a - a const reference of a SetUF instance
	 *
	 */
	SetUF(const SetUF &a): value(a.value), rank(0), parent(this) {} 
	/**
	 * the assignment operator for the SetUF class
	 * 
 	 * @param a - a const reference to a SetUF instance.
	 */
	SetUF<T>& operator=(const SetUF &a) {
		if(this != &a) {
			value = a.value;
			rank = 0;
			parent = this;
		}
		return *this;
	}
	/**
	 * Conversion operator that implicitly converts a setUF to a the template Value 
 	 *
 	 * @return the value of the template datatype 
	 */
	operator T() const {
		return value;
	}

	private:
	T value{};
	unsigned rank{0};
	SetUF<T> *parent{};

};

#endif
