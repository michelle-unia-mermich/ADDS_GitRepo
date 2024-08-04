#include "Referee.h"
#include <iostream>

     
Player* Referee::refGame(Player* player1, Player* player2)
{
    Move* move1= player1->makeMove();
    Move* move2= player2->makeMove();

    if (move1->isWeakAgainst(move2))
    {
        //player1 wins
        return player1; 
    }
    else 
    {
        //there are two cases, either a tie or player 1 loses
        if (move1->getName()==move2->getName())
        {
            return nullptr; //it's a tie
        }
        else
        {
            return player2;
        }

        //or, can also check if move2->isWeakAgainst(move1): yes: winner is player2; no: it's a tie
    }
    

}
