#include "savings_account.h"

SavingsAccount::SavingsAccount(std::string name, double balance, double int_rate) 
    : Account{name, balance}, int_rate(int_rate) {}

bool SavingsAccount::deposit(double amount) 
{
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

bool SavingsAccount::withdraw(double amount)
{
    return false;
}

void SavingsAccount::print(std::ostream& os) const
{
    os << "Savings Account display";
}