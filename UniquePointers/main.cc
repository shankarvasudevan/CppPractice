#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
	std::unique_ptr<int> foo;

	if (foo == nullptr)
	{
		std::cout << "Default value is nullptr" << std::endl;
	}
	else
	{
		std::cout << "Default value is " << foo << std::endl;
	}

}
