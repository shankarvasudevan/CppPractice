#include <iostream>

struct A
{
    int Foo(int x) { return x*x; }
};

int main(int argc, char* argv[])
{
    A* a = nullptr;
    int result = a->Foo(10);

    std::cout << result << std::endl;

    std::cout << "finished" << std::endl;
    return 0;
}