#include "player.hpp"

std::string Player::GetName() {
    return Player::name;
};

void Player::SetName(std::string name) {
    Player::name = name;
};