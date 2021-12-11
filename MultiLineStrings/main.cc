#include <iostream>

int main(int argc, char* argv[])
{
	const std::string& fooStr = R"(
		SELECT foo1, foo2, foo3, foo4, foo5 
		FROM my_table
		WHERE foo5 > $1)";

	std::cout << fooStr << std::endl;

	return 0;
}
