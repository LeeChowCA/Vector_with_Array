 #include "TestSuite.h"
#include "DebugNewOp.h"
#include "MyVector.h"
#include <iostream>
#include <cassert>


void tests() {
	try {
		MyVector v1;
		//MyVector v2(-1);
		MyVector v3(3);

		v3.set(2, 10.5);
		std::cout << v3.get(2) << " size: " << v3.size();

		//v3.get(4);
		v3.set(4, 10.00);
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