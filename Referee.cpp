#include "Referee.h"
#include <iostream>

Referee::Referee()
{

}

Move* Referee::beat(Move* move1_ptr, Move* move2_ptr)
{
    std::string move1 = move1_ptr->getName();
    std::string move2 = move1_ptr->getName();
    Move* result;

    if ((move1=="Rock")||(move1=="Paper")||(move1=="Scissors"))
    {
        if ((move2=="Rock")||(move2=="Paper")||(move2=="Scissors"))
        {

        }
        else
        {
            //undefined behaviour
        }
    }
    else if ((move1=="Robot")||(move1=="Monkey")||(move1=="Pirate")||(move1=="Ninja")||(move1=="Zombie"))
    {
        if ((move2=="Robot")||(move2=="Monkey")||(move2=="Pirate")||(move2=="Ninja")||(move2=="Zombie"))
        {
            
        }
        else
        {
            //undefined behaviour
        }
    }
    else
    {
        //undefined behaviour
    }
}
        
Player* Referee::refGame(Player* player1, Player* player2)
{
    Move* move1= player1->makeMove();
    Move* move2= player2->makeMove();
    
    Player* result;

    Move* winning_move = this->beat(move1, move2);

    if (winning_move==nullptr)
    {
        //it's a tie
        result = nullptr;
    }
    else 
    {
        if (move1->getName()==winning_move->getName())
        {
            result=player1;
        }
        else if (move2->getName()==winning_move->getName())
        {
            result=player2;
        }
    }
    return result;
    

}
