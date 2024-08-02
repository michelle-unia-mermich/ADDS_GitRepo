#include <iostream>
#include "Computer.h"

Computer:: Computer():Player()
{
    move='R';
    name="Computer";
}

Move* Computer::makeMove()
{
    Move* result = new Move("Rock");
    return result;
}
