#include <iostream>

void copy_string_and_print(const std::string& str)
{
	std::string strCpy = str;
	std::cout << "Copy: " << strCpy << std::endl;
}

int main(int argc, char* argv[])
{
	copy_string_and_print("foo");
	return 0;
}
