/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#include "RegularGameLogic.h"
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
    vector <Move> temp = possibleMoves(player);
    setVector(temp, player->getName());
    if (temp.empty())
        return 0;
    else {
        cout << getSym(player->getName()) << ": it's your turn."<<endl;
        if (player->needMove())
            printMoves(player->getName());
        flip(player->getName(), player->makeMove(temp));
        return 1;
    }
}

void RegularGameLogic::flip(symbol sign, Cube cell) {
    cell.value = sign;
    if (canReverseDown(cell.value, cell))
        flipDown(cell);
    if (canReverseUp(cell.value, cell))
        flipUp(cell);
    if (canReverseLeft(cell.value, cell))
        flipLeft(cell);
    if (canReverseRight(cell.value, cell))
        flipRight(cell);
    if (canReverseDownLeft(cell.value, cell))
        flipDownLeft(cell);
    if (canReverseDownRight(cell.value, cell))
        flipDownRight(cell);
    if (canReverseUpLeft(cell.value, cell))
        flipUpLeft(cell);
    if (canReverseUpRight(cell.value, cell))
        flipUpRight(cell);
    board.setBoard(cell.x, cell.y, cell.value);
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