//question 4; redo
//quick sort a linked list (partitian around value x)
/*
 *  Write code to partition linked list around a value x, such that
 *  nodes less than x come before all the nodes greater than or equal to x.
 *  If x is in the list, the values of x only need to be after the elements less
 *  than x.
 *  Example
 *  3-->5-->8-->5-->10-->2-->1 (x = 5)
 *  3-->1-->2-->10-->5-->5-->8
 *  Approach:
 *  Start with first node, and add every thing bigger or equal to x at tail
 *  and smaller values at head.
 * */

#include<bits/stdc++.h>
class Node
{
    public:
    int data;
    Node *next = nullptr;//you do not need it here
}; 

void push(Node **n, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = (*n);
    (*n) = new_node;
}

void printList(Node *n)
{
    while (n!=NULL)
    {
        std::cout<< (n->data)<<"-->";
        n = n->next;
    }
    std::cout<<"null";
}
Node * partition( Node *n , int value ) {
    //initialize all variables
    Node *head = nullptr;
    Node *head_initial = nullptr;
    Node *tail = nullptr;
    Node *tail_initial = nullptr;
    Node *curr = n;

    while (curr != nullptr)
    {
    Node *next_node = curr->next;
    if (curr->data<value)
    {
            if (head == nullptr)
            {
                head = curr;
                head_initial = head;
            }
        head->next = curr;
        head = curr;
    } else {
            if (tail == nullptr)
            {
                tail = curr;
                tail_initial  = tail;
            }
        tail->next = curr;
        tail = curr;
        
    }
    curr = next_node;
    }    
   head->next = tail_initial;  /*Now, we connect the head list to tail list.*/
   tail->next = nullptr;
   return head_initial;
 }

int main()
{
    Node *head = nullptr;
    for (int i =1;i<=10;i++)
        {
            push(&head, rand()%9);
        }

  std::cout << "List before partition around 3:\n";
  printList(head);
  std::cout << "\nList after partition around 3:\n";
  printList(partition(head, 3));
  return 0;
}