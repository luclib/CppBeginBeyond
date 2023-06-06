#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    // Class exclusive constants to provide default parameter values.
    static constexpr const char* def_name = "Unnamed ACcount";
    static constexpr double def_balance = 0.0;
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = def_name, double balance = def_balance);
    ~Account();
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};

#endif