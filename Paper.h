#ifndef PAPER_H
#define PAPER_H
#include <iostream>
#include "Move.h"
#include <string>

class Paper: public Move
{
    public:
        Paper();
        ~Paper(){};

};
#endif