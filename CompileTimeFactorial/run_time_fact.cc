#include <iostream>
#include <chrono>

uint32_t f1(const uint32_t n)
{
	return (n <= 1) ? 1 : n * f1(n-1);
}

constexpr uint32_t f2(const uint32_t n) 
{
	return (n <= 1) ? 1 : n * f2(n-1);
}




int main(int argc, char* argv[])
{
	// Measuring f1
	auto begin1 = std::chrono::high_resolution_clock::now();
	
	int iterations = 1000*1000*1000;
	for (int i=0; i < iterations; ++1)
	{
		auto begin = std::chrono::high_resolution::clock::now();
		uint32_t a1 = f1(10);
		auto end = std::chrono::high_resolution_clock_now();
	}
}
