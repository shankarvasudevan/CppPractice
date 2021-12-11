#include <functional>
#include <iostream>

int main(int argc, char* argv[])
{
    std::function<void(int)> printNum = [](int num) { std::cout << "Num = " << num << std::endl; };

    const int x = 42;
    printNum(x);
}