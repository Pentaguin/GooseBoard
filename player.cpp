#include "player.hpp"

std::string Player::getName() { return name; }
void Player::setName(std::string name) { Player::name = name; }
int Player::getPosition() { return position; }
void Player::setPosition(int pos) { position = pos; }
void Player::setTurnsLeftInJail(int turns) {turnsLeftInJail = turns; }
int Player::getTurnsLeftInJail() { return turnsLeftInJail; }