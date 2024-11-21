#include "MyVector.h"

MyVector::MyVector(int size) : pItems(nullptr), m_size(size) {
	if (size < 0) {
		throw std::length_error("please enter a valid length");
	}

	if (size > 0) {
		pItems = new double[m_size + 1] {};
	}
}

MyVector::MyVector(const std::initializer_list<double>& list) : MyVector(static_cast<int>(list.size()))
{
	if (list.size() > 0) {
		int count = 0;
		for (auto& element : list) {
			pItems[count] = element;
			++count;
		}
		pItems[count] = '\0';
	}
}

MyVector::MyVector(const MyVector& v) : MyVector(v.size()) {
	for (int i = 0; i < v.size(); i++) {
		pItems[i] = v.get(i);
	}
	pItems[v.size()] = '\0';
}



bool MyVector::rangeCheck(int index) const {
	if (index > m_size - 1 || index < 0) {
		throw std::out_of_range("index out of range");
	}
	return true;
}



double MyVector::get(int index) const {
	if (rangeCheck(index)) {
		return pItems[index];
	}
}

void MyVector::set(int index, double value) {
	if (rangeCheck(index)) {
		pItems[index] = value;
	}
}

MyVector& MyVector::operator=(const MyVector& v) {
	//need to check if it the address of v object is the same as this
	if (this == &v) { return *this; }

	//it's delete the existing array. coz later we need assign new memory location for pItems
	delete[] pItems;

	if (v.m_size > 0) {
		m_size = v.m_size;
		//m_size + 1, because we are using array, the last element is '\0'
		pItems = new double[v.m_size + 1];

		for (int i = 0; i < v.m_size; i++) {
			pItems[i] = v.pItems[i];
		}
		pItems[m_size] = '\0';
	}
	else {
		pItems = nullptr;
	}

	return *this;
}

double& MyVector::operator[](int index) {
	if (rangeCheck(index)) {
		return pItems[index];
	}
}

const double& MyVector::operator[](int index) const {
	if (rangeCheck(index)) {
		return pItems[index];
	}
}


std::ostream& operator<<(std::ostream& out, const MyVector& v) {
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

