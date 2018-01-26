/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_THREADPOOL_H
#define EX3_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;

class ThreadPool {
public:
    /***********************************************************************
    * function name: ThreadPool                                       *
    * The input:  int                                                      *
    * The Output: No Output                                                *
    * The Function operation: build the ThreadPool according the threadNum.       *									   *
    ***********************************************************************/
    ThreadPool (int threadNum);
    /***********************************************************************
    * function name: addTask                                       *
    * The input:  Task*                                                      *
    * The Output: No Output                                                *
    * The Function operation: push task to the tasksQueue.       *									   *
    ***********************************************************************/
    void addTask(Task* task);
    /***********************************************************************
    * function name: terminate                                       *
    * The input:  No input                                                      *
    * The Output: No Output                                                *
    * The Function operation: cancel the mutex and kill the TreadPoll.       *									   *
    ***********************************************************************/
    void terminate();
    /***********************************************************************
    * function name: ThreadPool (d'tor)                                  *
    * The input: no input		 										     *
    * The Output: no output										         *                         *
    ***********************************************************************/
    virtual ~ThreadPool();

    private:
    queue <Task*> tasksQueue;
    pthread_t* threads;
    bool stopped;
    pthread_mutex_t lock;
    /***********************************************************************
    * function name: executeTask                                       *
    * The input:  No input                                                      *
    * The Output: No Output                                                *
    * The Function operation: The function that each thread runs.       *									   *
    ***********************************************************************/
    void executeTask();
    /***********************************************************************
    * function name: excute                                       *
    * The input:  void*                                                      *
    * The Output: No Output                                                *
    * The Function operation: A static wrapper that calls executeTask()        *									   *
    ***********************************************************************/
    static void* excute(void* arg);
    };


#endif //EX3_THREADPOOL_H
