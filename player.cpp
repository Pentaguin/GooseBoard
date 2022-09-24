#include "player.hpp"

std::string Player::GetName() { return name; }
void Player::SetName(std::string name) { Player::name = name; }
short Player::GetPosition() { return position; }
void Player::SetPosition(short pos) { position = pos; }
    