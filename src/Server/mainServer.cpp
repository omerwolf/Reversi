
/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/

#include "Server.h"
#include <cstring>
#include <stdlib.h>
#include <fstream>
using namespace std;


int main() {
    ifstream myInfo;
    int port;
    myInfo.open("serverSetting.txt");
    if (myInfo.is_open()) {
        myInfo >> port;
    } else {
        cout << "Unable to open the server/ip file" << endl;
        return -1;
    }
    Server* server = new Server(port);
    try {
        server->start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        server->stop();
        delete server;
        return 0;
    }
}