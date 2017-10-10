//
// Created by amer0 on 10/6/2017.
//


#include "queue.h"
#include<iostream>
using namespace std;


queue::queue() :head(nullptr),tail(nullptr),size(0){}

queue::queue(char &data) {
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

char queue::top() const {
    return head->data;
}

void queue::enqueue(char &data) {
        //Create a new node to store the data
    node *temp = new node(data);

    //Check to see if queue is empty by checking the head & tail pointers
    if(isEmpty())
    {
        //since the queue is empty set this both to the new node!
        this->head = this->tail = temp;
        //since this is the first node size will be 1
        size = 1;
        return;
    }
    else{
        //IF the queue list is not empty, and both the head & tail pointing to the first node
        // We use the tail to point to the new node and there after set tail to point the new node!
        tail->next = temp;
        tail = temp;
        //since we are adding a new node, we increment size
        size++;

        return;
    }


}

//we are removing an item from the front
void queue::dequeue() {

    //create a pointer node and have it point where the head is pointing too.
    node *temp;
    temp = head;

    //check to see if the list is empty
    if(isEmpty())
    {
        cout<<"Error encountered! The list is empty!"<<endl;
        size = 0;

        return;
    }
    //if head and tail are both equal.. meaning there is only one item in the list
    else if(head == tail)
    {
        //let temp point to the same node head & tail are pointing too.
        temp = head;
        //set head and tail pointers to nullptr (list is empty)
        head = tail = nullptr;
        //delete the node using delete
        delete temp;

        //since we deleted the only node size will be zero (list is empty)
        size--;
        return;
    }

    //If there are a lot of nodes in the list ... then remove the node pointed by head
    else{
        //let temp point to the same node as head
        temp = head;
        //move head to the next node since we will be deleting the leading node
        head = head->next;
        //free or delete the leading node pointed by temp.. done!
        delete temp;
        //decrement size by one since we removed one node
        size--;

        return;
    }

}
