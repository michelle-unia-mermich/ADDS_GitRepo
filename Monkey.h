#ifndef Monkey_H
#define Monkey_H
#include <iostream>
#include "Move.h"
#include <string>

class Monkey: public Move
{
    public:
        Monkey();
        ~Monkey(){};

};
#endif