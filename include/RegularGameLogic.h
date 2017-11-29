/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_FINAL_REGULARGAMELOGIC_H
#define EX3_FINAL_REGULARGAMELOGIC_H
#include "GameLogic.h"

class RegularGameLogic :public GameLogic{
private:
    vector <Move> lowPossibleMoves(symbol sign);
    int gradeMove(symbol sign);
    char getSym(symbol sym);
    vector <Move> deepPossibleMoves(symbol sign);
    Move findMax(vector <Move> temp);
    void flip(symbol sign, Cube cell);
public:
    explicit RegularGameLogic(int size = 8);
    ~RegularGameLogic();
    bool isWin();
    vector <Move> possibleMoves(Player* player);
    int playTurn(Player* player);
};


#endif //EX3_FINAL_REGULARGAMELOGIC_H
