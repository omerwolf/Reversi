/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/

#include "JoinCommand.h"

void JoinCommand::execute(GamesHandler *master, string nameOfGame, int clientSocket) {
    master->join(nameOfGame, clientSocket);
}
