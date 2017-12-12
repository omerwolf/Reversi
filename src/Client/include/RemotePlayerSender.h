/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_REMOTEPLAYERSENDER_H
#define EX3_REMOTEPLAYERSENDER_H

#include "HumanPlayer.h"
#include "ServerConnector.h"
/***********************************************************************
* inheritance from class HumanPlayer and composition of the pure virtual
* functions.                                                            *
***********************************************************************/
class RemotePlayerSender: public HumanPlayer{
private:
    ServerConnector* connector;
public:
    /***********************************************************************
    * function name: RemotePlayerSender (con's)					           *
    * The input: symbol(enum), ServerConnector*		  					   *
    * The Output: No Output											       *
    * The Function operation: initialized the ServerConnector in order to
    * read right from the socket, and the symbol of the player.            *
    ***********************************************************************/
    RemotePlayerSender(symbol sym, ServerConnector* connector);
    /***********************************************************************
    * function name: RemotePlayerSender (d'str)					           *
    * The input: No Input                   		  					   *
    * The Output: No Output											       *
    * The Function operation: delete the pointer of ServerConnector.       *
    ***********************************************************************/
    ~RemotePlayerSender();
    /***********************************************************************
    * function name: RemotePlayerSender     					           *
    * The input: vector <Move>                   		  				   *
    * The Output: Cube  											       *
    * The Function operation: write to the socket with the connector and,
    * using. HumanPlayer func "makeMove" explicitly and convert the cube
    * to cell.                                                             *
    ***********************************************************************/
    Cube makeMove(vector <Move> move);
};


#endif //EX3_REMOTEPLAYERSENDER_H
