#include <iostream>
#include <Account.h>
#include <Savings_Account.h>

int main() {
    // std::cout << "\n======Account class=====================\n";
    // Account acct1 {1000.0};
    // std::cout << acct1 << std::endl;     // Account balance: 1000

    // acct1.deposit(500.0);
    // std::cout << acct1 << std::endl;    // Account balance: 1500

    // acct1.withdraw(1000.0);               // Account balance: 500
    // std::cout << acct1 << std::endl;

    // acct1.withdraw(5000.0);             // Insufficient funds
    // std::cout << acct1 << std::endl;    // Account balance: 500

    std::cout << "\n======Savings account class=====================\n";
    Savings_Account sav_acct {1000, 5.0};
    std::cout << sav_acct << std::endl;   // Savings Account balance: 50, Interest Rate: 5
    
    sav_acct.deposit(1000);               // Savings Account balance: 2050, Interest rate: 5
    std::cout << sav_acct << std::endl;

    sav_acct.withdraw(2000);               // Savings Account balance: 50, Interest Rate: 5
    std::cout << sav_acct << std::endl;

    sav_acct.withdraw(1000);               // Insufficient funds.
    std::cout << sav_acct << std::endl;


    return 0;
}