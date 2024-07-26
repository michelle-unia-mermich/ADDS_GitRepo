#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

//<string.h> is the old C header. 
//C++ provides <string>, and then it should be referred to as std::string.

class Player
{
    //abstract class
    protected:
        char move;
        std::string name;

    public:
        virtual char makeMove()=0;
        virtual std::string getName()=0;

};
#endif