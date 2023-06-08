#include <iostream>
#include "player.h"

// Number of players initialization.
int Player::num_players = 0;

int Player::get_num_players(){
    return num_players;
}

void Player::set_name(std::string name){
    this->name = name;
}
std::string Player::get_name() const{
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
    { 
        ++num_players;
    }

Player::~Player(){
    --num_players;
}