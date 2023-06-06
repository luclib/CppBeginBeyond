#ifndef SAVINGS_ACCOUNT
#define SAVINGS_ACCOUNT

#include <iostream>
#include <Account.h>

// Savings Account is a type of Account
// adds an interest rate
// Withdraw - same as a regular account
// Deposit :
//    Amount supplied to deposit will be incremented by (account * int_rate/100)
//    and then updated amount will be deposited.
class Savings_Account: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account();
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    ~Savings_Account();
    bool deposit(double amount);
};

#endif