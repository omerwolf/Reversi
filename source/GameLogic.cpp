/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#include "../include/GameLogic.h"
using namespace std;

GameLogic::GameLogic(int size) : board(size) {

}

GameLogic::~GameLogic() {

}

void GameLogic::printWinner() {
    int XCount = countBoard(X);
    int OCount = countBoard(O);
    if (XCount > OCount)
        cout << "Congratulation X is the winner"<< endl;
    else if (XCount < OCount)
        cout << "Congratulation O is the winner"<< endl;
    else
        cout << "It's a tie, well done" << endl;
}

int GameLogic::countBoard(symbol sign) {
    int counter=0;
    for (int i = 0; i < board.getSize(); i++) {
        for (int j = 0; j < board.getSize(); j++) {
            if (board.getBoard(i, j) == sign) {
                counter++;
            }
        }
    }
    return counter;
}

void GameLogic::printMoves(symbol sign) {
    cout << "Your posible moves:";
    if (sign == X) {
        for (vector<Move>::iterator temp = XMoves.begin(); temp != XMoves.end(); temp++) {
            cout << "(" << temp->cell.x+ 1 << ", " << temp->cell.y + 1 << ") ";
        }
    }
    else if (sign ==O) {
        for (vector<Move>::iterator temp = OMoves.begin(); temp != OMoves.end(); temp++) {
            cout << "(" << temp->cell.x + 1 << ", " << temp->cell.y + 1 << ") ";
        }
    }
    cout << endl;
}

vector <Move> GameLogic::getVector(symbol sign){
    if (sign ==  X){
        return XMoves;
    }
    else if (sign ==O){
        return OMoves;
    }
}

void GameLogic::setVector(vector<Move> temp, symbol sign){
    if (sign ==  X){
        XMoves = temp;
    }
    else if (sign ==O){
        OMoves =temp;
    }
}

void GameLogic::flipDown(Cube& cell) {
    int i = 1;
    while (board.getBoard(cell.x + i, cell.y) != cell.value) {
        board.setBoard(cell.x + i, cell.y, cell.value);
        i++;
    }
}

void GameLogic::flipUp(Cube& cell) {
    int i = 1;
    while (board.getBoard(cell.x - i, cell.y) != cell.value) {
        board.setBoard(cell.x - i, cell.y, cell.value);
        i++;
    }
}

void GameLogic::flipRight(Cube& cell) {
    int i = 1;
    while (board.getBoard(cell.x , cell.y+i) != cell.value) {
        board.setBoard(cell.x , cell.y+i, cell.value);
        i++;
    }
}

void GameLogic::flipLeft(Cube& cell) {
    int i = 1;
    while (board.getBoard(cell.x, cell.y - i) != cell.value) {
        board.setBoard(cell.x, cell.y - i, cell.value);
        i++;
    }
}

void GameLogic::flipDownLeft(Cube& cell) {
    int i = 1;
    while (board.getBoard(cell.x+i, cell.y - i) != cell.value) {
        board.setBoard(cell.x+i, cell.y - i, cell.value);
        i++;
    }
}

void GameLogic::flipDownRight(Cube& cell) {
    int i = 1;
    while (board.getBoard(cell.x + i, cell.y + i) != cell.value) {
        board.setBoard(cell.x + i, cell.y + i, cell.value);
        i++;
    }
}

void GameLogic::flipUpLeft(Cube& cell) {
    int i = 1;
    while (board.getBoard(cell.x - i, cell.y - i) != cell.value) {
        board.setBoard(cell.x - i, cell.y - i, cell.value);
        i++;
    }
}

void GameLogic::flipUpRight(Cube &cell) {
    int i=1;
    while (board.getBoard(cell.x - i, cell.y + i) != cell.value) {
        board.setBoard(cell.x - i, cell.y + i, cell.value);
        i++;
    }
}

bool GameLogic::canReverseUp(symbol sign, const Cube& move) {
    int counter = 0;
    int i = 0;
    if (sign == X) {
        if (board.getBoard(move.x, move.y) != non || move.x - i == 0)
            return false;
        else {
            while (board.getBoard(move.x - (i + 1), move.y) != X) {
                i++;
                if (board.getBoard(move.x - i, move.y) == non)
                    return false;
                counter++;
                if (move.x - i == 0)
                    return false;
            }

        }
    }
    else {
        if (board.getBoard(move.x, move.y) != non || move.x - i == 0)
            return false;
        else {
            while (board.getBoard(move.x - (i + 1), move.y) != O) {
                i++;
                if (board.getBoard(move.x - i, move.y) == non)
                    return false;
                counter++;
                if (move.x - i == 0)
                    return false;
            }
        }
    }
    if (counter > 0)
        return true;
    return false;
}

bool GameLogic::canReverseDown(symbol sign, const Cube& move) {
    int counter = 0;
    int i = 0;
    if (sign == X) {
        if (board.getBoard(move.x, move.y) != non || move.x + i + 1 == board.getSize())
            return false;
        else {
            while (board.getBoard(move.x + (i + 1), move.y) != X) {
                i++;
                if (board.getBoard(move.x + i, move.y) == non)
                    return false;
                counter++;
                if (move.x + i + 1 == board.getSize())
                    return false;
            }
        }
    }
    else {
        if (board.getBoard(move.x, move.y) != non || move.x + i + 1 == board.getSize())
            return false;
        else {
            while (board.getBoard(move.x + (i + 1), move.y) != O) {
                i++;
                if (board.getBoard(move.x + i, move.y) == non)
                    return false;
                counter++;
                if (move.x + i + 1 == board.getSize())
                    return false;
            }
        }
    }
    if (counter > 0)
        return true;
    return false;
}

bool GameLogic::canReverseRight(symbol sign, const Cube& move) {
    int counter = 0;
    int i = 0;
    if (sign == X) {
        if (board.getBoard(move.x, move.y) != non || move.y + i + 1 == board.getSize())
            return false;
        else {
            while (board.getBoard(move.x, move.y + (i + 1)) != X) {
                i++;
                if (board.getBoard(move.x, move.y + i) == non)
                    return false;
                counter++;
                if (move.y + i + 1 == board.getSize())
                    return false;
            }
        }
    }
    else {
        if (board.getBoard(move.x, move.y) != non || move.y + i + 1 == board.getSize())
            return false;
        else {
            while (board.getBoard(move.x, move.y + (i + 1)) != O) {
                i++;
                if (board.getBoard(move.x, move.y + i) == non)
                    return false;
                counter++;
                if (move.y + i + 1 == board.getSize())
                    return false;
            }
        }
    }
    if (counter > 0)
        return true;
    return false;
}

bool GameLogic::canReverseLeft(symbol sign, const Cube& move) {
    int counter = 0;
    int i = 0;
    if (sign == X) {
        if (board.getBoard(move.x, move.y) != non || move.y - i == 0)
            return false;
        else {
            while (board.getBoard(move.x, move.y - (i + 1)) != X) {
                i++;
                if (board.getBoard(move.x, move.y - i) == non)
                    return false;
                counter++;
                if (move.y - i == 0)
                    return false;
            }
        }
    }
    else {
        if (board.getBoard(move.x, move.y) != non || move.y - i == 0)
            return false;
        else {
            while (board.getBoard(move.x, move.y - (i + 1)) != O) {
                i++;
                if (board.getBoard(move.x, move.y - i) == non)
                    return false;
                counter++;
                if (move.y - i == 0)
                    return false;
            }
        }
    }
    if (counter > 0)
        return true;
    return false;
}

bool GameLogic::canReverseUpLeft(symbol sign, const Cube& move) {
    int counter = 0;
    int i = 0;
    if (sign == X) {
        if (board.getBoard(move.x, move.y) != non || move.y - i == 0 || move.x - i == 0)
            return false;
        else {
            while (board.getBoard(move.x - (i + 1), move.y - (i + 1)) != X) {
                i++;
                if (board.getBoard(move.x - i, move.y - i) == non)
                    return false;
                counter++;
                if (move.y - i == 0 || move.x - i == 0)
                    return false;
            }
        }
    }
    else {
        if (board.getBoard(move.x, move.y) != non || move.y - i == 0 || move.x - i == 0)
            return false;
        else {
            while (board.getBoard(move.x - (i + 1), move.y - (i + 1)) != O) {
                i++;
                if (board.getBoard(move.x - i, move.y - i) == non)
                    return false;
                counter++;
                if (move.y - i == 0 || move.x - i == 0)
                    return false;
            }
        }
    }
    if (counter > 0)
        return true;
    return false;
}

bool GameLogic::canReverseDownLeft(symbol sign, const Cube& move) {
    int counter = 0;
    int i = 0;
    if (sign == X) {
        if (board.getBoard(move.x, move.y) != non || move.y - i == 0 || move.x + i + 1 == board.getSize())
            return false;
        else {
            while (board.getBoard(move.x + (i + 1), move.y - (i + 1)) != X) {
                i++;
                if (board.getBoard(move.x + i, move.y - i) == non)
                    return false;
                counter++;
                if (move.y - i == 0 || move.x + i + 1 == board.getSize())
                    return false;
            }
        }
    }
    else {
        if (board.getBoard(move.x, move.y) != non || move.y - i == 0 || move.x + i + 1 == board.getSize())
            return false;
        else {
            while (board.getBoard(move.x + (i + 1), move.y - (i + 1)) != O) {
                i++;
                if (board.getBoard(move.x + i, move.y - i) == non)
                    return false;
                counter++;
                if (move.y - i == 0 || move.x + i + 1 == board.getSize())
                    return false;
            }
        }
    }
    if (counter > 0)
        return true;
    return false;
}

bool GameLogic::canReverseUpRight(symbol sign, const Cube& move) {
    int counter = 0;
    int i = 0;
    if (sign == X) {
        if (board.getBoard(move.x, move.y) != non || move.y + i + 1 == board.getSize() || move.x - i == 0)
            return false;
        else {
            while (board.getBoard(move.x - (i + 1), move.y + (i + 1)) != X) {
                i++;
                if (board.getBoard(move.x - i, move.y + i) == non)
                    return false;
                counter++;
                if (move.y + i + 1 == board.getSize() || move.x - i == 0)
                    return false;
            }
        }
    }
    else {
        if (board.getBoard(move.x, move.y) != non || move.y + i + 1 == board.getSize() || move.x - i == 0)
            return false;
        else {
            while (board.getBoard(move.x - (i + 1), move.y + (i + 1)) != O) {
                i++;
                if (board.getBoard(move.x - i, move.y + i) == non)
                    return false;
                counter++;
                if (move.y + i + 1 == board.getSize() || move.x - i == 0)
                    return false;
            }
        }
    }
    if (counter > 0)
        return true;
    return false;
}

bool GameLogic::canReverseDownRight(symbol sign, const Cube& move) {
    int counter = 0;
    int i = 0;
    if (sign == X) {
        if (board.getBoard(move.x, move.y) != non || move.y + i + 1 == board.getSize() || move.x + i + 1 == board.getSize())
            return false;
        else {
            while (board.getBoard(move.x + (i + 1), move.y + (i + 1)) != X) {
                i++;
                if (board.getBoard(move.x + i, move.y + i) == non)
                    return false;
                counter++;
                if (move.y + i + 1 == board.getSize() || move.x + i + 1 == board.getSize())
                    return false;
            }
        }
    }
    else {
        if (board.getBoard(move.x, move.y) != non || move.y + i + 1 == board.getSize() || move.x + i + 1 == board.getSize())
            return false;
        else {
            while (board.getBoard(move.x + (i + 1), move.y + (i + 1)) != O) {
                i++;
                if (board.getBoard(move.x + i, move.y + i) == non)
                    return false;
                counter++;
                if (move.y + i + 1 == board.getSize() || move.x + i + 1 == board.getSize())
                    return false;
            }
        }
    }
    if (counter > 0)
        return true;
    return false;
}