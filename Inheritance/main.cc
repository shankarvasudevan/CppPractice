#include <iostream>
#include "account.h"
#include "savings_account.h"
#include "checking_account.h"
#include "trust_account.h"

class Base
{
public:
    Base() : mValue{0} { std::cout << "Base: No args constructor" << std::endl; }
    Base(int value) : mValue{value} { std::cout << "Base: Regular constructor" << std::endl; }
    ~Base() { std::cout << "Base: Destructor" << std::endl; }

private: 
    int mValue;
};

class Derived : public Base 
{
public:
    Derived() : mDoubleValue{0} { std::cout << "Derived: No args constructor" << std::endl; }
    Derived(int value) : Base(value), mDoubleValue(value*2) { std::cout << "Derived: Regular constructor" << std::endl; }
    ~Derived() { std::cout << "Derived: Destructor" << std::endl; }

private:
    int mDoubleValue;
};




int main(int argc, char* argv[])
{
    Account a1;
    a1.deposit(100);
    std::cout << a1 << std::endl;

    SavingsAccount s1{"S1", 5000, 10};
    s1.deposit(100);
    std::cout << s1 << std::endl;

    CheckingAccount c1{"C1", 1000};
    c1.withdraw(100);
    std::cout << c1 << std::endl;

    TrustAccount t1{"T1", 4000, 10};
    t1.deposit(50);
    std::cout << t1 << std::endl;
    t1.deposit(1000);
    std::cout << t1 << std::endl;
    t1.deposit(1000);
    std::cout << t1 << std::endl;
}