/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "../include/AIPlayer.h"
#include <algorithm>
using namespace std;

AIPlayer::AIPlayer(symbol sym) : Player(sym) {
    recursiveSuggestedTurn = 2;
}


AIPlayer::~AIPlayer()
{
}

Cube AIPlayer::makeMove(vector <Move> allmoves) {
    Move temp = *(allmoves.begin());
    Cube cell;
    if (allmoves.empty()){
        cell.value = non;
        cell.x = -1;
        cell.y = -1;
        return cell;
    }
    else {
        for (vector<Move>::iterator iter = allmoves.begin(); iter != allmoves.end(); iter++) {
            if ((*iter).grade >= temp.grade) {
                temp = *iter;
                cell.x = temp.cell.x;
                cell.y = temp.cell.y;
                cell.value = name;
            }
        }
    }
    return cell;
}

bool AIPlayer::needMove() {
    return false;
}