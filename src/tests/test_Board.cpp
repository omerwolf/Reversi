/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "test_Board.h"
using namespace std;

TEST_F(test_Board, getValue){
    EXPECT_EQ(board.getBoard(3,3), O);
    EXPECT_EQ(board.getBoard(4,4), O);
    EXPECT_EQ(board.getBoard(3,4), X);
    EXPECT_EQ(board.getBoard(4,3), X);
    EXPECT_EQ(board.getBoard(1,4), non);
}

TEST_F(test_Board, getSize){
    EXPECT_EQ(board.getSize(), 8);
    EXPECT_NE(board.getSize(), 9);
}

