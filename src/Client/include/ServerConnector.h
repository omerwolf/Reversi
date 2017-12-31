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
    /***********************************************************************
    * function name: ServerConnector (Default con's)					   *
    * The input: No Input		  										   *
    * The Output: No Output											       *
    * The Function operation: make the initialization of the serverPort
    * and serverIP reading from the destination file.			           *
    ***********************************************************************/
    ServerConnector();
    /***********************************************************************
    * function name: ServerConnector (con's)							   *
    * The input: const string & , int		  				               *
    * The Output: No Output											       *
    * The Function operation: make the connection with the server reading
    from given an ip and port.											   *
    ***********************************************************************/
    ServerConnector(const string & str, int serverPort);
    /***********************************************************************
    * function name: ServerConnector (d'str)							   *
    * The input: No Input		  										   *
    * The Output: No Output											       *
    * The Function operation: Nothing.									   *
    ***********************************************************************/
    ~ServerConnector();
    /***********************************************************************
    * function name: connectToServer        							   *
    * The input: No Input		  										   *
    * The Output: No Output											       *
    * The Function operation: making the connection with the server
    * according to the serverPort and serverIP.							   *
    ***********************************************************************/
    void connectToServer();
    /***********************************************************************
    * function name: getMove                							   *
    * The input: No Input		  										   *
    * The Output: char*											           *
    * The Function operation: reading from the socket and return the data.							   *
    ***********************************************************************/
    char* getMove();
    /***********************************************************************
    * function name: getSign                							   *
    * The input: No Input		  										   *
    * The Output: char*											           *
    * The Function operation: reading from the socket the sign of the
    * player and return the data.							               *
    ***********************************************************************/
    char* getSign();
    /***********************************************************************
    * function name: sendMove                							   *
    * The input: const char*		  									   *
    * The Output: No Output											       *
    * The Function operation: given a string write it to socket.           *
    ***********************************************************************/
    void sendMove(const char* str);
    void remotePlayerMenu();
};


#endif //EX3_SERVERCONNECTOR_H
