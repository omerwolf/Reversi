/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_TEST_BOARD_H
#define EX3_TEST_BOARD_H
#include "gtest/gtest.h"
#include "../include/Board.h"
#include "iostream"
using namespace std;

class test_Board:public testing::Test{
public:
    virtual void SetUp() {
        board;
    }


protected:
    Board board;
};

#endif //EX3_TEST_BOARD_H
