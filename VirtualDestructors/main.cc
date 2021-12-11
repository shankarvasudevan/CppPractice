#include <iostream>

class IFoo
{
public:
	virtual	~IFoo() { std::cout << "IFoo destroyed" << std::endl; }
};

class IBar : public IFoo
{
public:
	virtual ~IBar() { std::cout << "IBar destroyed" << std::endl; }
};

class Bar : public IBar
{
public:
	Bar() { std::cout << "Bar constructed" << std::endl; }
	~Bar() { std::cout << "Bar destroyed" << std::endl; }
};


int main(int argc, char* argv[])
{

	std::cout << "Scenario 1: Creating a Bar" << std::endl;
	Bar* b1 = new Bar();
	delete b1;

	std::cout << "Scenario 2: Creating an IBar" << std::endl;
	IBar* b2 = new Bar();
	delete b2;

	std::cout << "Scenario 3: Creating an IFoo" << std::endl;
	IFoo* b3 = new Bar();
	delete b3;

	return 0;
}
