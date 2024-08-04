#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Move.h"

#include "Zombie.h"
#include "Pirate.h"
#include "Monkey.h"
#include "Ninja.h"
#include "Robot.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"

class Player
{
    //abstract class
    protected:
        //std::string move; //? is this still needed? Answer: Not needed, change to Move*
        Move* currentMove;
        std::string name;

    public:
        Player();
        Player(std::string newName);

        std::string getName(); //*not a virtual method, it is shared functionality between two child classes of Player.h so it can be defined in Player.cpp
        void setName(std::string newName);

        Move* getCurrentMove();
        //!void setCurrentMove(Move* currentMove); //not sure if a getter function for currentMove is needed when the human enters the move via virtual makeMove() function, while the move of a computer does not change
        
        virtual Move* makeMove()=0; //*return type is changed - a hint to polymorphism
        //The part when "entering a move" is always in Human class, not Player class. Computer always plays Rock regardless - in Computer, there is no entering a move
        
        virtual ~Player(); //!Player.h: we want the child classes to use the destructor of the parent class since the parent class is the one containig a dynamicn pointer. However, the parent class is an abstract class that needs a VIRTUAL destructor. Second, how to make the child classes use both what is written in the destructor of the parent class and also the child class?

};
#endif
