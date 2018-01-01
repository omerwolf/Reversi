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
    virtual void execute(GamesHandler* master, string nameOfGame, int clientSocket = 0) =0;
    virtual ~Command() {};
};


#endif //EX3_COMMAND_H
