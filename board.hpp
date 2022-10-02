#ifndef BOARD_HPP
#define BOARD_HPP

#include "player.hpp"
#include <vector>

class Board {
private:
    const short minDiceValue = 1;
    const short maxDiceValue = 6;
    const short gooseBoardLastSpace = 63;
    short numberOfPlayers;
    std::vector<Player> players;
    bool endGame;

    void setNumberOfPlayers(short);
    short getNumberOfPlayers();
    short getRolledDiceValue();
    void printPlayerPosition();
    void setEndGame(bool);
    bool getEndGame();
    void boardRulesImplementation(short, short);

public:
    void setup();
    void printBoardRules();
    void play();
};

#endif