#include "game.h"

#include <stdlib.h>
#include <stdio.h>

Game* newGame(Player* p, char* opponent)
{
    Game* myGame = malloc(sizeof(Game));
    myGame->endGame = 0;
    myGame->opponent_name = opponent;
    myGame->player = p;
    
    return myGame;
}

