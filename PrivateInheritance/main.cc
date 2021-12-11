#include <iostream>

class IBase
{
public:
    virtual void SayHello() = 0;
    virtual ~IBase() = default;    
};

class PrivateConcrete : private IBase
{
public:
    virtual void SayHello() override { std::cout << "Hello PrivateConcrete"  << std::endl; }

};

int main(int agrc, char* argv[])
{
    PrivateConcrete pc;
    pc.SayHello();
}