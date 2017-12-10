/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_FINAL_REGULARGAMEMANAGER_H
#define EX3_FINAL_REGULARGAMEMANAGER_H
#include "GameManager.h"
/***********************************************************************
* inheritance  from class GameManager and composition of the pure virtual
* functions. regular game between to player given the option to choose
* each player play one turn at the time.                               *
***********************************************************************/

class RegularGameManager : public GameManager {
private:
    int menu();
public:
    explicit RegularGameManager(GameLogic* log);
    ~RegularGameManager();
    void graphic();
    void start();
};


#endif //EX3_FINAL_REGULARGAMEMANAGER_H
