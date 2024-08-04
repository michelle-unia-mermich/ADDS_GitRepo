#include "Referee.h"
#include <iostream>

     
Player* Referee::refGame(Player* player1, Player* player2)
{
    Move* move1= player1->makeMove();
    Move* move2= player2->makeMove();

    //only proceed if the two moves are compatible
    std::string array1[]={"Pirate", "Zombie", "Ninja", "Robot", "Monkey"};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    std::string array2[]={ "Paper", "Scissors", "Rock"};
    int size2 = sizeof(array2) / sizeof(array2[0]);
    bool array1_move1=false;
    bool array2_move1=false;
    bool array1_move2=false;
    bool array2_move2=false;
    for(int i=0;i<size1;i++)
    {
        if (array1[i]==move1->getName())
        {
            array1_move1=true;
        }
        if (array1[i]==move2->getName())
        {
            array1_move2=true;
        }
    }
    for(int j=0;j<size2;j++)
    {
        if (array2[j]==move1->getName())
        {
            array2_move1=true;
        }
        if (array2[j]==move2->getName())
        {
            array2_move2=true;
        }
    }

    //only when the two moves are compatible
    if (((array1_move1==true)&&(array1_move2==true))||((array2_move1==true)&&(array2_move2==true)))
    {
        //---------------------------------------------
        if (move1->isWeakAgainst(move2))
        {
            //player2 wins
            return player2; 
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
                return player1;
            }

            //or, can also check if move2->isWeakAgainst(move1): yes: winner is player2; no: it's a tie
        }
        //---------------------------------------------
    }
    else
    {
        //the moves are not compatible
        //behaviour is undefined, do not print out anything
        //must have return because the function is non-void
        //return nullptr; //!THIS IS WRONG, if it's incompatible it prints out Tie

        Player* newPointer = new Computer("Incompatible");
        return newPointer;
    }
    

}
