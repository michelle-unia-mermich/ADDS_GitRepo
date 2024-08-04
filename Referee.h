#ifndef REFEREE_H
#define REFEREE_H
#include <iostream>
#include <string.h>
#include "Player.h"
#include "Computer.h"
#include "Human.h"

class Referee
{
    public:
        Player* refGame(Player* player1, Player* player2); //returns the references to the winning player

};
#endif