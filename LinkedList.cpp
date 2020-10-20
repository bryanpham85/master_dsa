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
    Node *current = this->head->next;
    int index = 0;
    while (current != NULL && index < this->nCount)
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