#include "board.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void Board::setup() {
    cout << "Enter number of players:  ";
    short numberOfPlayers;
    cin >> numberOfPlayers;
    cin.ignore(256, '\n');  // Get rid of the endline
    Board::setNumberOfPlayers(numberOfPlayers);

    // Save the name of all the players.
    for (int i = 0; i < numberOfPlayers; i++) {
        Player player;
        string playerName;
        cout << "Enter name of player " << i + 1 << "\t";
        getline(cin, playerName);
        player.SetName(playerName);
        Board::players.push_back(player);
        cout << "Welcome player "<< Board::players[i].GetName() << endl;
        Sleep(1000);
    }
};

void Board::setNumberOfPlayers(short numberOfPlayers) {
    Board::numberOfPlayers = numberOfPlayers;
}

short Board::getNumberOfPlayers() {
    return Board::numberOfPlayers;
}

void Board::printBoardRules() {
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "RULES" << endl;
    cout << "To win the game, a player has to land on space number 63." << endl;
    cout << "If a player throws too many, the piece counts the extra points backwards from the winning space." << endl;
    cout << endl;
    cout << "If a placer lands on the following spaces, the player has to follow the stated rule:" << endl;
    cout << "6 or 12 - The Bridge - Advance or go back to the other bridge." << endl;
    cout << "19 - Inn - Stay for 2 turn." << endl;
    cout << "31 - Well - Wait until someone comes to pull you out or wait 4 turns." << endl;
    cout << "42 - The Maze - Go back to space 30" << endl;
    cout << "56 - Jail - Wait 3 turns." << endl;
    cout << "58 - Death - You start at 1 again." << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    Sleep(2000);
}