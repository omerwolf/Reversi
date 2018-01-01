#include <unistd.h>
#include "GamesHandler.h"
typedef enum result {failure, succsses};
pthread_mutex_t GamesHandler::lock;

int GamesHandler::start(string nameOfGame, int clientSocket) {
    GameRoom* room = new GameRoom();
    room->setClientSocket1(clientSocket);
    if (roomMap.find(nameOfGame) == roomMap.end()){
        pthread_mutex_lock(&lock);
        if (roomMap.find(nameOfGame) == roomMap.end()) {
            roomMap.insert(std::pair<string, GameRoom *>(nameOfGame, room));
        }
        pthread_mutex_unlock(&lock);
        return succsses;
    }
    else {
        delete room;
        close(clientSocket);
    }
    return failure;
}

vector<string> GamesHandler::list(int clientSocket) {
    vector <string> listOfGame;
    map <string, GameRoom*>::iterator iter;
    for (iter = roomMap.begin() ; iter != roomMap.end(); iter++){
        listOfGame.push_back(iter->first);
    }
    return listOfGame;
}
