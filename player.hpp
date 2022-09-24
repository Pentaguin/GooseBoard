#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player {
private:
    std::string name;
    short position = 0;
    short turnsLeftInJail = 0;

public:
    void SetName(std::string);
    void SetPosition(short);
    void SetTurnsLeftInJail(short);
    std::string GetName();
    short GetPosition();
    short GetTurnsLeftInJail();
};

#endif
