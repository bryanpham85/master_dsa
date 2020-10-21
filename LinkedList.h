#include <iostream>

using namespace std;

typedef struct Node{
    int data;
    Node *next;
} Node;

class LinkedList{
    private:
        Node *head;
        int nCount;

    public:
        LinkedList();
        void Create();
        void Traverse();
        void Clear();
        int Size();
        void InsertTail(int data);
        void InsertHead(int data);
        void RemoveTail();
        void RemoveHead();
        void Insert(int data, int pos);
        void Remove(int pos);
};