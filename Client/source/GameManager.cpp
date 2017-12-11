/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
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
