/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#ifndef EX3_FINAL_AIPLAYER_H
#define EX3_FINAL_AIPLAYER_H
#include "Player.h"
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
