#include "checking_account.h"

CheckingAccount::CheckingAccount(std::string name, double balance) : Account{name, balance} { }

bool CheckingAccount::withdraw(double amount)
{
    return Account::withdraw(amount + def_withdrawal_fee);
}

std::ostream& operator<<(std::ostream& os, const CheckingAccount& account)
{
    os << "[CheckngAccount: " << account.name << ":" << account.balance << ":" << account.def_withdrawal_fee << "]";
    return os;
}