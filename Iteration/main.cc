#include <iostream>

class Foo
{
public:
	int NextValue()
	{
		return mValue++;
	}

	int Value() const
	{
		return mValue-1;
	}
	

private:
	int mValue = 0;

};


int main(int argc, char* argv[])
{

	Foo f;
	
	std::cout << f.NextValue() << std::endl;

	std::cout << f.Value() << std::endl;

	std::cout << f.NextValue() << std::endl;

	std::cout << f.Value() << std::endl;
	
	return 0;
}
