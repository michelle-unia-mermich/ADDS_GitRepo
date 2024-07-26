#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "Player.h"
#include <string.h>

class Human: public Player
{
    public:
        Human();
        Human(std::string new_name);
        char makeMove() override;
        std::string getName() override;

};
#endif