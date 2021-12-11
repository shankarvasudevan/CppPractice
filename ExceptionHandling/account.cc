#include "account.h"
#include "illegal_balance_exception.h"
#include "insufficient_funds_exception.h"

Account::Account(std::string name, double balance) : name{name}, balance{balance} 
{
    if (balance < 0)
    {
        throw IllegalBalanceException{};
    }
}

bool Account::deposit(double amount)
{
    if (amount < 0) return false;

    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if (amount < 0) return false;

    if (balance-amount < 0) 
    {
        throw InsufficientFundsException{};
    }

    balance -= amount;
    return true;
}

void Account::print(std::ostream& os) const
{
    os << "Account display";
}

double Account::get_balance() const { return balance; }