#ifndef _PLAYER_H
#define _PLAYER_H

#include "client.h"
#include "server.h"
#include "../Board/board.h"
#include "../Ship/ship.h"

enum state{PLAYING = 0, WINNER = 1, LOOSER = 2};
enum action{ATTACK = 1, WAIT = 0, NOTHING = -1};
typedef struct Player Player;
struct Player
{
    enum action action;
    enum state state;
    char name[25];
    int isFirstPlayer;
    Client* client;
    Server* server;
    Boards* boards;
    Ship carrier;
    Ship battleship;
    Ship submarine;
    Ship destroyer;
};

Player newPlayer();
void play_game(Player* p);
void sendData(Player* p, char data[]);
void receiveData(Player* p, char data_received[]); 
void printPlayer(Player* p);
void attack(Player* p);
void receiveAttack(Player* p);
void testWin(Player* p);
void initializeServer(Player* p, char* port);
void initializeClient(Player* p, char* serv_address, char* port);

#endif