/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "../include/RegularGameLogic.h"
using namespace std;

RegularGameLogic::RegularGameLogic(int size) : GameLogic(size){

}

RegularGameLogic::~RegularGameLogic() {

}

bool RegularGameLogic::isWin() {
    if ((XMoves.empty()) && (OMoves.empty())) {
        printWinner();
        return true;
    }
    return false;
}

char RegularGameLogic::getSym(symbol sym) {
    if (sym == X)
        return 'X';
    else if (sym == O)
        return 'O';

}

int RegularGameLogic::playTurn(Player *player) {
    Cube cell;
    vector <Move> temp = possibleMoves(player);
    setVector(temp, player->getName());
    if (player->needMove()) {
        cout << getSym(player->getName()) << ": it's your turn." << endl;
        printMoves(player->getName());
    }
    cell = player->makeMove(temp);
    if (cell.x == -1 && cell.y == -1) {
        cout << getSym(player->getName()) << " You have no legal Move." <<endl;
        return -1;
    }
    else if (cell.x == -2 && cell.y == -2) {
        cout << getSym(player->getName()) << " Game is finished." <<endl;
        return -2;
    }
    else {
        cout << getSym(player->getName()) << " Played " << "(" << cell.x+1 << "," << cell.y+1 << ")" <<endl;
        flip(player->getName(), cell);
        setVector(lowPossibleMoves(X), X);
        setVector(lowPossibleMoves(O), O);
    }
    return 1;
}


vector <Move> RegularGameLogic::lowPossibleMoves(symbol sign) {
    vector <Move> vecTemp;
    Move temp;
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            temp.cell.x = i;
            temp.cell.y = j;
            if (canReverseDownRight(sign, temp.cell) || canReverseUp(sign, temp.cell) ||
                canReverseDown(sign, temp.cell) || canReverseRight(sign, temp.cell) ||
                canReverseLeft(sign, temp.cell) || canReverseDownLeft(sign, temp.cell) ||
                canReverseUpRight(sign, temp.cell) || canReverseUpLeft(sign, temp.cell)) {
                vecTemp.push_back(temp);
            }
        }
    }
    return vecTemp;
}


int RegularGameLogic::gradeMove(symbol sign){
    int XCount, OCount,grade;
    if (sign == X) {
        XCount = countBoard(sign);
        OCount = countBoard(O);
        grade = XCount - OCount;
    }
    else if (sign == O){
        XCount = countBoard(sign);
        OCount = countBoard(X);
        grade = OCount - XCount;
    }
    return grade;
}

vector <Move> RegularGameLogic::possibleMoves(Player* player) {
    vector <Move> temp;
    if (player->getRecusreSuggestionTurn() == 1){
        return lowPossibleMoves(player->getName());
    }
    else if (player->getRecusreSuggestionTurn() == 2)
        return deepPossibleMoves(player->getName());
}

vector <Move> RegularGameLogic::deepPossibleMoves(symbol sign){
    vector <Move> low = lowPossibleMoves(sign);
    vector <Move> deep, temp, low2;
    for (vector <Move> ::iterator iter = low.begin(); iter != low.end(); iter++) {
        if (sign == O) {
            RegularGameLogic* tempBoard = new RegularGameLogic(board.getSize());
            tempBoard->board = this->board;
            tempBoard->flip(sign,iter->cell);
            low2 = tempBoard->lowPossibleMoves(X);
            for (vector <Move> ::iterator iter = low2.begin(); iter != low2.end(); iter++){
                RegularGameLogic* tempBoard2 = new RegularGameLogic(board.getSize());
                tempBoard2->board = tempBoard->board;
                tempBoard2->flip(X, (*iter).cell);
                iter->grade = tempBoard2->gradeMove(X);
                delete tempBoard2;
            }
            if (low2.empty()){
                iter->grade= tempBoard->countBoard(X);
            }
            else
                iter->grade = findMax(low2).grade;
            delete tempBoard;
        }
        else if (sign == X){
            RegularGameLogic* tempBoard = new RegularGameLogic(board.getSize());
            tempBoard->board = this->board;
            tempBoard->flip(sign,iter->cell);
            low2 = tempBoard->lowPossibleMoves(O);
            for (vector <Move> ::iterator iter = low2.begin(); iter != low2.end(); iter++){
                RegularGameLogic* tempBoard2 = new RegularGameLogic(board.getSize());
                tempBoard2->board = tempBoard->board;
                tempBoard2->flip(O, (*iter).cell);
                iter->grade = tempBoard2->gradeMove(O);
                delete tempBoard2;
            }
            if (low2.empty()){
                iter->grade= tempBoard->countBoard(O);
            }
            else
                iter->grade = findMax(low2).grade;
            delete tempBoard;
        }
    }
    return low;
}

Move RegularGameLogic::findMax(vector <Move> temp) {
    Move move;
    move.cell.x = temp.begin()->cell.x;
    move.cell.y = temp.begin()->cell.y;
    move.grade = temp.begin()->grade;
    for (vector<Move>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
        if (iter->grade >= move.grade){
            move.cell.x = iter->cell.x;
            move.cell.y = iter->cell.y;
            move.grade = iter->grade;
        }
    }
    return move;
}