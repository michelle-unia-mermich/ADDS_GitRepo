#include <iostream>
#include "Move.h"
#include <algorithm>

//declaration of static data member vector outside the class
//defining it fixes the unresolved external error, see https://stackoverflow.com/questions/7531981/how-to-instantiate-a-static-vector-of-object

std::string Move::weakerAgainstArray[]={"Pirate", "Zombie", "Ninja", "Robot", "Monkey", "Paper", "Scissors", "Rock"};

Move::Move()
{
    name="";
}

Move::~Move()
{

}


void Move::setName(std::string newName)
{
    this->name = newName;
}

std::string Move::getName()
{
    return name;
}

std::string* Move::getweakerAgainstArray()
{
    return weakerAgainstArray;
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
        std::cout << "This line is executed 1.";
        return false;
   }
   else if ((name=="Rock")&&(opponentMoveName=="Paper"))
   {
        //ours is weaker
        return true;
   }
    //following the rules of the array {"Pirate", "Zombie", "Ninja", "Robot", "Monkey", "Paper", "Scissors", "Rock"}
    //for(std::string moveName : weakerAgainst) //recall: this is how you loop in a vector
    //recall: another to loop through a vector is like this
    int size_array = sizeof(weakerAgainstArray)/sizeof(weakerAgainstArray[0]);
    for(int i = 0; i < size_array ; i++)
    {
        if(weakerAgainstArray[i] == this->name) //can also use vec.at(i) instead of vec[i]
        {
            //can also use find() to find the index of an element in a vector but it might be more complicated
            int indexOurMove = i;
            for(int j = (indexOurMove+1); j < size_array ; j++)
            {
                if(weakerAgainstArray[j]==opponentMoveName)
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