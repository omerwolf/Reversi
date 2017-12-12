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
    myInfo.open("port_ip.txt");
    if (myInfo.is_open()) {
        myInfo >> port;
    } else {
        cout << "Unable to open the server/ip file" << endl;
    }
    Server server(port);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        server.stop();
        return 0;
    }
}
