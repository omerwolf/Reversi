/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "test_HumanPlayer.h"
#include "test_AIPlayer.h"
#include "test_Board.h"
#include "test_RegularGameLogic.h"
#include "gtest/gtest.h"
using namespace std;

GTEST_API_ int main(int argc,char** argv ){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}