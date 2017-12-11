/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_REMOTEPLAYER_H
#define EX3_REMOTEPLAYER_H
#include "Player.h"
#include "ServerConnector.h"
#include "string.h"

class RemotePlayerReciver : public Player{
private:
    ServerConnector* connector;
public:
    RemotePlayerReciver (symbol name, ServerConnector* connector);
    ~RemotePlayerReciver();
    bool needMove() {return false;};
    Cube makeMove(vector <Move> temp);
};


#endif //EX3_REMOTEPLAYER_H
