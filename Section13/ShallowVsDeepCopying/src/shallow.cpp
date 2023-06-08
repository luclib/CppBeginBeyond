#include <iostream>
#include "include/shallow.h"

void Shallow::set_data_value(int d) {
    *data = d;
}
int Shallow::get_data_value(){
    return *data;
}
Shallow::Shallow(int d){
    data = new int; // allocate storage
    *data = d;
}
Shallow::Shallow(const Shallow &source)
    : data {source.data} {
        std::cout << "Copy constructor - shallow" 
            << std::endl;
    }

Shallow::~Shallow(){
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
}