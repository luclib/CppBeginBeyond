#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player{
private: // attributes (members)
    std::string name {"Player"};
    int health {100};
    int xp {3}; //experience
public: // method prototypes (declarations)
    void set_name(std::string);
    std::string get_name();
    void set_health(int);
    void set_xp(int);
    
    void talk(std::string);
    bool is_dead();

    // With constructor parameters with default values
    Player(std::string = "None", int = 0, int = 0);

    // Overloading constructors
    // Player();
    // Player(std::string);
    // Player(std::string, int, int);

    ~Player();  // Deconstructor
};
#endif