#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string.h>
#include "Player.h"

class Computer: public Player
{
    //only plays Rock
    public:
        Computer();
        char makeMove() override;
        std::string getName() override;

};
#endif