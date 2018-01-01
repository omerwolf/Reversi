//
// Created by yoel on 01/01/18.
//

#include <cstring>
#include <unistd.h>
#include "ListCommand.h"

void ListCommand::execute(GamesHandler *master, string nameOfGame, int clientSocket) {
    vector <string> listofGame = master->list(clientSocket);
    for (unsigned int  i = 0 ; i< listofGame.size(); i++){
        char buffer[50];
        strcpy(buffer, listofGame[i].c_str());
        write(clientSocket, &buffer, strlen(buffer)+1);
    }
    close(clientSocket);
}
