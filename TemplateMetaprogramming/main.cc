#include <iostream>

template<uint32_t n>
struct fact 
{
    const static uint32_t value = n * fact<n-1>::value;
};

// fully specialised template for n as 0
template <>
struct fact<0> 
{
    const static uint32_t value = 1;
};

int main() 
{
    std::cout << "fact<0>=" << fact<0>::value << std::endl;
    std::cout << "fact<10>=" << fact<10>::value << std::endl;

    const uint32_t m=5;
    std::cout << "fact<m>=" << fact<m>::value << std::endl;
}