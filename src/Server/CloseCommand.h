//
// Created by yoel on 02/01/18.
//

#ifndef EX3_CLOSECOMMAND_H
#define EX3_CLOSECOMMAND_H
#include "Command.h"

class CloseCommand: public Command {
    CloseCommand(){};
    void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) ;
};


#endif //EX3_CLOSECOMMAND_H
