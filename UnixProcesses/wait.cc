#include <unistd.h>
#include <iostream>
#include <sys/wait.h>

int main(void)
{
    if (fork() != 0)
    {
        std::cout << "parent" << std::endl;
        wait(nullptr); // Tells the parent process to wait for the child to complete its execution
    }
    else
    {
        std::cout << "child" << std::endl;
    }
}
