#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player {
private:
    std::string name;
    short position = 0;
    short turnsLeftInJail = 0;

public:
    void setName(std::string);
    void setPosition(short);
    void setTurnsLeftInJail(short);
    std::string getName();
    short getPosition();
    short getTurnsLeftInJail();
};

#endif
