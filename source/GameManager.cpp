/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#include "../include/GameManager.h"
using namespace std;

GameManager::GameManager(){

}

GameManager::~GameManager(){

}

bool GameManager::isWinGame(){
    return(logic->isWin());
}
