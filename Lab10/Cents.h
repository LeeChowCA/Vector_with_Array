#pragma once
#include <iostream>

class Cents {
private:
	int value;
public:
	Cents(int newValue = 0) : value(newValue) {}
	int getValue() const { return value; }

	Cents(const Cents& c) :value(c.value){
		static int counter{ 0 };
		counter++;
		std::cout << "cents cc" << counter << "\n";
	}
};

// a quick and dirty override to output a Cents object
std::ostream& operator<<(std::ostream& out, const Cents& c);

inline bool operator==(const Cents& a, const Cents& b) {
	return a.getValue() == b.getValue();
}
inline bool operator<(const Cents& a, const Cents& b) {
	return a.getValue() < b.getValue();
}


