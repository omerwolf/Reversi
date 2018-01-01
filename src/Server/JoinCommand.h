//
// Created by yoel on 02/01/18.
//

#ifndef EX3_JOINCOMMAND_H
#define EX3_JOINCOMMAND_H


#include "GamesHandler.h"
#include "Command.h"

class JoinCommand: public Command {
    JoinCommand(){};
    void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) ;
};


#endif //EX3_JOINCOMMAND_H
