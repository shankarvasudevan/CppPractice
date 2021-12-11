#include <iostream>
#include <functional>
#include <thread>
#include <chrono>

class Foo
{
public:
    explicit Foo(int value) : mValue(value) { std::cout << "Constructing Foo: " << this << std::endl; }
    ~Foo() { std::cout << "Destroying Foo: " << this << std::endl;}

    int GetValue() { return mValue; }

private:
    int mValue;
};

class Bar
{
public:
    explicit Bar(Foo& foo) : mFoo(foo) { std::cout << "Constructing Bar" << std::endl; }

    void Call() 
    { 
        if (mOnFoo) 
        { 
            std::cout << "Executing callback" << std::endl;
            mOnFoo(mFoo); 
        } 
    }

    ~Bar() { std::cout << "Destroying Bar: " << std::endl; }

    std::function<void(Foo&)> mOnFoo = nullptr;

private:
    Foo& mFoo;
};

int main(int argc, char* argv[])
{
    Foo* fooPtr = nullptr;
    auto fooCallback = [&](Foo& foo) 
    { 
        std::cout << "Received Foo: " << &foo << std::endl; 
        fooPtr = &foo;
    };

    {
        Foo foo(42);
        Bar bar(foo);
        bar.mOnFoo = fooCallback;
        bar.Call();
    }

    std::cout << "Address of fooPtr: " << fooPtr << std::endl;
    std::cout << "Dereferencing fooPtr: " << fooPtr->GetValue() << std::endl; // Undefined behaviour
    std::cout << "End of program" << std::endl;
}