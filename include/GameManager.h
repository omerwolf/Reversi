/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#ifndef EX3_FINAL_GAMEMANAGER_H
#define EX3_FINAL_GAMEMANAGER_H
#include <iostream>
#include "Board.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "GameLogic.h"
#include <vector>

class GameManager {
protected:
    GameLogic* logic;
    Player* OPlayer, *XPlayer;
public:
    GameManager();
    virtual ~GameManager();
    virtual void graphic() = 0;
    virtual Player* menu()= 0;
    virtual bool isWinGame();
    virtual void start ()=0;
};


#endif //EX3_FINAL_GAMEMANAGER_H
