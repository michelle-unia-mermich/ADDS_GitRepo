#include <iostream>
#include "Human.h"
#include "MoveFactory.h"

Human:: Human(): Player()
{
    name="Human";
    //if write this this, Human:: Human(): Player(), the constructor of Player() is called first, then the constructor of Human() is called second, overriding whatever in the constructor of Player
    //if we do not write Player(), just Human:: Human(), he said that the constructor of Player() is not invoked, but I thought it is. I will check again.
}

Human::Human(std::string newName):Player()
{
    name=newName;
}

Move* Human::makeMove()
{
    std::cout<<"Enter move: ";
    std::string newMove;
    std::cin  >> newMove;
    std::cout<< std::endl;
    Move* result = MoveFactory::getMove(newMove);
    return result;
}

