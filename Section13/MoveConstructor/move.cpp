#include <iostream>
#include "move.h"

int Move::get_data_value(){
    return *data;
}
void Move::set_data_value(int d){
    *data = d;
}
Move::Move(int d){
    data = new int;
    *data = d;
    std::cout << "Constructor for: " << data
        << std::endl;
}
Move::Move(const Move &source)
    : data{source.data} {
    std::cout << "Copy constructor - deep"
        << std::endl;
}
Move::Move(Move &&source) noexcept
    :data {source.data}{
        source.data = nullptr;
        std::cout << "Move constructor -moving resource: " << std::endl;
}
Move::~Move(){
    if(data != nullptr) {
        std::cout << "Destructor freeing data for: " << std::endl; 
    }
    else {
        std::cout << "Destructor freeing data for nullptr" << std::endl;
    }
    delete data;
}