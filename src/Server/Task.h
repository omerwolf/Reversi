/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_TASK_H
#define EX3_TASK_H


class Task {
public:
    Task(void* (*func)(void* arg), void*arg):func(func), arg(arg) {}
    void excute(){
        func (arg);
    }
    virtual ~Task(){}
private:
    void* (*func)(void* arg);
    void* arg;
};


#endif //EX3_TASK_H
