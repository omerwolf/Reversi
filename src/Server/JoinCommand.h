/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/

#ifndef EX3_JOINCOMMAND_H
#define EX3_JOINCOMMAND_H


#include "GamesHandler.h"
#include "Command.h"

class JoinCommand: public Command { ;
private:
    /**********************************************************************
    * function name: execute
    * The input: GamesHandler*, string , int Socket (default value = 0)
    * The Output: No Output
    * The Function operation: add the player to RoomGame and start new reversi
    *                         game.
    ***********************************************************************/
    void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) ;

public:
  /**********************************************************************
  * function name: JoinCommand (defult con's)
  * The input:
  * The Output:
  * The Function operation: initialized the join command
  ***********************************************************************/
    JoinCommand(){}
};


#endif //EX3_JOINCOMMAND_H
