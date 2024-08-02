#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string.h>
#include <vector>

class Move
{
    private:
        //create a static vector to store all the acceptable names of class Move
        static std::vector<std::string> acceptableNames; //?Where to set the values of the static data member? Instructor's answer: in the constructor. Every object has the static data member, so every object can set it.??but this is questionable, find the answer again.
        //Another keyword is "final", in which we can only set the value ONCE. but for static, we can set the value more than once.
        std::string moveName;
    public:
        Move();
        Move(std::string inputMoveName);
        std::string getName(); //returns the name of a Move instance, for ex, "Ninja"
        //another way of the Beat() function in the referee class is to include a compare(pointer to another move) function here in the Move class, comparing it with another

};
#endif