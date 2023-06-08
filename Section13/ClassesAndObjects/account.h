#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account
{
private:
    std::string name{"Account"};
    double balance{0.0};

public:
    void set_name(std::string);
    std::string get_name();
    void set_balance(double);
    double get_balance();
    bool deposit(double);
    bool withdraw(double);
};

#endif // _ACCOUNT_H_