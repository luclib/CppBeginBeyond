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

// Using constructor parameters with default values
Player::Player(std::string name_val, int health_val, int xp_val)
    : name {name_val}, health {health_val}, xp {xp_val}
    { }

// Delegating constructors
// Player::Player(std::string name_val, int health_val, int xp_val)
//     : name {name_val}, health {health_val}, xp {xp_val}{
// }

// Player::Player(): Player{"None", 0, 0 }{ }

// Player::Player(std::string name_val): Player {name_val, 0, 0} { }


Player::~Player(){}