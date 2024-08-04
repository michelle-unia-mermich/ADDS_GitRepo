#include <iostream>
#include "Referee.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Move.h"

int main()
{
    //create the WeakerAgainst vector for this game
    std::string arr[]={"Pirate", "Zombie", "Ninja", "Robot", "Monkey", "Paper", "Scissors", "Rock"};
    int size = sizeof(arr) / sizeof(arr[0]);
    Move::instantiateVector(arr, size);

    //create the referee
    Referee referee1;
    Player* player1;
    Player* player2;
    Player* player3;
    player1 = new Human("Person1"); 
    player2 = new Human("Person2");
    player3 = new Computer();

    Player* result_ptr= referee1.refGame(player1, player2);

    if ((result_ptr==player1)||(result_ptr==player2))
    {
        std::cout<< result_ptr->getName()<< " Wins"<<std::endl;
    }
    else if (result_ptr==nullptr)
    {
        std::cout<< "It's a Tie."<<std::endl;
        //no need to delete a nullptr?
    }
    else 
    {
        //incompatible, not printing out anything
        delete result_ptr;
    }


    delete player1;
    delete player2;
    //delete result_ptr; //cannot delete result_ptr here because what if it is equal to player1 or player2, then we are deletingn twice?

    return 0;
}