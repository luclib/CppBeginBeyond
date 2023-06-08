#include <iostream>
#include "player.h"

void display_active_players() {
    std::cout << "Active players: "
        << Player::get_num_players()
        << std::endl;
}

int main() {

    return 0;
}