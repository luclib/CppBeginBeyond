#include <iostream>
#include <Account.h>
#include <Savings_Account.h>

class Base {
    // Note: friends of Base have access to all
public:
    int a {0};
    void display() { std::cout << a << "," << b << ", " << c << std::endl;}  //member method has access to all
protected:
    int b {0};
private:
    int c {0};

};

class Derived: public Base {
    // Note: friends of Derived have access to only what Derived has access to
public:
    void access_base_members(){
        a = 100;    // OK -> public in base, public in derived
        b = 200;    // OK -> protected in base, protected in derived
        c = 300;    // Error: not accessible.
    }
};

int main() {
    std::cout << "===Base member access from base objects ============" << std::endl;
    Base base;
    base.a = 100;   // OK
    base.b = 200;   // Error: b is a protected attribute --> inaccessible
    base.c = 300;   // Error: c is a private attribute --> inacessible

    Derived derived;
    derived.a = 100;   // OK 
    derived.b = 200;   // Error: b is protected
    derived.c = 400;   // Error: c is private

    return 0;
}