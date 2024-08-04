#include "MoveFactory.h"

#include "Zombie.h"
#include "Pirate.h"
#include "Monkey.h"
#include "Ninja.h"
#include "Robot.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

Move* MoveFactory::getMove(std::string moveType)
{
    // if the string returns any string in 
    //Zombie Ninja Robot Monkey Pirate Rock Paper Scissors
    //!question: in Move* MoveFactory::getMove(std::string moveType): do if else statement in this seems to break open-closed principle
    Move* result;
    if (moveType=="Zombie")
    {
        result= (new Zombie());
    }
    else if (moveType=="Pirate")
    {
        result= (new Pirate());
    }
    else if (moveType=="Monkey")
    {
        result=(new Monkey());
    }
    else if (moveType=="Ninja")
    {
        result= (new Ninja());
    } 
    else if (moveType=="Robot")
    {
        result= (new Robot());
    } 
    else if (moveType=="Rock")
    {
        return (new Rock());
    } 
    else if (moveType=="Paper")
    {
        result= (new Paper());
    } 
    else if (moveType=="Scissors")
    {
        result= (new Scissors());
    } 
    else
    {
        result= nullptr;
    }

    return result;
}