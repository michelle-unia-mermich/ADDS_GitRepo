#include <iostream>
#include "Human.h"


Human:: Human(): Player()
{
    name="Human";
    //if write this this, Human:: Human(): Player(), the constructor of Player() is called first, then the constructor of Human() is called second, overriding whatever in the constructor of Player
    //if we do not write Player(), just Human:: Human(), he said that the constructor of Player() is not invoked, but I thought it is. I will check again.
}

Human::Human(std::string new_name):Player()
{
    name=new_name;
}

Move* Human::makeMove()
{
    std::cout<<"Enter move: ";
    std::string new_move;
    std::cin  >> new_move;
    std::cout<< std::endl;
    Move* result = new Move(new_move);
    return result;
}

