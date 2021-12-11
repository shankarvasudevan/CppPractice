#include "trust_account.h"

TrustAccount::TrustAccount(std::string name, double balance, double int_rate) : SavingsAccount{name, balance, int_rate} { }

bool TrustAccount::deposit(double amount) 
{
    if (balance >= 5000) return SavingsAccount::deposit(amount + def_bonus_deposit);
    return SavingsAccount::deposit(amount);
}

std::ostream& operator<<(std::ostream& os, const TrustAccount& account)
{
    os << "[TrustAccount: " << account.name << ":" << account.balance << ":" << account.int_rate << account.def_bonus_deposit << "]";
    return os;
}