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
    player1 = new Human("Anna"); 
    player2 = new Human("Anderson");

    Player* result_ptr= referee1.refGame(player1, player2);

    if (result_ptr!=nullptr)
    {
        std::cout<< result_ptr->getName()<< " Wins"<<std::endl;
    }
    else
    {
        std::cout<< "It's a Tie."<<std::endl;
    }


    delete player1;
    delete player2;

    return 0;
}