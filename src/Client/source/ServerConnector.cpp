/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "../include/ServerConnector.h"
#include <stdlib.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include "limits"
using namespace std;
#define MAX_COMMAND_LEN 50


ServerConnector::ServerConnector() :clientSocket(0){
    ifstream myInfo;
    myInfo.open("clientSetting.txt");
    if (myInfo.is_open()) {
        myInfo >> serverPort;
        myInfo >> serverIP;
    }
    else {
        cout << "Error opening file" << endl;
    }
}

ServerConnector::ServerConnector(const string &str, int serverPort) :
        serverIP(str), serverPort(serverPort), clientSocket(0) {
}

ServerConnector::~ServerConnector(){

}

void ServerConnector::connectToServer() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1){
        throw "Error opening socket";
    }
    struct in_addr address;
    if (!inet_aton(serverIP.c_str(), &address)){
        throw "Can't parse IP address";
    }
    struct hostent* server;
    server = gethostbyaddr((const void*)&address, sizeof(address), AF_INET);
    if (server == NULL){
        throw "Host is unreachable";
    }
    struct sockaddr_in serverAddress;
    bzero((char*)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
    serverAddress.sin_port = htons(serverPort);
    if (connect(clientSocket,  (struct sockaddr*) &serverAddress, sizeof(serverAddress))== -1){
        throw "Error connecting to server";
    }
    cout << "Connected to the server" <<endl;
    remotePlayerMenu();
}

char* ServerConnector::getMove() {
    char *temp = new char [MAXSIZE];
    memset(temp, 0, MAXSIZE);
    cout << "waiting for other player's move... "<<endl;
    int n = read(clientSocket, temp, sizeof(temp));
    if ( n == -1){
        throw "Error in reading data";
    }
    return temp;
}

void ServerConnector::sendMove(const char* str) {
    int n =write(clientSocket, str, strlen(str)+1);
    if (n==-1){
        throw "Error writing expression";
    }
}

char* ServerConnector::getSign() {
    char *temp = new char [MAXSIZE];
    memset(temp, 0, MAXSIZE);
    int n = read(clientSocket, temp, sizeof(temp));
    if ( n == -1){
        throw "Error in reading data";
    }
    return temp;
}

void ServerConnector::remotePlayerMenu() {
    char commandStr [MAX_COMMAND_LEN];
    cout << "Choose Option:" << endl;
    cout << "   Host new game            , enter: start<name>" << endl;
    cout << "   See list of current games, enter: list_game" << endl;
    cout << "   Join to game             , enter: join<name>" << endl;
    cin >> commandStr;
    int n = write(clientSocket, commandStr, strlen(commandStr) + 1);
    if (n == -1) {
        cout << "Error writing command";
    }
}