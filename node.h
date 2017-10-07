//
// Created by amer0 on 10/6/2017.
//

#ifndef STACKS_QUEUE_LAB5_NODE_H
#define STACKS_QUEUE_LAB5_NODE_H


#include <string>

class node {
public:
    std::string data;
    node * next;

    node(const std::string &data);
};



#endif //STACKS_QUEUE_LAB5_NODE_H
