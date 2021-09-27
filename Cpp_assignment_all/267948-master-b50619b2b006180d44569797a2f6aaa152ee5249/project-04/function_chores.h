#ifndef FUNCTION_CHORES_H
#define FUNCTION_CHORES_H

#include "p_queue.h"
#include <cstdlib>



class function_Chores
{
private:
    p_Queue priorityQueue;
    string promptInput;
    bool isInitialized;

    //varible used for commands

    string args;
    string operation;
    string command;
    int number;
    bool numberFound;
    bool argsFound;


public:
    // constructor of function_Chores class

    function_Chores();
    // shows prompt at the begining and takes input
void prompt();

//split the input received after prompt to be used as argument

void processCommand();
// methods for various arguments.

void init();
void add();
void print();
void next();
void erase();


};

#endif // FUNCTION_CHORES_H
