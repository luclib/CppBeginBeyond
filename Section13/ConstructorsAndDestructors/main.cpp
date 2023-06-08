#include <iostream>
#include <string>
#include <vector>
#include "player.h"

int main() {
    {
        Player slayer;
        slayer.set_name("Slayer");
    }
    {
        Player kratos;
        kratos.set_name("Kratos");
        Player zeus;
        zeus.set_name("Zeus");
        Player pandora;
        pandora.set_name("Pandora");
    }

    Player *enemy = new Player;
    enemy->set_name("Ares");

    Player *level_boss = new Player("Haides", 1000.0, 300.0);
    level_boss->set_name("Pluto");

    delete enemy;
    delete level_boss;

    return 0;
}