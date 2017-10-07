//
// Created by amer0 on 10/6/2017.
//


#include "queue.h"

queue::queue() :head(nullptr),tail(nullptr),size(0){}

queue::queue(std::string &data) {
    head=tail=new node(data);
    size=1;
}

queue::queue(const queue &original) {
    if (original.head!= nullptr) {
        node *original_tmp = original.head;
        node *tmp = head = new node(original_tmp->data);

        original_tmp = original_tmp->next;
        while (original_tmp != nullptr) {
            tmp->next = new node(original_tmp->data);
            tmp = tmp->next;
            tail=tmp;
            original_tmp = original_tmp->next;
        }
    }
}

queue::~queue() {
    for (node* jump=head->next; !head ; jump=jump->next) {
        delete head;
        head=jump;
    }
}

queue &queue::operator=(const queue &RHS) {
    if(this != &RHS)
    {
        if (head!= nullptr)
            delete this;
        if (RHS.head!= nullptr) {

            node *RHS_tmp = RHS.head;
            node *tmp = head = new node(RHS_tmp->data);

            RHS_tmp = RHS_tmp->next;
            while (RHS_tmp != nullptr) {
                tmp->next=new node(RHS_tmp->data);
                tmp=tmp->next;
                tail=tmp;
                RHS_tmp = RHS_tmp->next;
            }
        }
    }
    return *this;
}

bool queue::isEmpty() const {
    return size==0;
}

unsigned queue::queueSize() const {
    return size;
}

std::string queue::top() const {
    return head->data;
}

void queue::enqueue(std::string &data) {
    //step 1 create a new node
    //step 2 update next of node pointed to by tail with address of new node
    //step 3 update tail with address of new node
    //step 4 update size of stack variable
}

void queue::dequeue() {
    //step 1 store address of current top node (pointed to by head) in a node*
    //step 2 update head with address of second node
    //step 3 delete node pointed to by address stored in step 1
    //step 4 update size of stack variable
}
