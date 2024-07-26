#ifndef REFEREE_H
#define REFEREE_H
#include <iostream>
#include <string.h>
#include "Player.h"

class Referee
{
    public:
        Referee();
        //returns the references to the winning player
        Player* refGame(Player* player1, Player* player2);

};
#endif