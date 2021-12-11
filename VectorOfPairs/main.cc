#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{

	std::vector<std::pair<std::string, std::string>> vec;
	vec.emplace_back("foo", "aaa");
	vec.emplace_back("bar", "bbb");

	for (const auto& i : vec)
	{
		std::cout << "Key: " << i.first << std::endl;
		std::cout << "Value: " << i.second << std::endl;
	}

	return 0;
}

