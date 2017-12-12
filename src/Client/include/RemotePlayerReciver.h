/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_REMOTEPLAYER_H
#define EX3_REMOTEPLAYER_H
#include "Player.h"
#include "ServerConnector.h"
#include "string.h"


/***********************************************************************
* inheritance from class Player and composition of the pure virtual
* functions.                                                            *
***********************************************************************/
class RemotePlayerReciver : public Player{
private:
    ServerConnector* connector;
public:
    /***********************************************************************
    * function name: RemotePlayerReciver (con's)					       *
    * The input: symbol(enum), ServerConnector*		  					   *
    * The Output: No Output											       *
    * The Function operation: initialized the ServerConnector in order to
    * read right from the socket, and the symbol of the player.            *
    ***********************************************************************/
    RemotePlayerReciver (symbol name, ServerConnector* connector);
    /***********************************************************************
    * function name: RemotePlayerReciver (d'str)					       *
    * The input: No Input                   		  					   *
    * The Output: No Output											       *
    * The Function operation: no need to delete the pointer of
    * ServerConnector since the same address is deleted when the game is
    * over on behalf of the RemotePlayerSender.                            *
    ***********************************************************************/
    ~RemotePlayerReciver();
    bool needMove() {return false;};
    /***********************************************************************
    * function name: makeMove                   					       *
    * The input: vector <Move>                   		  				   *
    * The Output: Cube  											       *
    * The Function operation: use the connector to the server and read
    * from the socket pass it to char* and convert it to a cube with flags
    * if needed.                                                           *
    ***********************************************************************/
    Cube makeMove(vector <Move> temp);
};


#endif //EX3_REMOTEPLAYER_H
