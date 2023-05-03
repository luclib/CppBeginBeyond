#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player{
private:
    static int num_players;
    std::string name;
    int health;
    int xp;
public: 
    static int get_num_players();
    void set_name(std::string);
    std::string get_name() const;
    void set_health(int);
    void set_xp(int);

    Player(std::string = "None", int = 0, int = 0);
    ~Player();  // Deconstructor
};
#endif