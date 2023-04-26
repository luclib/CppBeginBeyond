#include "account.h"

void Account::set_name(std::string name_val){
    name = name_val;
}
std::string Account::get_name(){
    return name;
}
void Account::set_balance(double amount){
    balance = amount;
}
double Account::get_balance(){
    return balance;
}
bool Account::deposit(double amount){
    balance += amount;
    return true;
}
bool Account::withdraw(double amount){
    if(balance - amount >= 0){
        balance -= amount;
        return true;
    }
    else {
        return false;
    }
}
