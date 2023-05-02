#include <iostream>
#include "player.h"

void Player::set_name(std::string new_name){
    name = new_name;
}
std::string Player::get_name(){
    return name;
}
void Player::set_health(int amount){
    health = amount;
}
void Player::set_xp(int amount){
    xp = amount;
}

Player::Player(std::string name_val, int health_val, int xp_val)
    : name {name_val}, health {health_val}, xp {xp_val}
    { }

Player::~Player(){}