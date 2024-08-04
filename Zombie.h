#ifndef Zombie_H
#define Zombie_H
#include <iostream>
#include "Move.h"
#include <string>

class Zombie: public Move
{
    public:
        Zombie();
        ~Zombie(){};

};
#endif