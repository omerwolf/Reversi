/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_REMOTEPLAYERSENDER_H
#define EX3_REMOTEPLAYERSENDER_H

#include "HumanPlayer.h"
#include "ServerConnector.h"

class RemotePlayerSender: public HumanPlayer{
private:
    ServerConnector* connector;
public:
    RemotePlayerSender(symbol sym, ServerConnector* connector);
    ~RemotePlayerSender();
    Cube makeMove(vector <Move> move);
};


#endif //EX3_REMOTEPLAYERSENDER_H
