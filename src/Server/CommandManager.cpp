/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "CommandManager.h"
#include "StartCommand.h"
#include "JoinCommand.h"
#include "ListCommand.h"
#include "CloseCommand.h"

using namespace std;
CommandManager* CommandManager::instance = 0;
pthread_mutex_t CommandManager::lock;


CommandManager::CommandManager() {
    master = new GamesHandler();
    commandMap["start"] = new StartCommand;
    commandMap["join"] = new JoinCommand();
    commandMap["list_games"] = new ListCommand();
    commandMap["close"] = new CloseCommand();
}

CommandManager::~CommandManager() {
    if (instance != 0){
        delete instance;
    }
    map<string, Command *>::iterator it;
    for (it = commandMap.begin(); it !=commandMap.end(); it++) {
        delete it->second;
    }
    delete master;
}

CommandManager* CommandManager::getInstance() {
    if (instance == 0) {
        pthread_mutex_lock (&lock);
        if (instance == 0) {
            instance = new CommandManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

 void CommandManager::executeCommand(string command,string nameOfGame, int clientSocket) {
     Command* commandobj = commandMap[command];
     commandobj->execute(master, nameOfGame, clientSocket);
 }