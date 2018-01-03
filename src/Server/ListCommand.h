//
// Created by yoel on 01/01/18.
//

#ifndef EX3_LISTCOMMAND_H
#define EX3_LISTCOMMAND_H


#include "GamesHandler.h"
#include "Command.h"

class ListCommand : public Command{
public:
    ListCommand(){};
    void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) ;
};


#endif //EX3_LISTCOMMAND_H
