/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include <iostream>
#include <limits>
#include <iosfwd>
#include "../include/GameManager.h"
#include "../include/RegularGameManager.h"
#include "../include/RegularGameLogic.h"
using namespace std;


int main() {
    GameLogic* logic = new RegularGameLogic(8);
    GameManager* GM = new RegularGameManager(logic);
    GM->start();
    delete logic;
    delete GM;
    return 0;
}