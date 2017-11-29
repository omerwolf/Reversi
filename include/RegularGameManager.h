//
// Created by yoel on 26/11/17.
//

#ifndef EX3_FINAL_REGULARGAMEMANAGER_H
#define EX3_FINAL_REGULARGAMEMANAGER_H
#include "GameManager.h"

class RegularGameManager : public GameManager {
public:
    explicit RegularGameManager(GameLogic* log);
    ~RegularGameManager();
    void graphic();
    Player* menu();
    void start();
};


#endif //EX3_FINAL_REGULARGAMEMANAGER_H
