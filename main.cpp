#include <iostream>

#include "LinkedList.h"
using namespace std;


int main() {
    
    LinkedList *lSample = new LinkedList();
    cout << "Samle List init, size is: " << lSample->Size() <<"\n";

    //insert head
    lSample->InsertHead(1);
    lSample->InsertHead(2);
    lSample->InsertHead(3);
    lSample->InsertTail(4);
    cout <<"size of the list by Size method "<< lSample->Size() << "\n";
    lSample->Traverse();

    return 1;
}