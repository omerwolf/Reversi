/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_FINAL_AIPLAYER_H
#define EX3_FINAL_AIPLAYER_H
#include "Player.h"

/***********************************************************************
* inheritance  from class Player and composition of the pure virtual
* functions.                                                            *
***********************************************************************/

class AIPlayer :
        public Player
{

public:
    explicit AIPlayer(symbol sym);
    ~AIPlayer();
    Cube makeMove(vector <Move> allmoves);
    bool needMove();
};


#endif //EX3_FINAL_AIPLAYER_H
