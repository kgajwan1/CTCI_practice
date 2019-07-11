//A simple singly linked list
//printing content of linked list after making one
#include<bits/stdc++.h>

class Node{
    public:
    Node *next  = nullptr;
    int data = 0;
};

void printList(Node *n)  
{  
    while (n != nullptr)  
    {  
        std::cout << n->data << " ";  
        n = n->next;  
    }  
}  

int main()
{
    Node *head ;
    Node *second ;
    Node *third ; 
    
    head = new Node();
    second = new Node();
    third = new Node();

    head->data =1;//assign data to node (by default 0)
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;

    printList(head);
}
