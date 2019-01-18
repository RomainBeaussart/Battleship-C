#ifndef _SERVER_H
#define _SERVER_H

typedef struct Server Server;
struct Server
{
    int client_socket;
    char buffer[256];  
};

Server* newServer(char* port);
void serverRead(Server* server, char data_returned[]);
void serverWrite(Server* server, char data[]);

#endif