#include <unistd.h>
#include "GamesHandler.h"
using namespace std;
typedef enum result {failure, succsses};
pthread_mutex_t GamesHandler::lock;

GamesHandler::~GamesHandler(){
    if (!roomMap.empty()){
        for (map<string, GameRoom *>::iterator iter = roomMap.begin(); iter != roomMap.end(); ++iter) {
            if (roomMap.find(iter->first) != roomMap.end()) {
                roomMap[iter->first]->end();
                pthread_mutex_lock(&lock);
                roomMap.erase(iter->first);
                pthread_mutex_unlock(&lock);
            }
        }
    }
}

int GamesHandler::start(string nameOfGame, int clientSocket) {
    GameRoom* room;
    room = new GameRoom();
    room->setClientSocket1(clientSocket);
    if (roomMap.find(nameOfGame) == roomMap.end()){
        pthread_mutex_lock(&lock);
        if (roomMap.find(nameOfGame) == roomMap.end()) {
            roomMap.insert(pair<string, GameRoom *>(nameOfGame, room));
            roomMap[nameOfGame]->increaseCounter();
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
        if (iter->second->getCounter() == 1) {
            listOfGame.push_back(iter->first);
        }
    }
    if (listOfGame.empty()){
        listOfGame.push_back("no game available");
    }
    return listOfGame;
}

int GamesHandler::join(string nameOfGame, int clientSocket) {
    if (roomMap.find(nameOfGame) != roomMap.end()){
        pthread_mutex_lock(&lock);
        if (roomMap.find((nameOfGame)) != roomMap.end() && roomMap[nameOfGame]->getCounter() == 1){
            roomMap[nameOfGame]->increaseCounter();
            roomMap[nameOfGame]->setClientSocket2(clientSocket);
        }
        pthread_mutex_unlock(&lock);
        try {
            roomMap[nameOfGame]->play();
        } catch (const char* msg){
            cout<< msg <<endl;
        }
        return end(nameOfGame);
    }
    else{
        close(clientSocket);
        return 0;
    }
}

int GamesHandler::end(string nameOfGame){
    if (roomMap.find(nameOfGame) != roomMap.end()){
        roomMap[nameOfGame]->end();
        pthread_mutex_lock(&lock);
        roomMap.erase(nameOfGame);
        pthread_mutex_unlock(&lock);
        return 1;
    }
    else
        return 0;
}
