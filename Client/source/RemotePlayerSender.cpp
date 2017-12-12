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
        try {
            connector->sendMove("NO MOVE");       
        }  catch (const char* msg){
            cout << msg << endl;
        }
    }
    else {
        stringstream str;
        str << cell.x << ", " << cell.y;
        string temp = str.str();
        try {
            connector->sendMove(temp.c_str());
        }  catch (const char* msg){
            cout << msg << endl;
        }
    }
    return cell;
}