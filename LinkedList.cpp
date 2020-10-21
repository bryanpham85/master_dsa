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
    cout << "The list is: ";
    while (current != NULL)
    {
        cout << current->data << " , ";
        index++;
        current = current->next;
    }
    cout << "\n";
    
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
    cout << "The list before insert Head is ";
    this->Traverse();
    Node *newNode = new Node();
    newNode->data = data;
    Node *previousHead = this->head;
    this->head = newNode;
    newNode->next = previousHead;
    cout << "The list after insert Head is ";
    this->Traverse();
}

void LinkedList::InsertTail(int data){
    //go from head to the current tail, 
    //then attach new node to the tail which becomes new tails
    cout << "The list before insert Tail is ";
    this->Traverse();

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

    cout << "The list after insert Tail is ";
    this->Traverse();
}

void LinkedList::RemoveTail(){
    if(this->head == NULL){
        cout << "Cannot delete the tail because list is empty \n";
        return;
    }
    Node *pDel;

    Node *curNode = this->head;
    //go to the node right before tail
    //To-do: need to improve with only one node list: head is tail
    while(curNode->next->next != NULL){
        curNode = curNode->next->next;
    }
    
    cout << "The list before remove Tail is ";
    this->Traverse();

    pDel = curNode->next;
    curNode->next = NULL;
    delete pDel;
    this->nCount--;
    
    cout << "The list before removeTail Head is ";
    this->Traverse();
}

void LinkedList::RemoveHead(){
    if(this->head == NULL){
        cout << "The list currently empty, cannot delete the head" << "\n";
        return;
    }
    //The list before removeHead
    cout << "The list before removeHead is: ";
    this->Traverse();

    Node *pDel = this->head;
    this->head = this->head->next;
    delete pDel;
    --this->nCount;
    
    cout << "The list aftr Remove Head is ";
    this->Traverse();
}

void LinkedList::Insert(int data, int pos){
    //check pos
    if(pos > this->nCount || pos < 0)
    {
        cout << "Invalid position \n";
        return;
    }
    cout << "the list before insert";
    this->Traverse();

    //build node
    Node *newNode = new Node();
    newNode->data = data;

    //move to the the node just right before the expected pos
    int index = 0;
    Node *curNode = this->head;
    while(index < pos){
        curNode = curNode->next;
        ++index;
    }
    //switch node
    newNode->next = curNode->next;
    curNode->next = newNode;

    cout << "The list after insert " << data << " at pos " << pos;
    this->Traverse();
    
}
