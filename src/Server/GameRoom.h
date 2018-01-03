/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_GAMEROOM_H
#define EX3_GAMEROOM_H
#include <iostream>
#include "stdlib.h"
#include <string>
#include <vector>
#include <pthread.h>

class GameRoom {
private:
    int clientSocket1, clientSocket2, counter=0;
    pthread_t threadId;

public:
  /**********************************************************************
  * function name: GameRoom (defult con's)
  * The input: no input		 										     *
  * The output: no output
  * The Function operation: initialized the GameRoom
  ***********************************************************************/
    GameRoom();
 /***********************************************************************
 * function name: GameRoom (d'tor)                                       *
 * The input: no input		 										     *
 * The Output: no output										         *                         *
 ***********************************************************************/
    ~GameRoom();
 /***********************************************************************
  * function name: Play                                                  *
  * The input: no input		 									         *
  * The Output: no output										         *
  * The Function operation: start new reversi game
  ***********************************************************************/
    void play();
  /***********************************************************************
  * function name: end                                                  *
  * The input: no input		 									         *
  * The Output: no output										         *
  * The Function operation: safe close the GameRoom
  ***********************************************************************/
    int end();
   /***********************************************************************
   * function name: setClientSocket1/2                                    *
   * The input: no input		 								          *
   * The Output: no output										          *
   * The Function operation: Set the private member ClientSocket1/2
   ***********************************************************************/
    void setClientSocket1(int clientSocket1);
    void setClientSocket2(int clientSocket2);
    /***********************************************************************
    * function name: setThreadId                                          *
    * The input: pthread_t		 								          *
    * The Output: no output										          *
    * The Function operation: Set the private member threadID             *
    ***********************************************************************/
    void setThreadId(pthread_t threadId);
    /***********************************************************************
    * function name: increaseCounter                                      *
    * The input: no input		 								          *
    * The Output: no output										          *
    * The Function operation: increase the counter of the current players in
    *                         the GameRoom by 1
    ***********************************************************************/
    void increaseCounter() {counter++;};
    /***********************************************************************
    * function name: getCounter                                           *
    * The input: no input		 								          *
    * The Output: no output										          *
    * The Function operation: Set the private member counter              *
    ***********************************************************************/
    int getCounter(){ return counter;};

};


#endif //EX3_GAMEROOM_H
