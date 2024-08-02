#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Move.h"

class Player
{
    //abstract class
    protected:
        std::string move; //? is this still needed
        std::string name;

    public:
        virtual Move* makeMove()=0; //*return type is changed - a hint to polymorphism
        //The part when "entering a move" is always in Human class, not Player class. Computer always plays Rock regardless - in Computer, there is no entring a move
        virtual std::string getName(); //*not a pure virtual method, it is shared functionality between two child classes of Player.h so it can be defined in Player.cpp
        virtual ~Player(); 

};
#endif
