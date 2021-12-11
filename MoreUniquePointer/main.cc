#include <iostream>
#include <memory>

class Foo
{
public:
    void PrintPtr(std::string* s)
    {
        if (s == nullptr) std::cout << "S is a nullptr" << std::endl;

        std::cout << "S is " << *s << std::endl;
    }
};

int main(int argc, char* argv[])
{
    std::unique_ptr<std::string> sPtr;

    std::string* sCopy = sPtr.get();

    sPtr = std::make_unique<std::string>("Some value");

    
}