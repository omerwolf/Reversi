/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "../include/RegularGameManager.h"
#include "limits"
#include "stdlib.h"
using namespace std;

RegularGameManager::RegularGameManager(GameLogic* log) {
    logic = log;
    menu();
}

int RegularGameManager::menu() {
    int input;
    do {
        do {
            cout << "Choose Player:" << endl;
            cout << "   1.Human Player press 1" << endl;
            cout << "   2.AI Player press 2" << endl;
            cout << "   3.Remote Player press 3" << endl;
            cin >> input;
            if (!cin.fail()) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                break;
            }
            cout << "Please enter numbers only." << endl;
            cin.clear(); // reset fail bit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        } while (true);
        ServerConnector* connector = new ServerConnector();
        char* str;
        switch (input) {
            case 1:
                OPlayer = new HumanPlayer(O);
                XPlayer = new HumanPlayer(X);
                return 0;
            case 2:
                OPlayer = new AIPlayer(O);
                XPlayer = new HumanPlayer(X);
                return 0;
            case 3:
                connector->connectToServer();
                str = connector->getSign();
                if (!strcmp(str,"1")){
                    OPlayer = new RemotePlayerReciver(O, connector);
                    XPlayer = new RemotePlayerSender(X, connector);
                }
                else {
                    OPlayer = new RemotePlayerSender(O, connector);
                    XPlayer = new RemotePlayerReciver(X, connector);
                }
                delete str;
                return 0;
        }
    } while (true);
}

RegularGameManager::~RegularGameManager() {
    delete OPlayer;
    delete XPlayer;
}

void RegularGameManager::graphic() {
    logic->display();
}

void RegularGameManager::start() {
    graphic();
    do {
        int i = logic->playTurn(XPlayer);
        if (i == 1 || i == -2 ) {
            if (i == 1) {
                graphic();
                if (isWinGame()) {
                    return;
                }
            }
            else {
                return;
            }
        }
        i = logic->playTurn(OPlayer);
        if (i == 1 || i == -2){
            if (i==1) {
                graphic();
            }
            else
                return;
        }
    } while (!isWinGame());
}
