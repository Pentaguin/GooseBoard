#include <iostream>
#include <time.h>
#include <cstdlib>
#include "board.hpp"

int main() {
    std::cout << "Welcome to Goose Board" << std::endl << std::endl;
    Board board;
    board.setup();
    board.printBoardRules();
    board.play();
    return 0;
}

