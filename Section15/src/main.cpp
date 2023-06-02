#include <iostream>
#include <Account.h>
#include <Savings_Account.h>

class Base {
private:
    int value;
public:
    Base(): value{0} {std::cout << "Base no-args constructor" << std::endl; }
    Base(int x): value {x} { std::cout << "Base (int) overloaded constructor" << std::endl;}
    Base(const Base &other)
        :value{other.value} {
            std::cout << "Base copy constructor" << std::endl; }
    Base &operator=(const Base &rhs){
        std::cout << "Base operator=" << std::endl;
        if(this != &rhs) {
            value = rhs.value;
        }
        return *this;
    }
    ~Base() { std::cout << "Base destructor" << std::endl; }

    int display_value(){ return value; }
    int* get_address() { return &value;}
};

class Derived: public Base {
private:
    int double_value;
public:
    Derived()
        : Base{}, double_value{0} { std::cout << "Derived no-args constructor " << std::endl; }
    Derived(int x)
        :Base{x}, double_value{x * 2} { std::cout << "Derived (int) overloaded constructor" << std::endl;}
    Derived(const Derived &other)
        :Base(other), double_value {other.double_value}{
            std::cout << "Derived copy constructor" << std::endl;
    }
    Derived &operator=(const Derived &rhs){
        if(this != &rhs){
            Base::operator=(rhs);                   // Assign Base part
            this->double_value = rhs.double_value;  // Assign Derived part
            std::cout << "Derived operator=" << std::endl;

        }
        return *this;
    }
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main() {
    // Base b {100};       // Overloaded constructor
    // std::cout << "Address of b: " << b.get_address() << std::endl;
    // std::cout << "Value of b: " << b.display_value() << std::endl;
    // Base b1 {b};        // Copy constructor
    // std::cout << "Address of b1: " << b1.get_address() << std::endl;
    // std::cout << "Value of b1: " << b1.display_value() << std::endl;
    // b = b1;             // Copy assignment

    Derived d {100};    // Overloaded constructor
    Derived d1 {d};     // Copy constructor
    d = d1;             // Copy assignment

    return 0;
}