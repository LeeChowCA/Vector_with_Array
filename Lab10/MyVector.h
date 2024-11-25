#ifndef MYVECTOR_H
#define MYVECTOR_H
#include "DebugNewOp.h"
#include <stdexcept>
#include <iostream>
#include <initializer_list>
#include "DebugNewOp.h"
#include "MyVector.h"
#include <cassert>
#include <vector>
#include "Cents.h"


template<typename T>
class MyVector {
private:
	int m_size{};
	T* pItems{};
	bool rangeCheck(int index) const;
	int m_capacity{};

public:
	MyVector() :m_size(0), m_capacity(0), pItems(nullptr) {}


	//because we want to prevent the situation like MyVector v = 10; so put explicit before
	explicit MyVector(int size);

	//we use const std::initializer_list<double>& list to receive the initializer list being passed in
	MyVector(const std::initializer_list<T>& list);

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
	T get(int index) const;

	// set the element at the given index
	void set(int index, T value);

	//pass by reference of the MyVector object
	MyVector& operator=(const MyVector& v);

	//this is used for regular subscript operator, the return value can be changed
	T& operator[](int index);

	//this is for const MyVector type, in this case the return value can't be changed.
	const T& operator[](int index) const;

	// this is a getter that's used to return the capacity of MyVector.
	int capacity() const;

	//this function is used to reserve the capacity of MyVector
	void reserve(int newCapacity);

	//this is used to resize the size of MyVector.
	void resize(int newSize);

	//this push the element into the end of MyVector
	void push_back(T value);

	// this will return the last element in MyVector and reduce the size by 1
	T pop_back();


};

template<typename T>
//overload the << operator to output the elements stored in the array in [ e1, e2, e3 ...] format.
std::ostream& operator<<(std::ostream& out, const MyVector<T>& v) {
	if (v.size() == 0) {
		out << "[]";
		return out;
	}

	out << "[";

	for (int i = 0; i < v.size() - 1; i++) {
		out << v.get(i) << ", ";
	}

	out << v.get(v.size() - 1) << "]";
	return out;
}


template<typename T>
MyVector<T>::MyVector(int size) : pItems(nullptr), m_size(size), m_capacity(size) {
	if (size < 0) {
		throw std::length_error("please enter a valid length");
	}

	if (size > 0) {
		pItems = new T[m_size] {};
	}
}
template<typename T>
MyVector<T>::MyVector(const std::initializer_list<T>& list) : MyVector(static_cast<int>(list.size()))
{
	if (list.size() > 0) {
		int count = 0;
		for (auto& element : list) {
			pItems[count] = element;
			++count;
		}
	}
}
template<typename T>
MyVector<T>::MyVector(const MyVector& v) : MyVector(v.size()) {
	for (int i = 0; i < v.size(); i++) {
		pItems[i] = v.get(i);
	}
}


template<typename T>
bool MyVector<T>::rangeCheck(int index) const {
	if (index > m_size - 1 || index < 0) {
		throw std::out_of_range("index out of range");
	}
	return true;
}

template<typename T>
T MyVector<T>::get(int index) const {
	if (rangeCheck(index)) {
		return pItems[index];
	}
}
template<typename T>
void MyVector<T>::set(int index, T value) {
	if (rangeCheck(index)) {
		pItems[index] = value;
	}
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& v) {
	//need to check if it the address of v object is the same as this
	if (this == &v) { return *this; }

	//it's delete the existing array. coz later we need assign new memory location for pItems
	delete[] pItems;

	if (v.m_size > 0) {
		m_size = v.m_size;
		m_capacity = m_size;
		//m_size + 1, because we are using array, the last element is '\0'
		pItems = new T[v.m_size];

		for (int i = 0; i < v.m_size; i++) {
			pItems[i] = v.pItems[i];
		}
	}
	else {
		pItems = nullptr;
	}

	return *this;
}

template<typename T>
T& MyVector<T>::operator[](int index) {
	if (rangeCheck(index)) {
		return pItems[index];
	}
}
template<typename T>
const T& MyVector<T>::operator[](int index) const {
	if (rangeCheck(index)) {
		return pItems[index];
	}
}


template<typename T>
int MyVector<T>::capacity() const {
	return m_capacity;
}

template<typename T>
void MyVector<T>::reserve(int newCapacity) {
	if (newCapacity > m_capacity) {
		T* temp = new T[newCapacity] {};

		for (int i = 0; i < m_capacity; i++) {
			temp[i] = pItems[i];
		}

		delete[] pItems;

		pItems = temp;

		m_capacity = newCapacity;
	}
}

template<typename T>
void MyVector<T>::resize(int newSize) {
	if (newSize < 0) throw std::length_error("length should be greater than 0");
	reserve(newSize);

	for (int i = m_size; i < newSize; i++) {
		pItems[i] = 0;
	}

	m_size = newSize;
}

template<typename T>
void MyVector<T>::push_back(T value) {
	if (m_capacity == 0) reserve(8);
	if (m_size == m_capacity) reserve(2 * m_size);
	pItems[m_size] = value;
	m_size++;
}

template<typename T>
T MyVector<T>::pop_back() {
	if (m_size == 0) throw std::exception("cannot pop_back() an empty vector");

	T valueToReturn{ pItems[m_size - 1] };

	resize(m_size - 1);

	return valueToReturn;
}




#endif