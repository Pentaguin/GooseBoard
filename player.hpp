#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player {
private:
    std::string name;
    int position = 0;
    int turnsLeftInJail = 0;

public:
    void setName(std::string);
    void setPosition(int);
    void setTurnsLeftInJail(int);
    std::string getName();
    int getPosition();
    int getTurnsLeftInJail();
};

#endif
