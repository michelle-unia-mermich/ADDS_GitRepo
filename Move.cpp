#include <iostream>
#include "Move.h"
#include <algorithm>

//declaration of static data member vector outside the class
//defining it fixes the unresolved external error, see https://stackoverflow.com/questions/7531981/how-to-instantiate-a-static-vector-of-object
std::vector<std::string> Move::weakerAgainst;
//!Where to put this line

Move::Move()
{
    name="";
}

Move::~Move()
{

}

void Move::instantiateVector(std::string arr[], int size)
{
    //initialise vector via array
    for (int i=0; i<size ; i++)
    {
        weakerAgainst.push_back(arr[0]);
    }
}

void Move::setName(std::string newName)
{
    this->name = newName;
}

std::string Move::getName()
{
    return name;
}

std::vector<std::string> Move::getWeakerAgainst()
{
    return weakerAgainst;
}

void Move::setWeakerAgainst(std::vector<std::string> newWeakerAgainst)
{
    weakerAgainst = newWeakerAgainst;
}

bool Move::isWeakAgainst(Move* newMove)
{
    //this->name; //is our name
    std::string opponentMoveName = newMove->getName();

    if(this->name == opponentMoveName)
    {
        return false; //it's a tie, return false
    }

    /*exceptions to the rule of the array
    * Zombie > Monkey
    * Pirate > Robot
    * Pirate > Monkey
    * Paper > Rock  
    */ 
   if ((name=="Zombie")&&(opponentMoveName=="Monkey"))
   {
        //ours is stronger
        return false;
   }
   else if ((name=="Monkey")&&(opponentMoveName=="Zombie"))
   {
        //ours is weaker
        return true;
   }

   if ((name=="Pirate")&&(opponentMoveName=="Robot"))
   {
        //ours is stronger
        return false;
   }
   else if ((name=="Robot")&&(opponentMoveName=="Pirate"))
   {
        //ours is weaker
        return true;
   }

   if ((name=="Pirate")&&(opponentMoveName=="Monkey"))
   {
        //ours is stronger
        return false;
   }
   else if ((name=="Monkey")&&(opponentMoveName=="Pirate"))
   {
        //ours is weaker
        return true;
   }

    if ((name=="Paper")&&(opponentMoveName=="Rock"))
   {
        //ours is stronger
        return false;
   }
   else if ((name=="Rock")&&(opponentMoveName=="Paper"))
   {
        //ours is weaker
        return true;
   }
    //following the rules of the array
    //for(std::string moveName : weakerAgainst) //recall: this is how you loop in a vector
    //recall: another to loop through a vector is like this
    for(unsigned int i = 0; i < weakerAgainst.size(); i++)
    {
        if(weakerAgainst[i] == this->name) //can also use vec.at(i) instead of vec[i]
        {
            //can also use find() to find the index of an element in a vector but it might be more complicated
            unsigned int indexOurMove = i;
            for(unsigned int j = indexOurMove; j < weakerAgainst.size(); j++)
            {
                if(weakerAgainst[j]==newMove->getName())
                {
                    //then the opponent Name is found after ourMoveName in WeakerAgainst vector => our move is weaker against
                    return true;
                    break; //break the loop to find opponentMoveName (actually this one no need since return true already exits out of the whole isWeakerAgainst function)
                }
            }
            break;//break the loop to find index of this->name
        }
    }
    return false;

}