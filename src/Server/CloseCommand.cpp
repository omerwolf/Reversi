//
// Created by yoel on 02/01/18.
//

#include <unistd.h>
#include "CloseCommand.h"

void CloseCommand::execute(GamesHandler *master, string nameOfGame, int clientSocket) {
    master->end(nameOfGame);
    close(clientSocket);
}
