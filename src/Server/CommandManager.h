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
   /**********************************************************************
   * function name: executeCommand
   * The input: string command, string name of game, int Socket (default value = 0)
   * The Output: No Output
   * The Function operation: Activate the command by matching the string to
   *                         map fo commands.
   ***********************************************************************/
    void executeCommand (string command,string nameOfGame , int clientSocket =0);
   /**********************************************************************
   * function name: getInstance
   * The input: No input
   * The Output: No Output
   * The Function operation: static method, make sure that only one appearance
   *                         of the command manager created.
   ***********************************************************************/
    static CommandManager* getInstance();
    GamesHandler* get(){return master;};
};


#endif //EX3_COMMANDMANAGER_H
