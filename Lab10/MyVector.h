#ifndef MYVECTOR_H
#define MYVECTOR_H
#include "DebugNewOp.h"
#include <stdexcept>

class MyVector {
private:
	int m_size;
	double* pItems;

	bool rangeCheck(int index) const;
public:
	MyVector() :m_size(0), pItems(nullptr) {}

	MyVector(int size): pItems(nullptr),m_size(size){
		if (size < 0) {
			throw std::length_error("please enter a valid length");
		}

		if (size > 0) {
			pItems = new double[m_size] {};
		}
	}

	~MyVector() {
		delete pItems;
		pItems = nullptr;
	}

	//get the size of the array
	int size() const { return m_size; }

	//get the element at the given index
	double get(int index) const;

	// set the element at the given index
	void set(int index, double value);


};

#endif