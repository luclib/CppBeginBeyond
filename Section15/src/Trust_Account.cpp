#include<string>
#include<iostream>
#include "Trust_Account.h"

std::ostream &operator<<(std::ostream &os, const Trust_Account &account){
    os << "[Trust Account: " << account.name << " : " << account.balance
       << ", " << account.int_rate << "%]";
    return os;
}


Trust_Account::Trust_Account(std::string name, double balance, double int_rate):
    Savings_Account(name, balance, int_rate){}

bool Trust_Account::deposit(double amount){
    if(this->withdraw_count == this->max_withdraw)
        std::cout << "Sorry, but you have already reached the maximum withdrawl amount of 3 per year.\n";
    else{
        if(amount >= 5000.0){
            amount += this->bonus;
        }
        amount += amount  * (this->int_rate/100);
        ++this->withdraw_count;
        return Account::deposit(amount);
    }
    return 0;
}