#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string.h>
#include "Player.h"
#include "Move.h"

class Computer: public Player
{
    //only plays Rock
    public:
        Computer();
        Computer(std::string name);
        Move* makeMove() override;

};
#endif