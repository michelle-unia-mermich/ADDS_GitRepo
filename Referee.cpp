#include "Referee.h"
#include <iostream>

Referee::Referee()
{

}
        
Player* Referee::refGame(Player* player1, Player* player2)
{
    char p1_move= player1->makeMove();
    char p2_move= player2->makeMove();
    Player* result;

    switch (p1_move)
    {
        case 'R':
            if (p2_move=='R')
            {
                result=nullptr;
            }
            else if (p2_move=='P')
            {
                result=player2;
            }
            else if (p2_move=='S')
            {
                result=player1;
            }
            break;

        case 'S':
            if (p2_move=='S')
            {
                result=nullptr;
            }
            else if (p2_move=='R')
            {
                result=player2;
            }
            else if (p2_move=='P')
            {
                result=player1;
            }
            break;

        case 'P':
            if (p2_move=='P')
            {
                result=nullptr;
            }
            else if (p2_move=='S')
            {
                result=player2;
            }
            else if (p2_move=='R')
            {
                result=player1;
            }
            break;

        default:
            std::cout <<"The move of player 1 is not valid, name "<< player1->getName()<< std::endl;
    }
    
    return result;
    

}
