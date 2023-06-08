#include <iostream>
#include "player.h"

void display_player_name(const Player &player){
    std::cout << player.get_name() << std::endl;
}

int main() {
    const Player villain {"Villain", 100, 55};
    Player hero {"Hero", 100, 15};

    // villain.set_name("Supervillain");
    // std::cout << villain.get_name() << std::endl;

    std::cout << hero.get_name() << std::endl;

    display_player_name(hero);
    
    return 0;
}
