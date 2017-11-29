//
// Created by yoel on 29/11/17.
//

#ifndef EX3_TEST_HUMANPLAYER_H
#define EX3_TEST_HUMANPLAYER_H

#include "../include/HumanPlayer.h"
#include "../include/RegularGameLogic.h"
#include <gtest/gtest.h>

class test_HumanPlayer: public testing::Test {
public:
    virtual void setUp(){
        Xplayer, logic;
    }
    virtual void TearDown(){
        delete Xplayer;
        delete logic;
    }
protected:
    RegularGameLogic* logic = new RegularGameLogic(8);
    HumanPlayer* Xplayer = new HumanPlayer(X);
};

#endif //EX3_TEST_HUMANPLAYER_H
