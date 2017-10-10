//
// Created by amer0 on 10/6/2017.
//

#ifndef STACKS_QUEUE_LAB5_QUEUE_H
#define STACKS_QUEUE_LAB5_QUEUE_H




#include "node.h"

class queue {
    node *head, *tail;
    unsigned size;

public:
    queue();
    queue(char &data);
    queue(const queue& original);
    virtual ~queue();

    queue&operator=(const queue& RHS);
    bool isEmpty()const;
    unsigned queueSize() const;
    char top()const;
    void enqueue(char &data);
    void dequeue();
};



#endif //STACKS_QUEUE_LAB5_QUEUE_H
