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
    ThreadPool (int threadNum);
    void addTask(Task* task);
    void terminate();
    virtual ~ThreadPool();

private:
    queue <Task*> tasksQueue;
    pthread_t* threads;
    void executeTask();
    bool stopped;
    pthread_mutex_t lock;
    static void* excute(void* arg);
};


#endif //EX3_THREADPOOL_H
