#include "board.hpp"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void Board::setup() {
    int numberOfPlayers;
    srand(time(0)); // Use current time as seed to get random numbers
    cout << "Enter number of players:  ";
    cin >> numberOfPlayers;
    cin.ignore(256, '\n');  // Get rid of the endline
    setNumberOfPlayers(numberOfPlayers);

    // Save the name of all the players.
    for (int i = 0; i < numberOfPlayers; i++) {
        Player player;
        string playerName;
        cout << "Enter name of player " << i + 1 << "\t";
        getline(cin, playerName);
        player.setName(playerName);
        players.push_back(player);
        cout << "Welcome player "<< players[i].getName() << endl;
        Sleep(1000);
    }
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
    cout << "31 - Well -  Wait 4 turns or wait until someone take your place." << endl;
    cout << "42 - The Maze - Go back to space 30" << endl;
    cout << "56 - Jail - Wait 3 turns." << endl;
    cout << "58 - Death - You start at 1 again." << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    Sleep(2000);
}

void Board::play() {
    while (getEndGame() != true) {
        for (int playerIndex = 0; playerIndex < getNumberOfPlayers(); playerIndex++) {
            cout << endl;
            cout << "Player " << players[playerIndex].getName() << " turn."<< endl;
            cout << "Enter [r] to read the rules again." << endl;
            cout << "Enter [x] to roll a dice." << endl;

            char keyBoardInput;
            cin >> keyBoardInput;
            cin.ignore(256, '\n');  // Get rid of the endline
            
            if (keyBoardInput == 'r') {
                printBoardRules();
                playerIndex--;
            } 
            else if (keyBoardInput == 'x') {
                int diceValue = getRolledDiceValue();
                cout << "Player " << players[playerIndex].getName() << " rolled " << diceValue << endl;
                Sleep(1000);
                boardRulesImplementation(playerIndex, diceValue);
                Sleep(1000);
            } 
            else {
                playerIndex--;
            }   
        }
        printPlayerPosition();
    }
}

void Board::boardRulesImplementation(int playerIndex, int diceValue) {

    // Algorithm for when the player cant move.
    if (players[playerIndex].getTurnsLeftInJail() > 1) {
        players[playerIndex].setTurnsLeftInJail(players[playerIndex].getTurnsLeftInJail() - 1);
        cout << "Player " << players[playerIndex].getName() << " still needs to stay in this space for " << players[playerIndex].getTurnsLeftInJail() << " turns." << endl;
        return;
    }
    else if (players[playerIndex].getTurnsLeftInJail() == 1) {
        players[playerIndex].setTurnsLeftInJail(0);
        cout << "Player " << players[playerIndex].getName() << " is free next turn." << endl;
        return;
    }

    // Algorithm for when the player surpass gooseBoardLastSpace
    if (players[playerIndex].getPosition() + diceValue > gooseBoardLastSpace) { 
        int temporaryPosition = players[playerIndex].getPosition() + diceValue;
        players[playerIndex].setPosition(gooseBoardLastSpace - (temporaryPosition - gooseBoardLastSpace));
    } 

    // Algorithm for the special spaces from GooseBoard
    if (players[playerIndex].getPosition() + diceValue == 6) { // Bridge
        cout << "Player " << players[playerIndex].getName() << " landed on [Bridge - space 6] and can move forward to space 12. " << endl;
        players[playerIndex].setPosition(12);
    } 
    else if (players[playerIndex].getPosition() + diceValue == 12) { // Bridge
        cout << "Player " << players[playerIndex].getName() << " landed on [Bridge - space 12] and has to walk back to space 6. " << endl;
        players[playerIndex].setPosition(6);
    } 
    else if (players[playerIndex].getPosition() + diceValue == 19) { // Inn
        cout << "Player " << players[playerIndex].getName() << " landed on [Inn- space 19] and is gonna stay for 2 turns. " << endl;
        players[playerIndex].setPosition(19);
        players[playerIndex].setTurnsLeftInJail(2);
    } 
    else if (players[playerIndex].getPosition() + diceValue == 31) { // Well
        bool playerWasInWell = false;

        // Itterate through every players and check if a player is on space 31 and is in jail.
        for (int i = 0; i < numberOfPlayers; i++) {
            if (players[i].getPosition() == 31 && players[i].getTurnsLeftInJail() > 0) {
                players[i].setTurnsLeftInJail(0);
                cout << "Player " << players[i].getName() << " was in the well. You freed the other player, but you accidently fell and took over his place. Wait 4 turns or wait until someone takes your place." << endl;
                playerWasInWell = true;
            }
        }

        players[playerIndex].setTurnsLeftInJail(4);
        players[playerIndex].setPosition(31);

        if (!playerWasInWell) {
            cout << "Player " << players[playerIndex].getName() << " landed on [Well - space 31]. Wait 4 turns or wait until someone takes your place " << endl;
        }
    } 
    else if (players[playerIndex].getPosition() + diceValue == 42) { // Maze
        cout << "Player " << players[playerIndex].getName() << " landed on [Maze - space 42], got lost and walked back to space 30. " << endl;
        players[playerIndex].setPosition(30);
    } 
    else if (players[playerIndex].getPosition() + diceValue == 56) { // Jail
        cout << "Player " << players[playerIndex].getName() << " landed on [Jail- space 56]. Wait 3 turns." << endl;
        players[playerIndex].setPosition(56);
        players[playerIndex].setTurnsLeftInJail(3);
    }
    else if (players[playerIndex].getPosition() + diceValue == 58) { // Death
        cout << "Player " << players[playerIndex].getName() << " landed on [Death- space 58]. Go back to space 1." << endl;
        players[playerIndex].setPosition(1);
    } 
    else if (players[playerIndex].getPosition() + diceValue == gooseBoardLastSpace) { // End game
        players[playerIndex].setPosition(63);
        cout << "Player " << players[playerIndex].getName() << " landed on 63." << endl << "Congratulations. You won the game." << endl;
        Sleep(1000);
        setEndGame(true);
        return;
    } 
    else {
        players[playerIndex].setPosition(players[playerIndex].getPosition() + diceValue);
    }

    cout << "Player " << players[playerIndex].getName() << " new position: " << players[playerIndex].getPosition() << endl;
}

void Board::printPlayerPosition() {
    cout << endl;
    cout << "POSITION:" << endl;
    for (int playerIndex = 0; playerIndex < getNumberOfPlayers(); playerIndex++) {
        cout << players[playerIndex].getName() << ": " << players[playerIndex].getPosition() << endl;
    }
}

int Board::getRolledDiceValue() {
    return rand() % (maxDiceValue - minDiceValue + 1) + minDiceValue;
}

int Board::getNumberOfPlayers() { return Board::numberOfPlayers; }
bool Board::getEndGame() { return Board::endGame; }
void Board::setNumberOfPlayers(int numberOfPlayers) { Board::numberOfPlayers = numberOfPlayers; }
void Board::setEndGame(bool endGame) { Board::endGame = endGame; }

