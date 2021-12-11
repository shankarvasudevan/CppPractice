#pragma once
#include "account.h"

class CheckingAccount : public Account
{
public:
    CheckingAccount(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream& os) const override;

private:
    static constexpr const char* def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_withdrawal_fee = 1.50;
};