/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_SERVERCONNECTOR_H
#define EX3_SERVERCONNECTOR_H
#include <iostream>
#include <string>
#define MAXSIZE 10
using namespace std;

class ServerConnector {
private:
    string serverIP;
    int serverPort, clientSocket;
public:
    ServerConnector();
    ServerConnector(const string & str, int serverPort);
    ~ServerConnector();
    void connectToServer();
    char* getMove();
    void sendMove(const char* str);
};


#endif //EX3_SERVERCONNECTOR_H
