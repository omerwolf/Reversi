/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "../include/RemotePlayer.h"
using namespace std;

RemotePlayer::RemotePlayer(symbol name, int size, GameLogic* receivingLogic) :
        Player(name), logic(receivingLogic) {
    recursiveSuggestedTurn =1;
    count= 0;
}

RemotePlayer::~RemotePlayer() {
    delete logic;
}

void RemotePlayer::moveOpponent(Cube cell) {
    logic->flip(cell.value, cell);
}

