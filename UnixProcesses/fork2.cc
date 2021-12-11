#include <unistd.h>
#include <iostream>

int data = 0;

int main(void)
{
    if (fork() != 0) 
    {
        data = 42;
    }
    
    std::cout << "The answer is: " << data << std::endl;
}
