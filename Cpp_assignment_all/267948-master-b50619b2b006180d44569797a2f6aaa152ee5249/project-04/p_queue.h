#ifndef P_QUEUE_H
#define P_QUEUE_H


#include <ostream>
#include <iostream>

#define INT_MAX 2147483647

using namespace std;


struct Node {
    int priority;
    string data;
    Node *next;
};


class p_Queue
{

private:
    Node *head;
    int maxPriority;


public:
     //Node *head;
    p_Queue(int maximum_priority = INT_MAX);
    ~p_Queue();
    //methods to get and set max priority
    void setMaxPriority(int value);
    int getMaxPriority();

    // get the first element's address
    Node *top();

    //insert data into list with priority

    bool push(const int priority, const string data);
    //remove data from list with priority
    bool pop();

    //erase current priority task
    bool erase(const int number);
    //clear all data from priolity list
    void clear();

    friend ostream &operator <<(ostream &out,const p_Queue &ll);

};

#endif // P_QUEUE_H
