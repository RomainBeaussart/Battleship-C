#include "server.h"

#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct sockaddr_in sockaddr_in;

void error(char *msg)
{
    perror(msg);
    exit(1);
}

Server* newServer(char* port)
{
    Server *myServer = malloc(sizeof(Server));

    int server_socket, client_socket, client_lenght, port_number;
    sockaddr_in server_addr, client_addr;

    // Create the server socket and then check if everything is ok
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0)
    {
        error("ERROR opening socket");
    }

    // Clear the server addr to dodge potential errors
    bzero((char*) &server_addr, sizeof(server_addr));

    // Convert a string to a integer to store the port number
    port_number = atoi(port);
    // Then fill the values of server_addr
    // Here we configure the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_number);

    // Try to bind the socket with the server address
    if(bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)))
    {
        error("ERROR on binding \n");
    }

    // Start listening
    listen(server_socket, 1);

    // Create the socket for the connected client
    client_lenght = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *) &client_addr, (socklen_t *) &client_lenght);
    if(client_socket < 0)
    {
        error("ERROR on accept: \n");
        printf("Code error: %d", client_socket);
    }

    myServer->client_socket = client_socket;
    return myServer;
}

void serverWrite(Server* server, char data[])
{
    // write
    int n = write(server->client_socket, data, strlen(data));
    if(n < 0)
    {
        error("ERROR writing a message\n");
    }
}

void serverRead(Server* server, char data_returned[])
{
    //read 
    bzero(server->buffer, 256);
    int n = read(server->client_socket, server->buffer, 255);
    if(n < 0)
    {
        error("ERROR reading from socket\n");
        printf("ERROR reading from socket\n");
    }
    //printf("I have received data : %s.\n", server->buffer);
    strncpy(data_returned, server->buffer, strlen(server->buffer));
}

