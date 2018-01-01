
#ifndef EX3_GAMESHANDLER_H
#define EX3_GAMESHANDLER_H

#include <iostream>
#include <string>
#include "GameRoom.h"
#include <map>
using namespace std;

class GamesHandler {
private:
    map <string, GameRoom*> roomMap;
    static pthread_mutex_t lock;
public:
    GamesHandler();
    ~GamesHandler();
    int start (string nameOfGame, int clientSocket);
    vector <string> list(int clientSocket);
};


#endif //EX3_GAMESHANDLER_H
