#include "board.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void Board::setup() {
    // Use current time as seed to get random numbers
    srand(time(0));

    cout << "Enter number of players:  ";
    short numberOfPlayers;
    cin >> numberOfPlayers;
    cin.ignore(256, '\n');  // Get rid of the endline
    setNumberOfPlayers(numberOfPlayers);

    // Save the name of all the players.
    for (int i = 0; i < numberOfPlayers; i++) {
        Player player;
        string playerName;
        cout << "Enter name of player " << i + 1 << "\t";
        getline(cin, playerName);
        player.SetName(playerName);
        players.push_back(player);
        cout << "Welcome player "<< players[i].GetName() << endl;
        Sleep(1000);
    }
}

short Board::getNumberOfPlayers() { return Board::numberOfPlayers; }
bool Board::getEndGame() { return Board::endGame; }
void Board::setNumberOfPlayers(short numberOfPlayers) { Board::numberOfPlayers = numberOfPlayers; }
void Board::setEndGame(bool endGame) { Board::endGame = endGame; }
    
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

void Board::play() {
    while(getEndGame() != true) {
        for(short playerIndex = 0; playerIndex < getNumberOfPlayers(); playerIndex++) {
            cout << endl;
            cout << "Player " << players[playerIndex].GetName() << " turn."<< endl;
            cout << "Enter [r] to read the rules again." << endl;
            cout << "Enter [x] to roll a dice." << endl;

            char keyBoardInput;
            cin >> keyBoardInput;
            cin.ignore(256, '\n');  // Get rid of the endline
            
            if(keyBoardInput == 'r') {
                printBoardRules();
                playerIndex--;
            } else if (keyBoardInput == 'x') {
                short diceValue = getRolledDiceValue();
                cout << "Player " << players[playerIndex].GetName() << " rolled " << diceValue << endl;
                Sleep(1000);
                players[playerIndex].SetPosition(players[playerIndex].GetPosition() + diceValue);
                boardRulesImplementation(playerIndex);
                Sleep(1000);
            // else if (ADMIN MODE)
            } else {
                playerIndex--;
            }   
        }
        printPlayerPosition();
    }
}

short Board::getRolledDiceValue() {
    return rand() % (maxDiceValue - minDiceValue + 1) + minDiceValue;
}

void Board::printPlayerPosition() {
    cout << endl;
    cout << "POSITION:" << endl;
    for (short playerIndex = 0; playerIndex < getNumberOfPlayers(); playerIndex++) {
        cout << players[playerIndex].GetName() << ": " << players[playerIndex].GetPosition() << endl;
    }
}

void Board::boardRulesImplementation(short playerIndex) {
    // if 63 setEndGame(true);

    if(players[playerIndex].GetPosition() == 6) {
        cout << "Player " << players[playerIndex].GetName() << " landed on [Bridge - space 6] and can move forward to space 12. " << endl;
        players[playerIndex].SetPosition(12);
    } 
    else if(players[playerIndex].GetPosition() == 12) {
        cout << "Player " << players[playerIndex].GetName() << " landed on [Bridge - space 12] and has to walk back to space 6. " << endl;
        players[playerIndex].SetPosition(6);
    }
    
    // if 63 setEndGame(true);
    //else
    cout << "Player " << players[playerIndex].GetName() << " new position: " << players[playerIndex].GetPosition() << endl;
    

    
}
