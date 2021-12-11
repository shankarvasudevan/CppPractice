#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

int main(int argc, char* argv[])
{
	std::vector<double> vec;
	
	std::cout << "Without reserving size" << std::endl;
	std::cout << "Begin: " << std::addressof(*vec.begin()) << std::endl;
	std::cout << "End: " << std::addressof(*vec.end()) << std::endl;	

	vec.reserve(20);
	std::cout << "With reserving size" << std::endl;
	std::cout << "Begin: " << std::addressof(*vec.begin()) << std::endl;
	std::cout << "End: " << std::addressof(*vec.end()) << std::endl;

	std::cout << "Using lower_bound" << std::endl;
	
	double value = 42;
	auto insertPoint = std::lower_bound(vec.begin(), vec.end(), value);
	
	std::cout << "Insert point: " << std::addressof(*insertPoint) << std::endl;
	bool isInsertPointSameAsEnd = insertPoint == vec.end();

	std::cout << "Same as end: " << isInsertPointSameAsEnd << std::endl;
}
