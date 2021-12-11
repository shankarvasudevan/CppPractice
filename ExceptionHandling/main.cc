#include <iostream>
#include "account.h"
#include "savings_account.h"
#include "checking_account.h"
#include "trust_account.h"
#include "iprintable.h"

int main(int argc, char* argv[])
{
    // Dynamic polymorphism
    Account* s1 = new SavingsAccount("S1", 5000, 10);
    s1->deposit(100);
    std::cout << *s1 << std::endl;

    Account* c1 = new CheckingAccount("C1", 50);
    c1->withdraw(100);
    std::cout << *c1 << std::endl;

    Account* t1 = new TrustAccount("T1", 4000, 10);
    t1->deposit(50);
    std::cout << *t1 << std::endl;
    t1->withdraw(45);
    std::cout << *t1 << std::endl;
    t1->withdraw(10);
    std::cout << *t1 << std::endl;
}