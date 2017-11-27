/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#ifndef EX3_FINAL_HUMANPLAYER_H
#define EX3_FINAL_HUMANPLAYER_H
#include "Player.h"


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
