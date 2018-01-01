//
// Created by yoel on 01/01/18.
//

#ifndef EX3_GAMEROOM_H
#define EX3_GAMEROOM_H
#include <iostream>
#include "stdlib.h"
#include <string>
#include <vector>
#include <pthread.h>

class GameRoom {
private:
    int clientSocket1, clientSocket2;
    int threadId;
public:
    GameRoom();
    ~GameRoom();
    int join();
    void play(void* game);
    int end();

    void setClientSocket1(int clientSocket1);

    void setClientSocket2(int clientSocket2);

    void setThreadId(int threadId);
};


#endif //EX3_GAMEROOM_H
