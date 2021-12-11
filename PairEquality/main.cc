#include <iostream>
#include <utility>

int main(int argc, char* argv[])
{
	std::pair<std::string, std::string> p1 = std::make_pair("foo", "bar");
	std::pair<std::string, std::string> p2 = std::make_pair("foo1", "bar1");
	std::pair<std::string, std::string> p3 = std::make_pair("foo", "bar");

	bool first = p1 == p2;
	bool second = p1 == p3;

	std::cout << first << std::endl;
	std::cout << second << std::endl;

	return 0;	
}
