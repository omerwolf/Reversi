/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "Server.h"
#include "CommandManager.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;
#define NUMOFPLAYER 10
#define MAXSIZECOMMAND 50

static void* handleOneClient(void* socket);
static void* clientAccept(void* socket);


Server::Server(int port): port(port), serverSocket(0), serverThreadID(0){
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
    currentNumOfPlayer = 0;
    int rc = pthread_create(&serverThreadID, NULL, &clientAccept, (void*)serverSocket);
    if (rc){
        cout << "Error: unable to create thread " << rc << endl;
        pthread_exit(NULL);
    }
    waitForExit();
}

void Server::waitForExit() {
    string input;
    while (true){
        cin >> input;
        if (!strcmp(input.c_str(), "exit")){
            return stop();
        }
    }
}

static void* clientAccept(void *socket) {
    long serverSocket = (long) socket;
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAdderssLen =0;
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAdderssLen);
        if (clientSocket == -1) {
            cout << "Error on accept socket1";
            return NULL;
        }
        cout << "Client connected" << endl;
        pthread_t threadId;
        int rc = pthread_create(&threadId, NULL, &handleOneClient, (void*) clientSocket);
        if (rc){
            cout << "Error: unable to create thread " << rc << endl;
            return NULL;
        }
        pthread_detach(pthread_self());
    }
}

static void* handleOneClient(void* socket) {
    long clientSocket = (long) socket;
    char buffer[MAXSIZECOMMAND];
    int check = read(clientSocket, buffer, sizeof(buffer));
    if (check == -1) {
        cout << "Error reading the client command";
        close(clientSocket);
        return NULL;
    }
    else if ( check == 0){
        close(clientSocket);
        cout << "Client is disconnected";
        return NULL;
    }
    string str(buffer);
    istringstream iss(str);
    string command;
    string nameOfGame;
    iss >> command;
    //command check
    if (command != "start" && (command != "list_games") && (command != "join") && (command != "close")) {
        cout << "Error matching command";
        close(clientSocket);
        return NULL;
    } else {
        if ((command == "start") || (command == "join") || (command == "close")) {
            iss >> nameOfGame;
        } else {
            nameOfGame = "default";
        }
    }
    CommandManager::getInstance()->executeCommand(command, nameOfGame, clientSocket);
}


void Server::stop() {
    delete CommandManager::getInstance()->get();
    pthread_cancel(serverThreadID);
    pthread_join(serverThreadID, NULL);
    close(serverSocket);
}

