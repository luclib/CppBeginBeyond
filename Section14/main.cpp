#include <iostream>
#include "../include/Mystring.h"

int main() {
    Mystring empty;
    Mystring kratos("Kratos");
    Mystring stooge{"Kratos"};

    empty.display();
    kratos.display();
    stooge.display();
}