/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_TEST_AIPLAYER_H
#define EX3_TEST_AIPLAYER_H
#include "../include/AIPlayer.h"
#include "../include/RegularGameLogic.h"
#include <gtest/gtest.h>

class test_AIPlayer: public testing::Test {
public:
    virtual void setUp(){
            Oplayer, logic;
    }
    virtual void TearDown(){
        delete Oplayer;
        delete logic;
    }
protected:
    RegularGameLogic* logic = new RegularGameLogic(8);
    AIPlayer* Oplayer = new AIPlayer(O);
};


#endif //EX3_TEST_AIPLAYER_H
