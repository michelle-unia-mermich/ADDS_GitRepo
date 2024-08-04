#include "Player.h"
//the only purpose of Player.cpp is to define getName()
Player::Player()
{
    currentMove = nullptr;
    name = "";
}
Player::Player(std::string newName)
{
    currentMove = nullptr;
    this->name = newName; 
}
std::string Player::getName()
{
    return name;
}

void Player::setName(std::string newName)
{
    this->name = newName;
}

Move* Player::getCurrentMove()
{
    return currentMove; 
}


Player::~Player()
{
    delete currentMove;
}