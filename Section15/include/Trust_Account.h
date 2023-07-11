#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include <string>
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
protected:
    const int max_withdraw {3};
    const double bonus {50.00};
    int withdraw_count {0};
public:
    Trust_Account(std::string name = "Unnamed", double balance = 0.0, double int_rate = 0.0);
    bool deposit(double amount);
};

#endif