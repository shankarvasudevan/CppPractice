#include <unistd.h>
#include <iostream>

int main(void)
{
	if (fork() != 0) 
	{
		// Parent process receives the PID of the Child process
		std::cout << "Hello" << std::endl;
	}
	else
	{
		// Child process receives 0
		std::cout << "World" << std::endl;
	}
}
