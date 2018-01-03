/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/


#ifndef EX3_CLOSECOMMAND_H
#define EX3_CLOSECOMMAND_H
#include "Command.h"

class CloseCommand: public Command {
public:
  /**********************************************************************
  * function name: CloseCommand (defult con's)
  * The input:
  * The Output:
  * The Function operation: initialized the close command
  ***********************************************************************/
    CloseCommand(){};
  /**********************************************************************
   * function name: execute
   * The input: GamesHandler*, string , int Socket (default value = 0)
   * The Output: No Output
   * The Function operation: Safe close of the GameRoom
   ***********************************************************************/
    void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) ;
};


#endif //EX3_CLOSECOMMAND_H
