/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include <unistd.h>
#include "CloseCommand.h"

void CloseCommand::execute(GamesHandler *master, string nameOfGame, int clientSocket) {
    master->end(nameOfGame);
    close(clientSocket);
}
