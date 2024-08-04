#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string>
#include <vector>

class Move
{
    protected:
        //create a static vector to store all the acceptable names of class Move
        //static std::vector<std::string> acceptableNames; //?Where to set the values of the static data member? Instructor's answer: in the constructor. Every object has the static data member, so every object can set it.??but this is questionable, if so then we are resetting the static data member so many times while we only want to set it once, find the answer again. But in this case, he didn't need to set it to static.
        //Another keyword is "final", in which we can only set the value ONCE. but for static, we can set the value more than once.
        std::string name;
        static std::vector<std::string> weakerAgainst;
        
        static std::string weakerAgainstArray[];
    public:
        Move();

        std::string getName(); //returns the name of a Move instance, for ex, "Ninja"
        //another way of the Beat() function in the referee class is to include a compare(pointer to another move) function here in the Move class, comparing it with another
        void setName(std::string newName);

        static std::vector<std::string> getWeakerAgainst(); //getter function
        static void setWeakerAgainst(std::vector<std::string> weakerAgainst);//setter function
        static void instantiateVector(std::string arr[], int size);

        bool isWeakAgainst(Move* newMove);

        virtual ~Move();

};


#endif