/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include <unistd.h>
#include <cstring>
#include "GameRoom.h"
#define MAXSIZE 10

typedef struct twoPlayer{
    int clientSocket1, clientSocket2;
};

GameRoom::GameRoom(){}

GameRoom::~GameRoom(){}

///nt GameRoom::join();

void GameRoom::play(void* game) {
            char init = '1';
            char init2 = '2';
            twoPlayer* temp = (twoPlayer*)game;
            int clientSocket1 = temp->clientSocket1;
            int clientSocket2 = temp->clientSocket2;
            //write color to player1
            int check = write(clientSocket1, &init, sizeof(init));
            if (check == -1){
                throw  "Error writing to socket1" ;
            }
            //write color to player2
            check = write(clientSocket2, &init2, sizeof(init2));
            if (check == -1){
                throw "Error writing to socket2" ;
            }
            while (true) {
                char buffer[MAXSIZE];
                //Player1 move
                int n = read(clientSocket1, buffer, sizeof(buffer));
                if (n == -1) {
                    throw "Error reading the client 1 move" ;

                }
                if (n == 0) {
                    throw "Client 1 disconnected" ;
                }
                n = write(clientSocket2, &buffer, strlen(buffer)+1);
                if (n == -1) {
                    throw "Error writing to socket2" ;
                }
                char buff[MAXSIZE];
                //Player2 move
                n = read(clientSocket2, buff, sizeof(buff));
                if (n == -1) {
                    throw "Error reading the client 2 move" ;
                }
                if (n == 0) {
                    throw "Client 2 disconnected" ;
                }
                n = write(clientSocket1, &buff, strlen(buff)+1);
                if (n == -1) {
                    throw "Error writing to socket1" ;
                }
            }
}


int GameRoom::end(){}

void GameRoom::setClientSocket1(int clientSocket1) {
    GameRoom::clientSocket1 = clientSocket1;
}

void GameRoom::setClientSocket2(int clientSocket2) {
    GameRoom::clientSocket2 = clientSocket2;
}

void GameRoom::setThreadId(int threadId) {
    GameRoom::threadId = threadId;
}

