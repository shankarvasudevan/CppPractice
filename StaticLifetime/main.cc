#include <iostream>

class Foo
{
public:
	Foo() { std::cout << "Creating foo" << std::endl; } // This will never get called for static execution
	static void Execute() {	std::cout << "Executing foo" << std::endl; }
	~Foo() { std::cout << "Destroying foo" << std::endl; } // This will never get called for static execution
};

class Bar
{
public:
	Bar() { std::cout << "Creating bar" << std::endl; }
	void Execute() 
	{
		std::cout << "Executing Bar" << std::endl;
		Foo::Execute();
	}

	~Bar() { std::cout << "Destroying bar" << std::endl; }
};

int main(int argc, char* argv[])
{
	Bar b1;
	b1.Execute();
	Bar b2;
	b2.Execute();
}
