#include <iostream>
#include <functional>
#include <optional>
#include <unordered_set>

class Foo
{
public:
	Foo() : mValue{0} { std::cout << "Empty constructor" << std::endl; }
	Foo(int value) : mValue{value} { std::cout << "Default constructor" << std::endl; }
	Foo(Foo&& foo) : mValue{std::move(foo.mValue)} { std::cout << "Move constructor" << std::endl; }
	Foo(const Foo& foo) : mValue{foo.mValue} { std::cout << "Copy constructor" << std::endl; }

	int GetValue() const { return mValue; }

private:
	int mValue;
};

int main(int argc, char* argv[])
{
	std::unordered_set<int> set;
	std::cout << "Inserting 42" << std::endl;
	set.insert(42);

	std::cout << "Inserting 42 again" << std::endl;
	set.insert(42);
	/*std::cout << "Hello world" <<  std::endl;
	Foo foo{42};

	std::cout << "Foo(42)" << std::endl;
	Foo foo1(42);

	std::cout << "(Copy) foo2 = foo" << std::endl;
	Foo foo2 = foo;
	
	std::cout << "(Copy) foo3{foo}" << std::endl;
	Foo foo3{foo};

	std::cout << "foo4{std::move(foo)}" << std::endl;
	Foo foo4{std::move(foo)};

	std::cout << "std::optional<std::reference_wrapper<Foo>>" << std::endl;
	std::optional<std::reference_wrapper<Foo>> foo5 = std::ref(foo);
	
	if (foo5)
	{
		std::cout << foo5.value().get().GetValue() << std::endl;
	}
	else
	{
		std::cout << "No value" << std::endl;
	}*/

	return 0;
}
