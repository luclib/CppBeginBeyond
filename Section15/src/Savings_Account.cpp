#include <iostream>
#include <Savings_Account.h>

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account(name, balance), int_rate{int_rate} { }

Savings_Account::~Savings_Account(){}

bool Savings_Account::deposit(double amount){
    amount += amount  * (this->int_rate/100);
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Savings_Account &account){
    os << "[Savings_Account: " << account.name << ": " << account.balance
        << ", " << account.int_rate << "%]";
    return os;
}