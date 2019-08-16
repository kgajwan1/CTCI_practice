#include<cstdio>
#include<stdlib.h>
#include<iostream>
class Node
{
    public:
    Node *next = nullptr; 
    int data;
     
};

class linkedlist : public Node
{
    public:
    void push(Node **n, int data);
    void printList(Node *n);
};

void linkedlist::push(Node **n, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = *n;
    *n = new_node;
}

void linkedlist::printList(Node *n)
{
    while (n != nullptr)
    {
        std::cout << n->data<<"-->";
        n =  n->next;
    }
    std::cout <<'\n';
}