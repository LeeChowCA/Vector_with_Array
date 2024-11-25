//#include "TestSuite.h"
#include "TestSuiteTemplate.h"


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
	//MyVector v{ 1.1, 2.2 };
	//std::cout << v[0] << '\n'; // should output 1.1
	//v[0] = 9.9;
	//std::cout << v[0] << '\n'; // should output 9.9
	//const MyVector constVec{ 3.3, 4.4 };
	//std::cout << constVec[0]; // should output 3.3
	// 
		//std::vector<Cents> v; // a vector for doing some tests with
		//int iterations = 20;
		//v.reserve(iterations);
		//std::cout << "adding items:\n";
		//for (int i = 0; i < iterations; i++) {
		//	// add an item to the vector
		//	v.push_back(0.0);
		//	// print out some stats
		//	std::cout << "v.size:" << v.size() << ", v.capacity:" << v.capacity() << "\n";
		//}
		//std::cout << "removing items:\n";
		//for (int i = 0; i < iterations; i++) {
		//	// remove an item from the vector
		//	v.pop_back();
		//	// print out some stats
		//	std::cout << "v.size:" << v.size() << ", v.capacity:" << v.capacity() << "\n";
		//}

		MyVector<int> v{};
		
		for (int i = 0; i < 20; i++) {
			v.push_back(0.0);

			std::cout << v.size() << v.capacity() << "\n";
		}

		



	}

    catch (const std::exception& error) {
		std::cerr << "Exception caught: " << error.what() << std::endl;
    }
	

}


int main() {
	_CrtMemDumpAllObjectsSince(NULL); // for detecting memory leaks
	//TestSuite::runTestSuite();
	TestSuiteTemplate::runTestSuite();

	//tests();

	return 0;

}