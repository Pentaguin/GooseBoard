#ifndef BOARD_HPP
#define BOARD_HPP

#include "player.hpp"
#include <vector>

class Board {
private:
    const short minDiceValue = 1;
    const short maxDiceValue = 6;
    short numberOfPlayers;
    std::vector<Player> players;

public:
    void setup();
    void setNumberOfPlayers(short);
    short getNumberOfPlayers();
    void rollDice();
    void printPlayerPosition();
    void printBoardRules();
};

#endif