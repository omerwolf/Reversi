/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_STARTCOMMAND_H
#define EX3_STARTCOMMAND_H
#include "Command.h"
#include "GameRoom.h"

class StartCommand : public Command {
public:
    /**********************************************************************
    * function name: StartCommand (defult con's)
    * The input: No Input
    * The Output: No Output
    * The Function operation: initialized the start command
    ***********************************************************************/
    StartCommand(){};
    /**********************************************************************
    * function name: execute
    * The input: GamesHandler*, string , int Socket (default value = 0)
    * The Output: No Output
    * The Function operation: Open new RoomGame and add the name of game to
    *                         the list of games
    ***********************************************************************/
    void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) ;
};


#endif //EX3_STARTCOMMAND_H
