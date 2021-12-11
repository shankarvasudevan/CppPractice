#pragma once

#include <iostream>
#include <string>
#include "iprintable.h"

class Account : public IPrintable
{
public:
    Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(std::ostream& os) const override;
    double get_balance() const; 

protected:
    std::string name;
    double balance;
    
private:
    static constexpr const char* def_name = "Unnamed account";
    static constexpr double def_balance = 0.0;


};