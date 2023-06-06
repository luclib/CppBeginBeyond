#include <iostream>
#include <Account.h>

Account::Account(std::string name, double balance)
    :name{name}, balance{balance}{ }

Account::~Account(){}

bool Account::deposit(double amount){
    if(amount < 0)
        return false;
    else {
        this->balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount){
    if(this->balance - amount >= 0){
        this->balance -= amount;
        return true;
    } else
        return false;
}

std::ostream &operator<<(std::ostream &out, const Account &account){
    out << "Account balance: " << account.balance;
}
