/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
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
public:
    explicit RegularGameLogic(int size = 8);
    ~RegularGameLogic();
    bool isWin();
    vector <Move> possibleMoves(Player* player);
    int playTurn(Player* player);
    void flip(symbol sign, Cube cell);
};


#endif //EX3_FINAL_REGULARGAMELOGIC_H
