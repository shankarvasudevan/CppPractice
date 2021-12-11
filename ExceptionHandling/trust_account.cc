#include "trust_account.h"

TrustAccount::TrustAccount(std::string name, double balance, double int_rate) : SavingsAccount{name, balance, int_rate} { }

bool TrustAccount::deposit(double amount) 
{
    if (balance >= 5000) return SavingsAccount::deposit(amount + def_bonus_deposit);
    return SavingsAccount::deposit(amount);
}

bool TrustAccount::withdraw(double amount)
{
    return false;
}

void TrustAccount::print(std::ostream& os) const
{
    os << "Trust Account display";
}
