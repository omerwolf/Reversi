/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_SERVER_H
#define EX3_SERVER_H
#include <iostream>

class Server {
private:
    int port, serverSocket;
    void handleClient(int clientSocket);

public:
    Server(int port);
    void start();
    void stop();

};


#endif //EX3_SERVER_H
