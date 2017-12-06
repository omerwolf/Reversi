/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_REMOTEPLAYER_H
#define EX3_REMOTEPLAYER_H
#include "Player.h"
#include "GameLogic.h"

class RemotePlayer : public Player{
private:
    GameLogic* logic;
public:
    RemotePlayer (symbol name, int size, GameLogic* receivingLogic);
    ~RemotePlayer();
    void moveOpponent(Cube cell);
};


#endif //EX3_REMOTEPLAYER_H
