/***********************************************************************
* id: 204380992											               *
* Name : Yoel Jasner												   *
***********************************************************************/
#include "Board.h"
using namespace std;


Board::Board(int newSize) {
    size = newSize;
    board = new Cube*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new Cube[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((i == size / 2 - 1 && j == size / 2 - 1) || (i == size / 2 && j == size / 2)) {
                board[i][j].x = i;
                board[i][j].y = j;
                board[i][j].value = O;
            }
            else if ((i == size / 2 && j == size / 2 - 1) || (i == size / 2 - 1 && j == size / 2)) {
                board[i][j].x = i;
                board[i][j].y = j;
                board[i][j].value = X;
            }
            else {
                board[i][j].value = non;
                board[i][j].x = i;
                board[i][j].y = j;
            }
        }
    }
}

void Board::print() const {
    cout << " ";
    for (int i = 1; i <= size; i++) {
        cout << "| " << i << " ";
    }
    cout << "|";
    Board::printLine();
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "|";
        for (int j = 0; j < size; j++) {
            switch (board[i][j].value) {
                case (X):
                    cout << " X ";
                    break;
                case (O):
                    cout << " O ";
                    break;
                case(non):
                    cout << "   ";
                    break;
            }
            cout << "|";
        }
        Board::printLine();
    }
}

void Board::printLine() const {
    cout << endl << "-";
    for (int i = 0; i < 2 * size + 1; i++)
        cout << " -";
    cout << endl;
}

Board::~Board() {
    for (int i = 0; i < size; i++) {
        delete[]board[i];
    }
    delete[]board;
}

void Board::setBoard(int i, int j, symbol value) {
    board[i][j].value = value;
}

Board& Board::operator=(const Board &temp) {
    size = temp.getSize();
    board = new Cube*[size];
    for (int i = 0; i < size; i++) {
        board[i] = new Cube[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j].x = temp.board[i][j].x;
            board[i][j].y = temp.board[i][j].y;
            board[i][j].value = temp.board[i][j].value;
        }
    }
}