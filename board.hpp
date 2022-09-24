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
    bool endGame;

public:
    void setup();
    void setNumberOfPlayers(short);
    short getNumberOfPlayers();
    short getRolledDiceValue();
    void printPlayerPosition();
    void printBoardRules();
    void play();
    void setEndGame(bool);
    bool getEndGame();
};

#endif