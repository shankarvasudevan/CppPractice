#include <iostream>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
	uint32_t x = 20908;
	
	uint32_t y = htonl(x);

	std::cout << "x=" << x << std::endl;
	std::cout << "y=" << y << std::endl;

	return 0;
}
