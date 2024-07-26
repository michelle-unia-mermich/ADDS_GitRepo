#include <iostream>
#include "Human.h"


Human:: Human():Player()
{
    name="Human";
}

Human::Human(std::string new_name):Player()
{
    name=new_name;
}

char Human::makeMove()
{
    std::cout<<"Enter move: ";
    char new_move;
    std::cin  >> new_move;
    std::cout<< std::endl;
    move = new_move;
    return move;
}

std::string Human::getName()
{
    return name;
}
