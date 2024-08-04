#ifndef Robot_H
#define Robot_H
#include <iostream>
#include "Move.h"
#include <string>

class Robot: public Move
{
    public:
        Robot();
        ~Robot(){};

};
#endif