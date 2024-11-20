#include "MyVector.h"
bool MyVector::rangeCheck(int index) const{
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