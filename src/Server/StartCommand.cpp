/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "StartCommand.h"

void StartCommand::execute(GamesHandler* master, string nameOfGame, int clientSocket) {
   master->start(nameOfGame, clientSocket);
}

