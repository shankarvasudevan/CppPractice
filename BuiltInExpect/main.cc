#include <iostream>

int main(int argc, char* argv[])
{
	bool check = true;

	bool basicCheck = !!(!check);
	bool builtInCheck = __builtin_expect(!!(!check), 0); 

	std::cout << std::boolalpha << basicCheck << std::endl;
	std::cout << std::boolalpha << builtInCheck << std::endl;

	return 0;
}
