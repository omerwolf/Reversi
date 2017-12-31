//
// Created by omer on 24/12/17.
//

#include <iostream>
#include <pthread.h>
#include <cstdlib>
using namespace std;
#define THREADS_NUM 5

void *printHello(void *threadId) {
    long tid = (long)threadId;
    cout << "Hello world. It's me, thread " << tid << endl;
}

int main_threads() {
    pthread_t threads[THREADS_NUM];
    for (int i = 0 ; i < THREADS_NUM ; i++){
        cout << "In main: creating threads " << i << endl;
        int rc = pthread_create(&threads[i],NULL,printHello,(void *)i);
        if (rc){
            cout << "Error: unable to creat thread, " << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}