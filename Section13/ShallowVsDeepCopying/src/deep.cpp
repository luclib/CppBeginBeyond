#include <iostream>
#include "include/deep.h"

int Deep::get_data_value(){
    return *data;
}
void Deep::set_data_value(int d){
    *data = d;
}

Deep::Deep(int d){
    data = new int;
    *data = d;
}
// // Deep constructor - longhand
// Deep::Deep(const Deep &source){
//     data = new int;
//     *data = *source.data;  
//     std::cout << "Copy constructor - deep"
//         << std::endl;
// }

// Deep constructor - shorthand
Deep::Deep(const Deep &source)
  : Deep{*source.data}{
    std::cout <<  "Copy constructor - deep" 
        << std::endl;
}
Deep::~Deep(){ 
    delete data;
    std::cout << "Destructor freeing data"
        << std::endl;
}
