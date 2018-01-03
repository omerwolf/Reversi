/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_GAMESHANDLER_H
#define EX3_GAMESHANDLER_H

#include <iostream>
#include <string>
#include "GameRoom.h"
#include <map>
using namespace std;

class GamesHandler {
private:
    map <string, GameRoom*> roomMap;
    static pthread_mutex_t lock;
public:
  /**********************************************************************
  * function name: GamesHandler (defult con's)
  * The input: no input		 										     *
  * The output: no output
  * The Function operation: initialized the GamesHandler
  ***********************************************************************/
    GamesHandler(){};
  /***********************************************************************
  * function name: GamesHandler (d'tor)                                  *
  * The input: no input		 										     *
  * The Output: no output										         *                         *
  ***********************************************************************/
    ~GamesHandler(){};
  /**********************************************************************
   * function name: start
   * The input: string nameOfGame, int clientSocket		 										     *
   * The output: 0 if the name is occupied, and 1 o.w
   * The Function operation: open new GameRoom
   ***********************************************************************/
    int start (string nameOfGame, int clientSocket);
    /**********************************************************************
   * function name: start
   * The input:int clientSocket		 										     *
   * The output: vector <string> list of games
   * The Function operation: open new GameRoom
   ***********************************************************************/
    vector <string> list(int clientSocket);
    /**********************************************************************
   * function name: join
   * The input: string nameOfGame, int clientSocket		 										     *
   * The output: 1 if success, and 0 o.w
   * The Function operation: add the second player to the GameRoom
   ***********************************************************************/
    int join (string nameOfGame, int clientSocket);
    /**********************************************************************
   * function name: end
   * The input: string nameOfGame		 										     *
   * The output: 1 if success, and 0 o.w
   * The Function operation: remove the name of the GameRoom from the map
   *                         of all games.
   ***********************************************************************/
    int end(string nameOfGame);
};


#endif //EX3_GAMESHANDLER_H
