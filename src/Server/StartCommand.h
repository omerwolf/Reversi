/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_STARTCOMMAND_H
#define EX3_STARTCOMMAND_H
#include "Command.h"
#include "GameRoom.h"

class StartCommand : public Command {
public:
    StartCommand(){};
    void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) ;
};


#endif //EX3_STARTCOMMAND_H
