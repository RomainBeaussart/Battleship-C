#include "client.h"

#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct sockaddr_in sockaddr_in;

void error_client(char *msg)
{
    perror(msg);
    //exit(1);
}

Client* newClient(char* server_address, char* port)
{
    Client* myClient = malloc(sizeof(Client));

    int client_socket, port_number;
    sockaddr_in server_addr;
    struct hostent *server;

    port_number = atoi(port);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0)
    {
        error_client("ERROR create socket");
        exit(1);
    }

    server = gethostbyname(server_address);
    if(server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr_list[0], (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port_number);

    if(connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) > 0)
    {
        error_client("ERROR connecting");
        exit(1);
    }

    myClient->client_socket = client_socket;
    return myClient;
}

void clientWrite(Client* client, char data[])
{
    int n = write(client->client_socket, data, strlen(data));
    if(n < 0)
    {
        error_client("ERROR writing to the server");
        printf("Code error: %d", n);
        exit(1); 
    }
}

void clientRead(Client* client, char data_returned[])
{
    bzero(client->buffer, 256);
    int n = read(client->client_socket, client->buffer, 255);

    if(n < 0)
    {
        error_client("ERROR reading from the server");
        printf("Code error: %d", n);
        exit(1);
    }
    strncpy(data_returned, client->buffer, strlen(client->buffer));
}