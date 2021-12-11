#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int *ptr = (int *)malloc(sizeof(int));
    *ptr = 42;

    std::cout << "Value = " << *ptr << std::endl;

    delete ptr;

    if (!ptr)
    {
        std::cout << "Now it is nullptr" << std::endl;
    }
    else
    {
        std::cout << "Not nullptr" << std::endl;
    }

	return 0;
}
