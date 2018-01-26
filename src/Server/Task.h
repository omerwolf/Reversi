/***********************************************************************
* Name : Yoel Jasner & Omer Wolf									   *
***********************************************************************/
#ifndef EX3_TASK_H
#define EX3_TASK_H


class Task {
public:
    /***********************************************************************
    * function name: Task (default con's)                                        *
    * The input:  No input                                                      *
    * The Output: No Output                                                *
    * The Function operation: build the Task from func and arg.       *									   *
    ***********************************************************************/
    Task(void* (*func)(void* arg), void*arg):func(func), arg(arg) {}
    /***********************************************************************
    * function name: excute                                       *
    * The input:  No input                                                      *
    * The Output: No Output                                                *
    * The Function operation: activate the arg as input for func       *									   *
    ***********************************************************************/
    void excute(){
        func (arg);
    }
    /***********************************************************************
    * function name: Task (d'tor)                                  *
    * The input: no input		 										     *
    * The Output: no output										         *                         *
    ***********************************************************************/
    virtual ~Task(){}
private:
    /***********************************************************************
    * function name: *func                                   *
    * The input: no input		 										     *
    * The Output: no output
    * The Function operation: The function that the task needs to execute                       *
    ***********************************************************************/
    void* (*func)(void* arg);
    void* arg;
};


#endif //EX3_TASK_H
