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
    int clientSocket1, clientSocket2, counter=0;
    pthread_t threadId;

public:
    GameRoom();
    ~GameRoom();
    void play();
    int end();

    void setClientSocket1(int clientSocket1);

    void setClientSocket2(int clientSocket2);
    void increaseCounter() {counter++;};
    int getCounter(){ return counter;};
    void setThreadId(int threadId);
};


#endif //EX3_GAMEROOM_H
