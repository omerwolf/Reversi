/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_FINAL_GAMEMANAGER_H
#define EX3_FINAL_GAMEMANAGER_H
#include <iostream>
#include "Board.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "RemotePlayerReciver.h"
#include "RemotePlayerSender.h"
#include "ServerConnector.h"
#include "GameLogic.h"
#include <vector>

class GameManager {
protected:
    GameLogic* logic;
    Player* OPlayer, *XPlayer;
public:
    /***********************************************************************
    * function name: GameManager (c'tor)                                   *
    * The input: no Input         										   *
    * The Output: no Output										           *
    * The Function operation: abstract class.                              *
    ***********************************************************************/
    GameManager();
    /***********************************************************************
    * function name: GameLogic (d'tor)                                     *
    * The input: No Input         										   *
    * The Output: no Output										           *
    * The Function operation: virtual d'tor.                               *
    ***********************************************************************/
    virtual ~GameManager();
    /***********************************************************************
    * function name: graphic                                               *
    * The input: No Input         										   *
    * The Output: no Output										           *
    * The Function operation: virtual function that should print the board
    * given the composition choosen.                                       *
    ***********************************************************************/
    virtual void graphic() = 0;
    /***********************************************************************
    * function name: isWinGame                                             *
    * The input: No Input         										   *
    * The Output: bool  										           *
    * The Function operation: ask the logic if someone win the game        *
    ***********************************************************************/
    virtual bool isWinGame();
    /***********************************************************************
    * function name: start                                                 *
    * The input: No Input         										   *
    * The Output: no Output  										       *
    * The Function operation: the flow of the game function depend on the
    * composition.                                                         *
    ***********************************************************************/
    virtual void start ()=0;
};


#endif //EX3_FINAL_GAMEMANAGER_H
