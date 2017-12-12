/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "test_RegularGameLogic.h"
using namespace std;


TEST_F(test_RegularGameLogic, isWin){
    EXPECT_TRUE(logic->isWin());   //return TRUE because the game goes with do while loop so don't computing the possible moves for each player
}

TEST_F(test_RegularGameLogic, possibleMoves){
    EXPECT_FALSE(logic->possibleMoves(playerX).empty());
    EXPECT_EQ(logic->possibleMoves(playerX).begin()->cell.x, 2);
    EXPECT_EQ(logic->possibleMoves(playerX).begin()->cell.y, 3);
}

TEST_F(test_RegularGameLogic, playTurn){
    EXPECT_EQ(logic->playTurn(playerX), 1);  //need to enter a move manually.
}
