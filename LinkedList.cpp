#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
    this->head = NULL;
    this->nCount = 0;
}

void LinkedList::Create(){
    this->head = NULL;
    this->nCount = 0;
}

void LinkedList::Traverse(){
    //just simply traverse all item then print the data out
    Node *current = this->head;
    int index = 0;
    while (current != NULL)
    {
        cout << "The data of Node " << index + 1 << " is " << current->data << "\n";
        index++;
        current = current->next;
    }
    
}

void LinkedList::Clear(){
    //Delete from head to tail
    Node *pDel;

    while (this->head != NULL)
    {
        pDel = this->head;
        this->head = this->head->next;
        delete pDel;
    }

    this->nCount = 0;
}

int LinkedList::Size(){
    return this->nCount;
}

void LinkedList::InsertHead(int data){
    Node *newNode = new Node();
    newNode->data = data;
    Node *previousHead = this->head;
    this->head = newNode;
    newNode->next = previousHead;
    cout << "the new node add at head. List size is: " << ++this->nCount <<"\n";
}

void LinkedList::InsertTail(int data){
    //go from head to the current tail, 
    //then attach new node to the tail which becomes new tails
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node *curNode = this->head;
    //go to tail
    while(curNode->next != NULL){
        curNode = curNode->next->next;
    }
    //at the tail add the new node in
    curNode->next = newNode;

    cout << "The new node added at the Tail of the list. List size is: " << ++this->nCount<<"\n";
}

void LinkedList::RemoveTail(){
    Node *pDel;

    Node *curNode = this->head;
    //go to the node right before tail
    while(curNode->next->next != NULL){
        curNode = curNode->next->next;
    }
    
    pDel = curNode->next;
    curNode->next = NULL;
    delete pDel;
    cout << "The tail node already removed. The size of list remand is: " << --this->nCount<<"\n";
}