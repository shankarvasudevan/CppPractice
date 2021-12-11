#include <iostream>
#include <vector>

class Foo
{
public:
	explicit Foo(int value) : mValue(value) { }

	void Print()
	{
		std::cout << mValue << std::endl;
	}

private:
	int mValue;
};

int main(int argc, char* argv[])
{
	Foo f{42};

	f.Print();

	std::vector<Foo*> vec;
	vec.push_back(&f);

	auto it = vec.begin();
	vec.erase(it);

	f.Print();
}
