#ifndef BOARD_HPP
#define BOARD_HPP

#include "player.hpp"
#include <vector>

class Board {
private:
    const int minDiceValue = 1;
    const int maxDiceValue = 6;
    const int gooseBoardLastSpace = 63;
    int numberOfPlayers;
    std::vector<Player> players;
    bool endGame;

    void setNumberOfPlayers(int);
    int getNumberOfPlayers();
    int getRolledDiceValue();
    void printPlayerPosition();
    void setEndGame(bool);
    bool getEndGame();
    void boardRulesImplementation(int, int);

public:
    void setup();
    void printBoardRules();
    void play();
};

#endif