#include "Heap.h"


Heap::
Heap(bool isMinHeap)
{
    _isMinHeap = isMinHeap;
    root = NULL;
}    

void
Heap::
Insert(int value)
{
    Node* new_node = new Node();
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    
    Node* right_node = GetRightMostNode();
    if (right_node != NULL)
    {
        new_node->parent = right_node;
        right_node->right = new_node;
    }
    else
    {
        right_node = new_node;
        _root = new_node;
    }
    HeapifyUp(new_node);
}

Node*
Heap::
GetRightMostNode()
{
    Node* root = _root;
    while(root != NULL)
    {
        root = root->right;
    }
    return root;
}

void
Heap::
HeapifyUp(Node* node)
{
    Node* parent(NULL);
    bool change(false);
    while(node != NULL)
    {
        parent = node->parent;
        if (parent != NULL)
        {
            if (_isMinHeap)
            {
                if (parent->data > node->data)
                {
                    change = true;
                }
            }
            else
            {
                if (parent->data < node->data)
                {
                    change = true;
                }
            }
            if (change)
            {
                swap(parent->data, node->data);
            }
        }
        node = parent;
        change = false;
    }
}

Heap::
swap(int& a, int&b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

Heap::
~Heap()
{
    
}

Heap::
PostOrder(Node* root)
{
    if (root != NULL)
    {
        cout << root->data;
    }
    PostOrder(root->left);
    PostOrder(root->right);
}

int
Heap::
GetRootValue()
{
    if (_root != NULL)
    {
        return _root -> data;
    }
    else
    {
        cout << "Root is NULL";
        return -1;
    }
}

int
Heap::
Size()
{
    return count(_root);
}

int
Heap::
count(Node* root)
{
    if(root != NULL)
    {
        return count(root->left) + count(root->right) + 1;
    }
    else
    {
        return 0;
    }
}