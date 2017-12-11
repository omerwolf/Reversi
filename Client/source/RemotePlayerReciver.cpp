/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "../include/RemotePlayerReciver.h"
using namespace std;

RemotePlayerReciver::RemotePlayerReciver(symbol name,ServerConnector * connector) :
        Player(name), connector(connector) {
}

RemotePlayerReciver::~RemotePlayerReciver() {
    delete connector;
}






