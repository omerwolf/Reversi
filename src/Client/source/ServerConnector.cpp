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
#include <sstream>

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
    int n;
    do {
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
        n = remotePlayerMenu(); } while (n == 0);
}

char* ServerConnector::getMove() {
    char *temp = new char [MAXSIZE];
    memset(temp, 0, MAXSIZE);
    cout << "waiting for other player's move... "<<endl;
    int n = read(clientSocket, temp, sizeof(temp));
    if ( n == -1){
        throw "Error in reading data";
    }
    else if ( n == 0){
        throw "Client is disconnected";
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
    else if ( n == 0){
        throw "Room alread exist, Client is disconnected";
    }
    return temp;
}

int ServerConnector::remotePlayerMenu() {
    string input ;
    cout << "Choose Option:" << endl;
    cout << "   Host new game            , enter: start<name>" << endl;
    cout << "   See list of current games, enter: list_games" << endl;
    cout << "   Join to game             , enter: join<name>" << endl;
    getline(cin, input);
    int n = write(clientSocket, input.c_str(), input.size()+1);
    if (n == -1) {
        cout << "Error writing command";
    }
    string buffer(input);
    istringstream iss(buffer);
    string command;
    string nameOfGame;
    iss >> command;
    if (!strcmp(command.c_str(),"list_games")){
        int num;
        int check = read(clientSocket, &num, sizeof(num));
        for (int i = 0; i < num ; i++){
            int size;
            char str[MAX_COMMAND_LEN];
            int check = read(clientSocket, &size, sizeof(size));
            if (check == -1) {
                cout << "Error reading command";
            }
            else if ( check == 0){
                throw "Client is disconnected";
            }
            check = read(clientSocket, str, size+1);
            if (check == -1) {
                cout << "Error reading command";
            }
            else if ( check == 0){
                throw "Client is disconnected";
            }
            else{
                cout << str << endl;
            }
        }
        return 0;
    }
    else if ((!strcmp(command.c_str(), "start") || (!strcmp(command.c_str(), "join")))){
        cout << "waiting for other player to join" << endl;
        return 1;
    }
    else
        return 0;
}
