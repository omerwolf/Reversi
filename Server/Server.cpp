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
#define NUMOFPLAYER 2
#define MAXSIZE 10


Server::Server(int port): port(port), serverSocket(0){
    cout << "Server" << endl;
}

void Server::start() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        close(serverSocket);
        throw "Error opening socket";
    }
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        close(serverSocket);
        throw "Error on binding";
    }
    // Start to listening to incoming connections
    if (listen(serverSocket, NUMOFPLAYER) <0){
        close(serverSocket);
        throw "Error on listening";
    };
    // Define the client socket's structures
    struct sockaddr_in clientAddress1, clientAddress2;
    socklen_t clientAdderssLen1, clientAdderssLen2;
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket1 = accept(serverSocket, (struct sockaddr *) &clientAddress1, &clientAdderssLen1);
        if (clientSocket1 == -1) {
            throw "Error on accept socket1";
        }
        cout << "Client 1 connected" << endl;
        int clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress2, &clientAdderssLen2);
        if (clientSocket2 == -1) {
            throw "Error on accept socket2";
        }
        cout << "Client 2 connected" << endl;

        handleClient(clientSocket1, clientSocket2);
        close(clientSocket1);
        close(clientSocket2);

    }
}
void Server::handleClient(int clientSocket1, int clientSocket2) {
    char buffer[MAXSIZE];
    string init = "1";
    string init2 = "2";
    //write color to player1
    int check = write(clientSocket1, init.c_str(), sizeof(init));
    if (check == -1){
        cout << "Error writing to socket1" << endl;
        return;
    }
    //write color to player2
    check = write(clientSocket2, init2.c_str(), sizeof(init2));
    if (check == -1){
        cout << "Error writing to socket2" << endl;
        return;
    }
    while (true) {
        //Player1 move
        int n = read(clientSocket1, buffer, strlen(buffer)+1);
        if (n == -1) {
            cout << "Error reading the client 1 move" << endl;
            return;
        }
        if (n == 0) {
            cout << "Client 1 disconnected" << endl;
            return;
        }
        n = write(clientSocket2, buffer, strlen(buffer)+1);
        if (n == -1) {
            cout << "Error writing to socket2" << endl;
            return;
        }

        //Player2 move
        n = read(clientSocket2, &buffer, strlen(buffer)+1);
        if (n == -1) {
            cout << "Error reading the client 2 move" << endl;
            return;
        }
        if (n == 0) {
            cout << "Client 2 disconnected" << endl;
            return;
        }
        n = write(clientSocket1, &buffer, sizeof(buffer));
        if (n == -1) {
            cout << "Error writing to socket1" << endl;
            return;
        }
    }

}


void Server::stop() {
    close(serverSocket);
}

