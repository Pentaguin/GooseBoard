#include "player.hpp"

std::string Player::getName() { return name; }
void Player::setName(std::string name) { Player::name = name; }
short Player::getPosition() { return position; }
void Player::setPosition(short pos) { position = pos; }
    