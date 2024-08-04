#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "Player.h"
#include "Move.h"
#include <string.h>

class Human: public Player
{
    public:
        Human();
        Human(std::string newName);
        Move* makeMove() override;

};
#endif