#ifndef _GAME_H
#define _GAME_H

#include "player.h"


typedef struct Game Game;
struct Game{
    Player* player;
    char* opponent_name;
    int endGame;
};

Game* newGame(Player* p, char* opponent);
void playGame(Game* g);

#endif