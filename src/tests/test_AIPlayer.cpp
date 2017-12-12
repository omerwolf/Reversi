/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "test_AIPlayer.h"
using namespace std;

TEST_F(test_AIPlayer, getName){
    EXPECT_EQ(Oplayer->getName(), O);
    EXPECT_NE(Oplayer->getName(), X);
}

TEST_F(test_AIPlayer, ifNeedMove){
    EXPECT_FALSE(Oplayer->needMove());
}

TEST_F(test_AIPlayer, getRecuressive){
    EXPECT_EQ(Oplayer->getRecusreSuggestionTurn(), 2);
    EXPECT_NE(Oplayer->getRecusreSuggestionTurn(), 1);
}

TEST_F(test_AIPlayer, makeMove){
    EXPECT_EQ(Oplayer->makeMove(logic->possibleMoves(Oplayer)).x,5 );
    EXPECT_EQ(Oplayer->makeMove(logic->possibleMoves(Oplayer)).y,3 );
}


