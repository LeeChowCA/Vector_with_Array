#ifndef MYVECTOR_H
#define MYVECTOR_H
#include "DebugNewOp.h"
#include <stdexcept>
#include <ostream>
#include <initializer_list>


class MyVector {
private:
	int m_size{};
	double* pItems{};

	bool rangeCheck(int index) const;
public:
	MyVector() :m_size(0), pItems(nullptr) {}


	//because we want to prevent the situation like MyVector v = 10; so put explicit before
	explicit MyVector(int size);

	//we use const std::initializer_list<double>& list to receive the initializer list being passed in
	MyVector(const std::initializer_list<double>& list);

	//copy constructor for case like MyVector v3(v1).
	MyVector(const MyVector& v);

	//destructor
	~MyVector() {
		delete[] pItems;
		pItems = nullptr;
	}

	//get the size of the array
	int size() const { return m_size; }

	//get the element at the given index
	double get(int index) const;

	// set the element at the given index
	void set(int index, double value);

	//pass by reference of the MyVector object
	MyVector& operator=(const MyVector& v);

	//this is used for regular subscript operator, the return value can be changed
	double& operator[](int index);

	//this is for const MyVector type, in this case the return value can't be changed.
	const double& operator[](int index) const;	
};

//overload the << operator to output the elements stored in the array in [ e1, e2, e3 ...] format.
std::ostream& operator<<(std::ostream& out, const MyVector& v);

#endif