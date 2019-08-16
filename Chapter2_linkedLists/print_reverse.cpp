#include"ll.h"
#include<bits/stdc++.h>

void print_reverse(Node *n)
{
    if(n->next  == nullptr)
    {
        std::cout << n->data<< "-->";
        return;
    }
    else 
    {
        print_reverse(n->next);
        std::cout << n->data<< "-->";
        return;
    }
   
}
int main()
{
    linkedlist l;
    Node *n  = nullptr;
    l.push(&n,5);
    l.push(&n,6);
    l.push(&n,4);
    
    print_reverse(n);
    std::cout <<'\n';
    l.printList(n);

    return 0;
}