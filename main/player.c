#include "player.h"

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>

void place_ship(Player* p, Ship s){
    printf("***** setting the %s on the board *****\n", get_ship_type(s));
    do{
        printf("follow the instructions to place the ship. \n");
    }while(set_ship(p->boards->mainBoard, s) == 0);
}

Player newPlayer()
{
    Player myPlayer;
    myPlayer.state = PLAYING;
    myPlayer.action = NOTHING;
    myPlayer.boards = new_boards();
    myPlayer.carrier = new_carrier();
    myPlayer.battleship = new_battleship();
    myPlayer.destroyer = new_destroyer();
    myPlayer.submarine = new_submarine();

    printf("Enter the player name: ");
    scanf("%s", myPlayer.name);
    printf("\n");

    printf("Let's place your ships now.\n");
    place_ship(&myPlayer, myPlayer.carrier);
    place_ship(&myPlayer, myPlayer.battleship);
    place_ship(&myPlayer, myPlayer.submarine);
    place_ship(&myPlayer, myPlayer.destroyer);
    return myPlayer;
}

void initializeServer(Player* p, char* port)
{
    p->server = newServer(port);
    p->client = NULL;
    p->isFirstPlayer = 1;
    p->action = ATTACK;
}

void initializeClient(Player* p, char* serv_address, char* port)
{
    p->client = newClient(serv_address, port);
    p->server = NULL;
    p->isFirstPlayer = 0;
    p->action = WAIT;
}

void sendData(Player* p, char data[])
{
    
    if(p->client == NULL)
    {
        serverWrite(p->server, data);
    }
    else
    {
        clientWrite(p->client, data);
    }
}

void receiveData(Player* p, char data_received[])
{
    bzero(data_received, strlen(data_received));
    if(p->client == NULL)
    {
        serverRead(p->server, data_received);
    }
    else
    {
        clientRead(p->client, data_received);
    }
}

void testWin(Player* p)
{
    printf("Me(%s) testing if a win.\n", p->name);
}

int verifyEntryAttack(char entry[])
{  
    printf("I verify the entry '%s'\n", entry);
    return 1;
}

void updateMarkBoard(Player* p, Box b)
{
    printf("\nI'm updating the mark board now...\n");
    printf("Attack's result: ");
    char array_data[1];
    receiveData(p, array_data);
    char valueReceived = array_data[0];
    switch(valueReceived){
        case '0':
            printf("Missed !\n");
            set_case(p->boards->markBoard, b, 'x');
            break;
        case '1':
            printf("Hit !\n");
            set_case(p->boards->markBoard, b, 'O');
            break;
        case '2':
            printf("Boat down\n");
            set_case(p->boards->markBoard, b, 'O');
            break;
    }

}

void attack(Player* p)
{
    char msg[256] = {'\0'};
    printf("Where do you want to fire? ");
    scanf("%s", msg);

    while(verifyEntryAttack(msg) != 1)
    {
        printf("ERROR Entry:\nFormat = A4, C9, ...\nColumns = A B C D E F G H I J\nRows = 0 1 2 3 4 5 6 7 8 9\n");
        printf("please try again: ");
        scanf("%s", msg);
    }
    sendData(p, msg);
    Box my_attack_box;
    my_attack_box.abs = msg[0];
    my_attack_box.ord = msg[1]-'0';
    updateMarkBoard(p, my_attack_box);
}

void endureAttack(Box attack, Player* p){
    int case_state = get_state(attack, (*p->boards->mainBoard));
    char response[] = {};

    switch(case_state){
        case 1:
            printf("HIT !\n");
            set_case(p->boards->mainBoard, attack, toupper(get_case_from_box(attack, *p->boards->mainBoard)));
            response[0] = '1';
            break;
        case 0:
            printf("MISSED !\n");
            set_case(p->boards->mainBoard, attack, 'x');
            response[0] = '0';
            break;
    }

    sendData(p, response);
}

void receiveAttack(Player* p)
{
    char received_attack[2];
    receiveData(p, received_attack);
    printf("I have received the attack: %s\n", received_attack);
    Box my_attack_box;
    my_attack_box.abs = received_attack[0];
    my_attack_box.ord = received_attack[1]-'0';
    endureAttack(my_attack_box, p);
}

void printPlayer(Player* p)
{
    printf("-------------------------------------------------------\n");
    print_boards(*(p->boards));
    printf("-------------------------------------------------------\n");
}

void printAction(Player* p)
{
    printf("\nState = %d\t", p->state);
    printf("Action = %d\n", p->action);
}

void play_game(Player* p)
{
    while(p->state == PLAYING){
        printAction(p);
        printPlayer(p);
        if(p->action == ATTACK){
            printf("Your turn to attack.\n");
            attack(p);
            printf("end of attack turn.\n");
        } else if(p->action == WAIT){
            printf("wait for an attack...\n");
            receiveAttack(p);
            printf("end of waiting turn.\n");
        }

        if(p->action == WAIT){
            p->action = ATTACK;
        } 
        else{
            p->action = WAIT;
        }
    }
}


