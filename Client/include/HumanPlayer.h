/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_FINAL_HUMANPLAYER_H
#define EX3_FINAL_HUMANPLAYER_H
#include "Player.h"


/***********************************************************************
* inheritance  from class Player and composition of the pure virtual
* functions.                                                            *
***********************************************************************/

class HumanPlayer :
        public Player
{
public:
    explicit HumanPlayer(symbol num);
    ~HumanPlayer();
    Cube makeMove(vector <Move> move);
    bool needMove();
};


#endif //EX3_FINAL_HUMANPLAYER_H
