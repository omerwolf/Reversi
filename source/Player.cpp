/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#include "../include/Player.h"
#include <iostream>
using namespace std;


Player::Player(symbol sym) :name(sym)
{
    count = 0;
}

Player::~Player()
{
}

bool Player::isLegal(vector <Move>& allmoves, const Cube& cell) const {
    for (vector <Move>::iterator iter = allmoves.begin(); iter != allmoves.end(); iter++) {
        if ((cell.x == iter->cell.x) && (cell.y == iter->cell.y))
            return true;
    }
    return false;
}