#include <iostream>

class Foo
{
public:
    Foo(int size)
    {
        std::cout << "Constructor" << std::endl;
        mSize = size;
        mValues = new int[size];
    }

    Foo(const Foo& other)
    {
        std::cout << "Copy constructor" << std::endl;
        mSize = other.mSize;
        mValues = new int[mSize];
    }

    Foo(Foo&& other)
    {
        std::cout << "Move constructor" << std::endl;
        mValues = other.mValues;
        other.mValues = nullptr;
    }

    void PrintAddress()
    {
        std::cout << "mValues=" << mValues << std::endl;
    }

    ~Foo()
    {
        std::cout << "Destructor" << std::endl;
        delete [] mValues;
    }

    int mSize{0};
    int* mValues{nullptr};
};

int main(int argc, char* argv[])
{
    Foo f1{3};
    f1.PrintAddress();

    Foo f2{std::move(f1)};
    f2.PrintAddress();
}