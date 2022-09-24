#include <iostream>
#include <time.h>
#include <cstdlib>
#include "board.hpp"

int main() {
    // Use current time as seed to get random numbers
    srand(time(0));

    std::cout << "Welcome to Goose Board" << std::endl << std::endl;
    Board board;
    board.setup();
    board.printBoardRules();
    //play

    return 0;
}

