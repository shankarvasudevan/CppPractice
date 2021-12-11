#include <iostream>
#include <boost/algorithm/string.hpp>
#include <unordered_map>

int main(int argc, char* argv[])
{
	std::unordered_map<std::string, int> values;
	values["A"] = 1;
	values["B"] = 2;
	values["C"] = 3;
	
	std::string result = boost::algorithm::join(values, ",");

	std::cout << result << std::endl;
		
	return 0;
}
