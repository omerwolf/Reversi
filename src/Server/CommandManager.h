/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_COMMANDMANAGER_H
#define EX3_COMMANDMANAGER_H
#include <map>
#include "Command.h"
#include "GamesHandler.h"

class CommandManager {
private:
    CommandManager();
    ~CommandManager();
    CommandManager(const CommandManager& temp);
    map <string, Command*> commandMap;
    static CommandManager* instance;
    static pthread_mutex_t lock;
    GamesHandler* master;
public:
    void executeCommand (string command,string nameOfGame , int clientSocket =0);
    static CommandManager* getInstance();
};


#endif //EX3_COMMANDMANAGER_H
