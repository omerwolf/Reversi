/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_SERVER_H
#define EX3_SERVER_H
#include <iostream>

class Server {
private:

    int port, serverSocket;
    void handleClient(int clientSocket1, int clientSocket2);

public:
    /***********************************************************************
    * function name: Server (con's)
    * The input:  int
    * The Output: No Output
    * The Function operation: build the server from port and socket.   											   *
    ***********************************************************************/
    Server(int port);
    /***********************************************************************
    * function name: start        							   *
    * The input: No Input		  										   *
    * The Output: No Output											       *
    * The Function operation: initialize the server, define 2 clientSocket
    * and listen the sockets. after accepting both clientSockets the function
    * handle them.
    ***********************************************************************/
    void start();
    /***********************************************************************
    * function name: stop        							   *
    * The input: No Input		  										   *
    * The Output: No Output											       *
    * The Function operation: shut down the socket
    ***********************************************************************/
    void stop();

};


#endif //EX3_SERVER_H
