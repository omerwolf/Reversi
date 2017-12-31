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
#define NUMOFPLAYER 10
#define MAXSIZE 10

typedef struct twoPlayer{
    int clientSocket1, clientSocket2;
};

Server::Server(int port): port(port), serverSocket(0){
}

void Server::start() {
    pthread_t threads[NUMOFPLAYER];
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
    currentNumOfPlayer = 0;
    int rc = pthread_create(&threadList[currentNumOfPlayer], NULL, clientAccept, NULL);
    if (rc){
        cout << "Error: unable to create thread " << rc << endl;
    }
}

void* Server::clientAccept(void *pVoid) {
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAdderssLen;
    while (currentNumOfPlayer < NUMOFPLAYER) {
        currentNumOfPlayer++;
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAdderssLen);
        if (clientSocket == -1) {
            throw "Error on accept socket1";
        }
        cout << "Client 1 connected" << endl;
        currentNumOfPlayer++;
        try {
            int rc = pthread_create(&threadList[currentNumOfPlayer], NULL, handleOneClient, (void*) clientSocket);
            if (rc){
                cout << "Error: unable to create thread " << rc << endl;
            }
        } catch (const char* msg){
            cout<< msg <<endl;
        }
        close(clientSocket);
        currentNumOfPlayer--;
    }
}

void* Server::handleOneClient(void* clientSocket){
    int clientSocket1 = (int) clientSocket;
    char buffer[50];
    twoPlayer* game;
    game->clientSocket1 = clientSocket1;
    int check = read(clientSocket1, buffer, sizeof(buffer));
    if (check == -1) {
        throw "Error reading the client 1 move" ;
    }
    try {
        int rc = pthread_create(&threadList[currentNumOfPlayer], NULL, handleClient, (void*) game);
        if (rc){
            cout << "Error: unable to create thread " << rc << endl;
        }
    } catch (const char* msg){
        cout<< msg <<endl;
    }
    close(clientSocket1);
}


void* Server::handleClientGame(void* game) {
    char init = '1';
    char init2 = '2';
    twoPlayer* temp = (twoPlayer*)game;
    int clientSocket1 = temp->clientSocket1;
    int clientSocket2 = temp->clientSocket2;
    //write color to player1
    int check = write(clientSocket1, &init, sizeof(init));
    if (check == -1){
        throw  "Error writing to socket1" ;
    }
    //write color to player2
    check = write(clientSocket2, &init2, sizeof(init2));
    if (check == -1){
        throw "Error writing to socket2" ;
    }
    while (true) {
        char buffer[MAXSIZE];
        //Player1 move
        int n = read(clientSocket1, buffer, sizeof(buffer));
        if (n == -1) {
            throw "Error reading the client 1 move" ;

        }
        if (n == 0) {
            throw "Client 1 disconnected" ;
        }
        n = write(clientSocket2, &buffer, strlen(buffer)+1);
        if (n == -1) {
            throw "Error writing to socket2" ;
        }
        char buff[MAXSIZE];
        //Player2 move
        n = read(clientSocket2, buff, sizeof(buff));
        if (n == -1) {
            throw "Error reading the client 2 move" ;
        }
        if (n == 0) {
            throw "Client 2 disconnected" ;
        }
        n = write(clientSocket1, &buff, strlen(buff)+1);
        if (n == -1) {
            throw "Error writing to socket1" ;
        }
    }

}


void Server::stop() {
    string str;
    while (true){
        cin >> str;
        if (!strcmp(str.c_str(), "exit")){
            close(serverSocket);
            break;
        }
    }
}

