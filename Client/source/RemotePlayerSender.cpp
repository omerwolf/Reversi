/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "../include/RemotePlayerSender.h"
#include <sstream>

RemotePlayerSender::RemotePlayerSender(symbol sym, ServerConnector* connector) :
        HumanPlayer(sym), connector(connector){
}

RemotePlayerSender::~RemotePlayerSender() {
    delete connector;
}

Cube RemotePlayerSender::makeMove(vector<Move> move)  {
    Cube cell = HumanPlayer::makeMove(move);
    if (cell.x == -1 && cell.y == -1){
        connector->sendMove("NO MOVE");
    }
    else {
        stringstream str;
        str << cell.x << ", " << cell.y;
        string temp = str.str();
        const char* strTemp = temp.c_str();
        connector->sendMove(strTemp);
    }
}