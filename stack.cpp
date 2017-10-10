//
// Created by amer0 on 10/6/2017.
//

#include <iostream>
#include "stack.h"
using namespace std;

stack::stack():head(nullptr), size(0) {}

stack::stack(char &data) {
    head = new node(data);
    size =1;
}

stack::stack(const stack &original) {
    if (original.head!= nullptr) {
        node *original_tmp = original.head;
        node *tmp = head = new node(original_tmp->data);

        original_tmp = original_tmp->next;
        while (original_tmp != nullptr) {
            tmp->next = new node(original_tmp->data);
            tmp = tmp->next;
            original_tmp = original_tmp->next;
        }
    }
}

stack::~stack() {
    for (node* jump=head->next; !head ; jump=jump->next) {
        delete head;
        head=jump;
    }
}

stack &stack::operator=(const stack &RHS) {

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
                RHS_tmp = RHS_tmp->next;
            }
        }
    }
    return *this;
}

bool stack::isEmpty() const {
    return size==0;
}

unsigned stack::stackSize() const {
    return size;
}

char stack::top() const {
    return head->data;
}

void stack::push(char &data) {

    //create a new node and insert data
    node *temp = new node(data);

    //If the stack is empty
    if(isEmpty())
    {
        //since it is empty point head to the new node
        head = temp;
        //since we added a node
        size++;

        return;
    }
    //if the stack is not empty
    else {

        //let the new node point to the first node
        temp = head->next;

        //let head then point to the newly created node
        head = temp;

        //since we added a node increment size
        size++;

        return;
    }
}

void stack::pop() {
    node *temp;
    //check to see if the stack is empty
    if(isEmpty())
    {
        //since it is empty return an error
        cout<<"Error encountered! The stack is empty"<<endl;
        return;
    }
    else
    {
      //if there are items in the stack
        //assign temp to the leading node
        temp = head;
        //move head to the next node so we can delete the leading node
        head = head->next;
        //once head is moved to the next node, we can delete the leading node
        free(temp);
        //decrement size since we deleted a node
        size--;
    }
}