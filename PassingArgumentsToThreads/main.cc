#include <iostream>
#include <thread>

struct Foo 
{
    int mValue;
};

void PrintGood(const Foo& foo)
{
    std::cout << foo.mValue << std::endl;
}

/*
the thread constructor copies the values passed to it and then passes them to the thread function with rvalue references. 
This is done to work with move-only types. 
So it will try to call the PrintBad function with rvalue, 
which will fail to compile (you can't pass rvalue to a function that expects a non-constant reference).
*/
void PrintBad(Foo& foo)
{
    std::cout << foo.mValue << std::endl;
}

int main(int argc, char* argv[])
{
    Foo f;
    f.mValue = 42;


    // std::thread t1{PrintGood, f};
    // t1.join();

    /* This fails to compile */
    std::thread t2{PrintBad, f};
    t2.join();

    std::cout << "Main thread terminating" << std::endl;
}