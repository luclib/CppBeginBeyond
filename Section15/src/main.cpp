#include <iostream>
#include <Account.h>
#include <Savings_Account.h>

class Base {
private:
    int value;
public:
    Base(): value{0} {std::cout << "Base no-args constructor" << std::endl; }
    Base(int x): value {x} { std::cout << "Base (int) overloaded constructor" << std::endl;}
    ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived: public Base {
    using Base::Base;
private:
    int double_value;
public:
    Derived(): double_value{0} { std::cout << "Derived constructor " << std::endl; }
    Derived(int x): double_value{x * 2} { std::cout << "Derive (int) overloaded constructor" << std::endl;}
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main() {
    // Base b;
    // Base b {100};
    // Derived d;
    Derived d {40};
    return 0;
}