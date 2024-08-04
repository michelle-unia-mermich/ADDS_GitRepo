#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H
#include <iostream>
#include <string>
#include "Move.h"

class MoveFactory
{
    public:
        static Move* getMove(std::string moveType);

};
#endif
