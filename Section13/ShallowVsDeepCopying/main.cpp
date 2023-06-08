#include <iostream>
#include "deep.h"

void display_deep(Deep s)
{
    std::cout << s.get_data_value() << std::endl;
}

int main()
{
    Deep obj1{100};
    display_deep(obj1);

    Deep obj2{obj1};
    obj2.set_data_value(1000);
    display_deep(obj1);
    return 0;
}