//
// Created by amer0 on 10/6/2017.
//

#ifndef STACKS_QUEUE_LAB5_STACK_H
#define STACKS_QUEUE_LAB5_STACK_H



#include "node.h"

class stack {
    node * head;
    unsigned size;

public:
    stack();
    stack(std::string& data);
    stack(const stack& original);
    virtual ~stack();

    stack & operator=(const stack& RHS);
    bool isEmpty()const;
    unsigned stackSize() const;
    std::string top()const;
    void push(std::string& data);
    void pop();
};



#endif //STACKS_QUEUE_LAB5_STACK_H
