#include "checking_account.h"

CheckingAccount::CheckingAccount(std::string name, double balance) : Account{name, balance} { }

bool CheckingAccount::deposit(double amount)
{
    return false;
}

bool CheckingAccount::withdraw(double amount)
{
    return Account::withdraw(amount + def_withdrawal_fee);
}

void CheckingAccount::print(std::ostream& os) const
{
    os << "Checking Account display";
}