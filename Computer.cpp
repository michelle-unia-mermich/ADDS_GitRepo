#include <iostream>
#include "Computer.h"

Computer:: Computer():Player()
{
    //currentMove= nullptr; //already set in Player()
    //to make it consistent with constructor of Human
    //only initialise move when use the function makeMove
    name="Computer";
}

Computer::Computer(std::string name)
{
    //give computer a name
    this->name =name;
}

Move* Computer::makeMove()
{
    return (new Rock());
}
