#include <iostream>
#include "Computer.h"

Computer:: Computer():Player()
{
    //if I do not put Player(), will the Player object be created when Computer is created
    move='R';
    name="Computer";
}

char Computer::makeMove()
{
    return move;
}

std::string Computer::getName()
{
    return name;
}
