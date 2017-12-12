/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_FINAL_GAMELOGIC_H
#define EX3_FINAL_GAMELOGIC_H

#include "Board.h"
#include "Player.h"

class GameLogic {
protected:
    Board board;
    vector <Move> XMoves, OMoves;
    /***********************************************************************
    * function name: printWinner                                           *
    * The input: No Input       		 							       *
    * The Output: No output     										   *
    * The Function operation: print the winner of the game.                *
    ***********************************************************************/
    virtual void printWinner();
    /***********************************************************************
    * function name: countBoard                                            *
    * The input: symbol (enum)  		 							       *
    * The Output: int           										   *
    * The Function operation: given a player symbol return the number of
    * the points he have.                                                  *
    ***********************************************************************/
    virtual int countBoard(symbol sign);
    /***********************************************************************
    * function name: printMoves                                            *
    * The input: symbol (enum)  		 							       *
    * The Output: No output     										   *
    * The Function operation: print all the possible move of the player.   *
    ***********************************************************************/
    virtual void printMoves(symbol sign);
    /***********************************************************************
    * function name: flip****                                              *
    * The input: Cube&                          		 			       *
    * The Output: No output            									   *
    * The Function operation: flip on the direction until the first cube
    * with the same symbol.                                                *
    ***********************************************************************/
    virtual void flip(symbol sign, Cube cell);
    void flipDown(Cube& cell);
    void flipUp(Cube& cell);
    void flipRight(Cube& cell);
    void flipLeft(Cube& cell);
    void flipDownLeft(Cube& cell);
    void flipUpRight(Cube& cell);
    void flipDownRight(Cube& cell);
    void flipUpLeft(Cube& cell);
    /***********************************************************************
    * function name: canReverse****                                        *
    * The input: Cube& and symbol                         		 		   *
    * The Output: bool              									   *
    * The Function operation: check if we can reverse cube on the direction
    * using conditional while until the limits of the board.               *
    ***********************************************************************/
    virtual bool canReverseUp(symbol sign, const Cube& move);
    virtual bool canReverseDown(symbol sign, const Cube& move);
    virtual bool canReverseRight(symbol sign, const Cube& move);
    virtual bool canReverseLeft(symbol sign, const Cube& move);
    virtual bool canReverseUpLeft(symbol sign, const Cube& move);
    virtual bool canReverseDownLeft(symbol sign, const Cube& move);
    virtual bool canReverseUpRight(symbol sign, const Cube& move);
    virtual bool canReverseDownRight(symbol sign, const Cube& move);
    virtual vector <Move> getVector(symbol sign);
    /***********************************************************************
    * function name: setVector                                             *
    * The input: vector <Move> and symbol                          		   *
    * The Output: no Output              								   *
    * The Function operation: copy the vector to the right member of logic.*
    ***********************************************************************/
    virtual void setVector(vector<Move> temp, symbol sign);
public:
    /***********************************************************************
    * function name: GameLogic (con's)                                     *
    * The input: int (default 8)  										   *
    * The Output: no Output										           *
    * The Function operation: pass the size of board to the board con's.   *
    ***********************************************************************/
    explicit GameLogic(int size = 8);
    /***********************************************************************
    * function name: GameLogic (d'tor)                                     *
    * The input: No input		 										   *
    * The Output: no Output										           *
    * The Function operation: do nothing (virtual d'ton).                  *
    ***********************************************************************/
    virtual ~GameLogic();
    /***********************************************************************
   * function name: display                                                *
   * The input: No input		 										   *
   * The Output: no Output										           *
   * The Function operation: call the print function of board.             *
   ***********************************************************************/
    virtual void display(){board.print();};
    /***********************************************************************
    * function name: playTurn                                              *
    * The input: pointer to Player		 							       *
    * The Output: int										               *
    * The Function operation: call the turn function of the player and
    * return 0 if nothing was  flipped or 1 if there was a flip.           *
    ***********************************************************************/
    virtual int playTurn(Player* player)=0;
    /***********************************************************************
    * function name: possblieMoves                                         *
    * The input: pointer to Player		 							       *
    * The Output: vector of Move										   *
    * The Function operation: given a player return all is possible move.  *
    ***********************************************************************/
    virtual vector <Move> possibleMoves(Player* player)=0;
    /***********************************************************************
    * function name: isWin                                                 *
    * The input: No Input		 	        						       *
    * The Output: bool          										   *
    * The Function operation: decide if someone has win the game.          *
    ***********************************************************************/
    virtual bool isWin()=0;
};


#endif //EX3_FINAL_GAMELOGIC_H
