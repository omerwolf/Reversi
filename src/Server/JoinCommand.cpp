//
// Created by yoel on 02/01/18.
//

#include "JoinCommand.h"

void JoinCommand::execute(GamesHandler *master, string nameOfGame, int clientSocket) {
    master->join(nameOfGame, clientSocket);
}
