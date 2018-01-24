/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_SERVER_H
#define EX3_SERVER_H
#define NUMOFTASK 10
#define NUMOFTHREADS 5
#include <iostream>
#include <vector>
#include <pthread.h>
#include "ThreadPool.h"
#include "Task.h"
using namespace std;

class Server {
private:

    int port, serverSocket, currentNumOfPlayer;
    pthread_t serverThreadID;
    ThreadPool pool;
    Task* tasks[NUMOFTASK];
   /// static vector <pthread_t > thr;

public:
    /***********************************************************************
    * function name: Server (con's)                                        *
    * The input:  int                                                      *
    * The Output: No Output                                                *
    * The Function operation: build the server from port and socket.       *									   *
    ***********************************************************************/
    Server(int port);
    /***********************************************************************
    * function name: start        		            					   *
    * The input: No Input		  										   *
    * The Output: No Output											       *
    * The Function operation: initialize the server, define 2 clientSocket
    * and listen the sockets. after accepting both clientSockets the function
    * handle them.                                                         *
    ***********************************************************************/
    void start();
    /***********************************************************************
    * function name: stop        							               *
    * The input: No Input		  										   *
    * The Output: No Output											       *
    * The Function operation: safe close the server                        *
    ***********************************************************************/
    void stop();
    /***********************************************************************
    * function name: waitForExit        					               *
    * The input: No Input		  										   *
    * The Output: No Output											       *
    * The Function operation: run without halting, check if the client write
     *                        the exit command                             *
    ***********************************************************************/
    void waitForExit();
    /***********************************************************************
    * function name: getNumOfPlayer        						           *
    * The input: No Input		  										   *
    * The Output: No Output											       *
    * The Function operation: Set the private member currentNumOfPlayer    *
    ***********************************************************************/
    int getNumOfPlayer(){ return currentNumOfPlayer;};
    void* handleClient(void* pack);
    void* acceptClient(void* pack);
    ///   static void setThreadVector(pthread_t thread){ Server::thr.push_back(thread);};
};

#endif //EX3_SERVER_H
