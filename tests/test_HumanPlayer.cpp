#include "test_HumanPlayer.h"
using namespace std;

TEST_F(test_HumanPlayer, name){
    EXPECT_EQ(Xplayer->getName(), X);
    EXPECT_NE(Xplayer->getName(), O);
}

TEST_F(test_HumanPlayer, ifNeedMove){
    EXPECT_TRUE(Xplayer->needMove());
}

TEST_F(test_HumanPlayer, getRecuressive){
    EXPECT_EQ(Xplayer->getRecusreSuggestionTurn(), 1);
    EXPECT_NE(Xplayer->getRecusreSuggestionTurn(), 2);
}
