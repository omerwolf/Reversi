/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_TEST_REGULARGAMELOGIC_H
#define EX3_TEST_REGULARGAMELOGIC_H

#include "../include/RegularGameLogic.h"
#include "../include/HumanPlayer.h"
#include "gtest/gtest.h"

class test_RegularGameLogic :public testing::Test{
public:
    virtual void setUp(){
        logic;
    }
    virtual void TearDown(){
        delete logic;
        delete playerX;
    }
protected:
    RegularGameLogic* logic = new RegularGameLogic(8);
    Player* playerX = new HumanPlayer(X);
};


#endif //EX3_TEST_REGULARGAMELOGIC_H
