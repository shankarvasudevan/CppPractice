#include <iostream>

class Foo
{
public:
	explicit Foo(int value) : mValue(value) { }

	void Bar(int& x) const
	{
		x++;
	}

private:
	int mValue;
};

int main(int argc, char* argv[])
{
	Foo f{42};

	int a = 10;
	f.Bar(a);

	std::cout << a << std::endl;
}
