#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;
} Node;

class Heap
{
public:
    Heap(bool isMinHeap);
    
    virtual ~Heap();

    void Insert(int val);
    int GetRoot();
    int size();
    
    HeapifyUp();
    HeapifyDown();
    
private:
    bool _isMinHeap;
    Node* _root;
};
