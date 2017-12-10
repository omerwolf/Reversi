/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_FINAL_BOARD_H
#define EX3_FINAL_BOARD_H
#include <iostream>
typedef enum  { non, X, O } symbol;

typedef struct Cube
{
    int x, y;
    symbol value;
}Cube;

class Board {
private:
    Cube** board;
    int size;
    /***********************************************************************
    * function name: printLine	                                           *
    * The input: no Input												   *
    * The Output: no Output										           *
    * The Function operation: print a line the seperate the line on the
    board.	example "--------"											   *
    ***********************************************************************/
    void printLine() const;
public:
    /***********************************************************************
    * function name: Board (con's)                                         *
    * The input: int (default 8)  										   *
    * The Output: no Output										           *
    * The Function operation: initialized the game board to the first move.*
    ***********************************************************************/
    explicit Board(int size = 8);
    /***********************************************************************
    * function name: Board operator =(overloading)                         *
    * The input: const Board & (by refernce)  							   *
    * The Output: no Output										           *
    * The Function operation: copy the board.                              *
    ***********************************************************************/
    Board& operator= (const Board& board);
    /***********************************************************************
    * function name: getSize	                                           *
    * The input: no Input												   *
    * The Output: int											           *
    * The Function operation: return the size of the board.				   *
    ***********************************************************************/
    int getSize()const { return size; };
    /***********************************************************************
    * function name: print		                                           *
    * The input: no Input												   *
    * The Output: no Output										           *
    * The Function operation: print the game board with a nested loop and
    a switch case.														   *
    ***********************************************************************/
    void print() const;
    /***********************************************************************
    * function name: setBoard	                                           *
    * The input: three int(two coordinates, one value)					   *
    * The Output: no Output										           *
    * The Function operation: given coordinates of the board and a value,
    set the board at the cordinates to the value.						   *
    ***********************************************************************/
    void setBoard(int i, int j, symbol value);
    /***********************************************************************
    * function name: getBoard											   *
    * The Input: Two int											       *
    * The Output: int											           *
    * The Function operation: given coordinates of the board, return the
      value on board.													   *
    ***********************************************************************/
    symbol getBoard(int i, int j) { return board[i][j].value; };
    /***********************************************************************
    * function name: Board (d'tor)                                         *
    * The input: No input		 										   *
    * The Output: no Output										           *
    * The Function operation: delete the game board with a nested loop.    *
    ***********************************************************************/
    ~Board();
};

#endif //EX3_FINAL_BOARD_H
