#ifndef REFEREE_H
#define REFEREE_H
#include <iostream>
#include <string.h>
#include "Player.h"

class Referee
{
    public:
        Referee();
        Player* refGame(Player* player1, Player* player2); //returns the references to the winning player
        Move* beat(Move* move1_ptr, Move* move2_ptr); //returns pointer to the move that wins

};
#endif