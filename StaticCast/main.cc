#include <iostream>
#include <optional>

struct Foo
{
	int mValue;
};

int main(int argc, char* argv[])
{

	std::optional<Foo> f1;
	std::optional<Foo> f2;

	f1 = Foo{42};

	bool b1 = static_cast<bool>(f1);
	bool b2 = static_cast<bool>(f2);

	std::cout << b1 << std::endl; // True because the optional has a value	
	std::cout << b2 << std::endl; // False because the optional does not have a value

	return 0;
}
