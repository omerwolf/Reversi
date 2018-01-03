/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/

#include <cstring>
#include <unistd.h>
#include "ListCommand.h"

void ListCommand::execute(GamesHandler *master, string nameOfGame, int clientSocket) {
    vector <string> listofGame = master->list(clientSocket);
    char buffer[50];
    int num = listofGame.size();
    int n = write(clientSocket, &num, sizeof(num));
    for (vector <string>::iterator iter = listofGame.begin() ; iter != listofGame.end(); iter++){
        num = iter->size();
        int n = write(clientSocket, &num, sizeof(num));
        if (n == -1){
            cout << "Error in writing to socket" << endl;
        }
        n = write(clientSocket, iter->c_str(), num+1);
        if (n == -1){
            cout << "Error in writing to socket" << endl;
        }
    }
    close(clientSocket);
}
