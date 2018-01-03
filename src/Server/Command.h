/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H
#include <string>
#include "GamesHandler.h"
using namespace std;

class Command {
public:
  /**********************************************************************
  * function name: interface execute
  * The input: GamesHandler*, string , int Socket (default value = 0)
  * The Output: No Output
  ***********************************************************************/
    virtual void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) =0;
  /***********************************************************************
  * function name: Command (d'tor)                                       *
  * The input: No input		 										     *
  * The Output: no Output										         *                         *
  ***********************************************************************/
    virtual ~Command() {};
};


#endif //EX3_COMMAND_H
