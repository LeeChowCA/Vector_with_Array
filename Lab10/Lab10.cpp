#include "TestSuite.h"
#include "DebugNewOp.h"
#include "MyVector.h"
#include <iostream>
#include <cassert>


void tests() {
	try {
		//MyVector v1;
		//MyVector v2(-1);
		//MyVector v3(3);

		//v3.set(2, 10.5);
		//std::cout << v3.get(2) << " size: " << v3.size();

		//v3.get(4);
		//v3.set(4, 10.00);

		//std::cout << v3;

		//MyVector v4{ 1,2,3,4 };

		//std::cout << v4;


		//MyVector v1{ 1.5, 2.5 };
		//MyVector v2 = v1; // copy constructor called
		//MyVector v3(v1); // copy constructor called
		//v3.set(0, 9); // check if a change here affects the original.
		//std::cout << v1 << v2 << v3;

		//MyVector v1{ 1.5, 2.5 };
		//MyVector v2;
		//v2 = v1;
		//const MyVector v3{ 1,2 };

		//std::cout << v1 << " " << v2;

		//std::cout << v1[1] << " " << v3[1];
		// 
		

	MyVector v{ 1.1, 2.2 };
	std::cout << v[0] << '\n'; // should output 1.1
	v[0] = 9.9;
	std::cout << v[0] << '\n'; // should output 9.9
	const MyVector constVec{ 3.3, 4.4 };
	std::cout << constVec[0]; // should output 3.3

	}

    catch (const std::exception& error) {
		std::cerr << "Exception caught: " << error.what() << std::endl;
    }
	

}


int main() {
	 TestSuite::runTestSuite();
	_CrtMemDumpAllObjectsSince(NULL); // for detecting memory leaks

	//tests();

	return 0;

}