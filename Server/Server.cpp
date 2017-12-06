/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;
#define NUMOFPLAYER 3


Server::Server(int port): port(port), serverSocket(0){
    cout << "Server" << endl;
}

void Server::start(){
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1){
        throw "Error opening socket";
    }
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1){
        throw "Error on binding";
    }
    listen(serverSocket, NUMOFPLAYER);
    struct sockaddr_in clientAddress;
    socklen_t clientAdderssLen;
    while (true){
        cout << "Waiting for client connections..." << endl;
        int clientSocket = accept(serverSocket, (
        struct sockaddr *)&clientAddress, &clientAdderssLen);
        if (clientSocket == -1){
            throw "Error on accept";
        }
        handleClient(clientSocket);
        close(clientSocket);
    }
}

void Server::stop() {

}
