#ifndef ROCK_H
#define ROCK_H
#include <iostream>
#include "Move.h"
#include <string>

class Rock: public Move
{
    public:
        //! std::vector<std::string> weakerAgainst; override //Why must our child classes of Move have this 
        Rock();
        //!Rock(std::string name); //in class Rock: why must we have this when we can just set the name to "Rock" in the default constructor?
        ~Rock(){};

};
#endif