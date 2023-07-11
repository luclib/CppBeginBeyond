#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include <string>
#include "Account.h"

class Checking_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);
protected:
    const double withdraw_fee = 1.50;
public:
    Checking_Account(std::string name = "Unnamed", double balance = 0.0);
    bool withdraw(double amount);
};

#endif 