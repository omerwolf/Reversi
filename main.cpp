/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#include <iostream>
#include "GameManager.h"
#include "RegularGameManager.h"
#include "RegularGameLogic.h"

using namespace std;

int main() {
    GameLogic* logic = new RegularGameLogic();
    GameManager* GM = new RegularGameManager(logic);
    GM->start();
    return 0;
}