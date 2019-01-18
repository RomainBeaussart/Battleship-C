#ifndef _CLIENT_H
#define _CLIENT_H

typedef struct Client Client;
struct Client
{
    int client_socket;
    char buffer[256];
};

Client* newClient(char* server_address, char* port);
void clientWrite(Client* client, char data[]);
void clientRead(Client* client, char data_returned[]);

#endif