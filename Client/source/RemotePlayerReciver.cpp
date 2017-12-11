/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "../include/RemotePlayerReciver.h"
using namespace std;

RemotePlayerReciver::RemotePlayerReciver(symbol name,ServerConnector * connector) :
        Player(name), connector(connector) {
    recursiveSuggestedTurn = 1;
}

RemotePlayerReciver::~RemotePlayerReciver() {
    delete connector;
}

Cube RemotePlayerReciver::makeMove(vector<Move> temp) {
    char* ptr =connector->getMove();
    Cube cell;
    if (!strcmp(ptr, "NO MOVE")){
        cell.x = -1;
        cell.y = -1;
        cell.value = non;
        return cell;
    }
    else if (!strcmp(ptr, "END")) {
        cell.x = -2;
        cell.y = -2;
        cell.value = non;
        return cell;
    }
    else {
        cell.x = ptr[0];
        cell.y = ptr[3];
        cell.value = non;
        return cell;
    }
}






