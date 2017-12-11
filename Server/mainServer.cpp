/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/

#include "Server.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;


int main() {
    ifstream myInfo;
    int port;
    myInfo.open("myInfo");
    if (myInfo.is_open()) {
        myInfo >> port;
    } else {
        cout << "Unable to open the server/ip file" << endl;
    }
    Server server(port);
    int mainServer() {
        Server server(8000);
        try {
            server.start();
        } catch (const char *msg) {
            cout << "Cannot start server. Reason: " << msg << endl;
            exit(-1);
        }
    }
}