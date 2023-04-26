#include "move.h"

int Move::get_data_value(){
    return 0;
}
void Move::set_data_value(int d){
    *data = d;
}
Move::Move(int d){
    data = new int;
    *data = d;
}
Move::Move(const Move &source)
    : data{source.data} {}
Move::~Move(){
    delete data;
}