/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_FINAL_PLAYER_H
#define EX3_FINAL_PLAYER_H
#include <vector>
#include "Board.h"

using namespace std;


struct Move {
    Cube cell;
    int grade;
};

class Player
{
protected:
    int  count, recursiveSuggestedTurn ;
    symbol name;
    virtual bool isLegal(vector <Move>& allmoves, const Cube& move) const;
public:
    /***********************************************************************
    * function name: Board (c'tor)                                         *
    * The input: int		  											   *
    * The Output: no Output										           *
    * The Function operation: initialized the "name" and the counter
      of the Player.                                                       *
    ***********************************************************************/
    explicit Player(symbol sym);
    /***********************************************************************
    * function name: Board (d'tor)                                         *
    * The input: No Input		  										   *
    * The Output: no Output										           *
    * The Function operation: nothing									   *
    ***********************************************************************/
    virtual ~Player();
    /***********************************************************************
    * function name: getName											   *
    * The input: No Input		  										   *
    * The Output: int											           *
    * The Function operation: return the name of the player.			   *
    ***********************************************************************/
    virtual symbol getName() { return name; };
    /***********************************************************************
    * function name: getName											   *
    * The input: No Input		  										   *
    * The Output: int											           *
    * The Function operation: return the number of the pices of the player
    on the board.														   *
    ***********************************************************************/
    virtual int getCount() { return count; };
    /***********************************************************************
    * function name: getName											   *
    * The input: int		  											   *
    * The Output: No Output											       *
    * The Function operation: initialized the counter of the player to the
    value.																   *
    ***********************************************************************/
    virtual void setCount(int num) { count = num; };
    /***********************************************************************
    * function name: getName											   *
    * The input: No Input		  										   *
    * The Output: int											           *
    * The Function operation: return the number of the pices of the player
    on the board.														   *
    ***********************************************************************/
    virtual int getRecusreSuggestionTurn() { return recursiveSuggestedTurn; };
    virtual bool needMove()=0;
    virtual Cube makeMove(vector <Move> move) = 0;
};

#endif //EX3_FINAL_PLAYER_H
