/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#include "ThreadPool.h"
#include <unistd.h>
#define NUMOFTHREADS 5

ThreadPool::ThreadPool(int threaNum) :stopped (false) {
    threads = new pthread_t(NUMOFTHREADS);
    for (int i=0;i<NUMOFTHREADS;++i){
        pthread_create(threads+i, NULL, excute, this);
    }
    pthread_mutex_init(&lock, NULL);
}

void* ThreadPool::excute(void *arg) {
  ThreadPool *pool = (ThreadPool*) arg;
    pool->executeTask();
}

void ThreadPool::addTask(Task *task) {
    tasksQueue.push(task);
}

void ThreadPool::executeTask() {
    while (!stopped){
        pthread_mutex_lock(&lock);
        if (!tasksQueue.empty()){
            Task* task = tasksQueue.front();
            tasksQueue.pop();
            pthread_mutex_unlock(&lock);
            task->excute();
        }
        else{
            pthread_mutex_unlock(&lock);
            sleep(1);
        }
    }
}

void ThreadPool::terminate() {
    pthread_mutex_destroy(&lock);
    stopped = true;
}
ThreadPool::~ThreadPool() {
    delete threads;
}
