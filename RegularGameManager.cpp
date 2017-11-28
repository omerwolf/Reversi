/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#include "RegularGameManager.h"
using namespace std;

RegularGameManager::RegularGameManager(GameLogic* log) {
    logic = log;
    OPlayer = menu();
    XPlayer = new HumanPlayer(X);
}

RegularGameManager::~RegularGameManager() {
    delete OPlayer;
    delete XPlayer;
}

void RegularGameManager::graphic() {
    logic->display();
}

Player* RegularGameManager::menu() {
    int input;
    do  {
        cout << "Choose Player:" << endl;
        cout << "   1.Human Player press 1" << endl;
        cout << "   2.AI Player press 2" << endl;
        cin >> input;
        if (input == 1){
            return(new HumanPlayer(O));
        }
        else if (input == 2){
            return(new AIPlayer(O));
        }
    } while(true);
}

void RegularGameManager::start() {
    graphic();
    do {
        if (logic->playTurn(XPlayer) == 0) {
            cout << "X you have no legal move." << endl;
        }
        else
            graphic();
        if (logic->playTurn(OPlayer) == 0){
            cout << "O you have no legal move." << endl;
        }
        else
            graphic();
    } while (!isWinGame());
}