#include <iostream>
#include <string>
#include <vector>
#include "account.h"

class Player{
private: // attributes (members)
    std::string name {"Player"};
    int health {100};
    int xp {3}; //experience
public: // method prototypes (declarations)
    void talk(std::string);
    bool is_dead();
};

int main() {
    // Player kratos;
    // Player zeus;

    // Player players[] {kratos, zeus};
    // std::vector<Player> player_vec {kratos};
    // player_vec.push_back(zeus);


    // Player *enemy {nullptr};
    // enemy = new Player;

    // delete enemy;

    Account luke_account;
    luke_account.set_name("Lucas' account");
    luke_account.set_balance(1000.0);

    if(luke_account.deposit(200.0))
        std::cout << "Deposit successful" << std::endl;
    else
        std::cout << "Deposit not allowed" << std::endl;

    if(luke_account.withdraw(500.0))
        std::cout << "Withdrawal OK" << std::endl;
    else
        std::cout << "Withdrawal rejected, insufficient balance" << std::endl;
    if(luke_account.withdraw(1500.0))
        std::cout << "Withdrawal OK" << std::endl;
    else
        std::cout << "Withdrawal rejected, insufficient balance" << std::endl;
    return 0;
}

// void Account::set_name(std::string name_val){
//     name = name_val;
// }
// std::string Account::get_name(){
//     return name;
// }
// void Account::set_balance(double amount){
//     balance = amount;
// }
// double Account::get_balance(){
//     return balance;
// }
// bool Account::deposit(double amount){
//     balance += amount;
//     return true;
// }
// bool Account::withdraw(double amount){
//     if(balance - amount >= 0){
//         balance -= amount;
//         return true;
//     }
//     else {
//         return false;
//     }
// }
