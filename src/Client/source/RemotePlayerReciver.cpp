/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "../include/RemotePlayerReciver.h"
#include "stdlib.h"
using namespace std;

RemotePlayerReciver::RemotePlayerReciver(symbol name,ServerConnector * connector) :
        Player(name), connector(connector) {
    recursiveSuggestedTurn = 1;
}

RemotePlayerReciver::~RemotePlayerReciver() { // deleted when the game is over on
                                              // behalf of the RemotePlayerSender
}

Cube RemotePlayerReciver::makeMove(vector<Move> temp) {
    char* ptr;
    try {
        ptr = connector->getMove();
    } catch (const char* msg){
        cout << msg <<endl;
        ptr = const_cast<char *>("END");
    }
    Cube cell;
    if (!strcmp(ptr, "NO MOVE")){ //special flag
        cell.x = -1;
        cell.y = -1;
        cell.value = non;
        delete ptr;
        return cell;
    }
    else if (!strcmp(ptr, "END")) { //special flag
        cell.x = -2;
        cell.y = -2;
        cell.value = non;
        delete ptr;
        return cell;
    }
    else {
        char temp[2] = "";
        temp[0] = ptr[0];
        cell.x = atoi(temp);
        temp[0] = ptr[3];
        cell.y = atoi(temp);
        cell.value = non;
        delete ptr;
        return cell;
    }
}







