#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "player.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void errorUsage()
{
    perror("ERROR Usage : server <port> OR client <server_address> <port>\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        errorUsage();
    }

    // Initialise player
    Player player = newPlayer();

    if(strcmp(argv[1], "server") == 0)
    {
        printf("Lets create a battlesheep server\n");
        if(argc != 3)
        {
            errorUsage();
        }
        initializeServer(&player, argv[2]);
    }
    else if (strcmp(argv[1], "client") == 0)
    {
        printf("Lets try to connect to the server.\n");
        if(argc != 4)
        {
            errorUsage();
        }
        initializeClient(&player, argv[2], argv[3]);
    }
    else
    {
        errorUsage();
    }

    play_game(&player);
}