/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_FINAL_GAMELOGIC_H
#define EX3_FINAL_GAMELOGIC_H

#include "Board.h"
#include "Player.h"

class GameLogic {
protected:
    Board board;
    vector <Move> XMoves, OMoves;
    virtual void printWinner();
    virtual int countBoard(symbol sign);
    virtual void printMoves(symbol sign);
    void flipDown(Cube& cell);
    void flipUp(Cube& cell);
    void flipRight(Cube& cell);
    void flipLeft(Cube& cell);
    void flipDownLeft(Cube& cell);
    void flipUpRight(Cube& cell);
    void flipDownRight(Cube& cell);
    void flipUpLeft(Cube& cell);
    virtual bool canReverseUp(symbol sign, const Cube& move);
    virtual bool canReverseDown(symbol sign, const Cube& move);
    virtual bool canReverseRight(symbol sign, const Cube& move);
    virtual bool canReverseLeft(symbol sign, const Cube& move);
    virtual bool canReverseUpLeft(symbol sign, const Cube& move);
    virtual bool canReverseDownLeft(symbol sign, const Cube& move);
    virtual bool canReverseUpRight(symbol sign, const Cube& move);
    virtual bool canReverseDownRight(symbol sign, const Cube& move);
    virtual vector <Move> getVector(symbol sign);
    virtual void setVector(vector<Move> temp, symbol sign);

public:
    explicit GameLogic(int size = 8);
    virtual ~GameLogic();
    virtual void display(){board.print();};
    virtual int playTurn(Player* player)=0;
    virtual vector <Move> possibleMoves(Player* player)=0;
    virtual bool isWin()=0;
};


#endif //EX3_FINAL_GAMELOGIC_H
