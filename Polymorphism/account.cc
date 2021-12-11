#include "account.h"

Account::Account(std::string name, double balance) : name{name}, balance{balance} {}

bool Account::deposit(double amount)
{
    if (amount < 0) return false;

    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if (amount < 0) return false;

    if (balance-amount < 0) return false;

    balance -= amount;
    return true;
}

void Account::print(std::ostream& os) const
{
    os << "Account display";
}

double Account::get_balance() const { return balance; }