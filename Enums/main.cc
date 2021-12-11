#include <iostream>

enum Choice { Foo, Bar };

int main(int argc, char* argv[])
{
	Choice c1 = Choice::Foo;
	Choice c2 = Choice::Bar;

	std::cout << "c1 = " << c1 << std::endl;
	std::cout << "c2 = " << c2 << std::endl;

	std::cout << "c1_int = " << static_cast<int>(c1) << std::endl;
	std::cout << "c2_int = " << static_cast<int>(c2) << std::endl;

	return 0;
}
