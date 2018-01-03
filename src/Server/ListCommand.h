/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/

#ifndef EX3_LISTCOMMAND_H
#define EX3_LISTCOMMAND_H


#include "GamesHandler.h"
#include "Command.h"

class ListCommand : public Command{
public:
    /**********************************************************************
    * function name: ListCommand (defult con's)
    * The input:
    * The Output:
    * The Function operation: initialized the list command
    ***********************************************************************/
    ListCommand(){};
    /**********************************************************************
    * function name: execute
    * The input: GamesHandler*, string , int Socket (default value = 0)
    * The Output: No Output
    * The Function operation:  print the client all potential game names
    ***********************************************************************/
    void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) ;
};


#endif //EX3_LISTCOMMAND_H
