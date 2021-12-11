#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

int main(int argc, char* argv[])
{
	std::pair<std::string, std::string> p1 = std::make_pair("foo1", "bar1");
	std::pair<std::string, std::string> p2 = std::make_pair("foo2", "bar2");
	std::pair<std::string, std::string> p3 = std::make_pair("foo3", "bar3");

	std::vector<std::pair<std::string, std::string>> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);

	auto elem1 = std::find_if(vec.begin(), vec.end(), [&](const auto& v) { return v.first == "foo2"; });

	std::cout << elem1->first << "," << elem1->second << std::endl;

	auto elem2 = std::find_if(vec.begin(), vec.end(), [&](const auto& v) { return v.first == "foo4"; });

	bool result = elem2 == vec.end();
	std::cout << result << std::endl;	

	return 0;	
}
