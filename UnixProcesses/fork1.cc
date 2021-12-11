#include <unistd.h>
#include <iostream>

int main(void)
{
    if (fork() != 0) 
    {
        std::cout << "Hello" << std::endl;
    }
    else
    {
        std::cout << "World" << std::endl;
    }
}
