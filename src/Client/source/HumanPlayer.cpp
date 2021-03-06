/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include <limits>
#include <iosfwd>
#include "../include/HumanPlayer.h"
#include <iostream>
using namespace std;


HumanPlayer::HumanPlayer(symbol num) : Player(num)
{
    recursiveSuggestedTurn = 1;
    count=0;
}

HumanPlayer::~HumanPlayer()
{
}

Cube HumanPlayer::makeMove(vector <Move> allmoves) {
    Cube cell;
    if (allmoves.empty()){
        cell.value = non;
        cell.x = -1;
        cell.y = -1;
        return cell;
    }
    else {
        do {
            cout << "Please enter your move row col (for example: 2 5): ";
            while (true) {
                cin >> cell.x >> cell.y;
                if (!cin.fail()) {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                    break;
                }
                cout << "Please enter numbers only." << endl;
                cin.clear(); // reset fail bit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            }
            cell.x--;
            cell.y--;
            cell.value = getName();
            if (!isLegal(allmoves, cell))
                cout << "Not legal move." << endl;
        } while (!isLegal(allmoves, cell));
        return cell;
    }
}

bool HumanPlayer::needMove() {
    return true;
}