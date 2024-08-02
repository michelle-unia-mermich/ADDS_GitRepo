#include <iostream>
#include "Move.h"
#include <algorithm>

Move::Move()
{
    moveName="";
}

Move::Move(std::string inputMoveName)
{
    //check if this inputMoveName is acceptable in the list
    if(std::find(acceptableNames.begin(), acceptableNames.end(), inputMoveName) != acceptableNames.end()) {
        /* acceptableNames contains inputeMoveName */
        moveName=inputMoveName;
    } else {
        /* v does not contain x */
        std::cout<<"The move entered is not acceptable.";
        moveName="";
    }

}

std::string Move::getName()
{
    return moveName;
}
