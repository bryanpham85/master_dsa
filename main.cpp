#include <iostream>

#include "LinkedList.h"
using namespace std;


int main() {
    
    LinkedList *lSample = new LinkedList();
    cout << "Samle List init, size is: " << lSample->Size() <<"\n";

    //insert head
    lSample->InsertHead(1);
    lSample->InsertTail(2);
    lSample->Insert(3,1);
    lSample->RemoveHead();
    lSample->RemoveTail();

    return 1;
}