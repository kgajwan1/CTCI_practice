//delete node from linked list
#include<bits/stdc++.h>
class Node{
    public:
    Node* next;
    int data ;

};

//push data to node
/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
void push(Node **n, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = (*n);
    (*n) = new_node;
}

void deleteNode(Node **n, int position)
{
    if(*n == NULL)
    {
        return;
    }
    Node *temp = *n;
    //postion = 0;
    if (position == 0)
    {
        *n = temp->next;
        free(temp);
        return;
    }
    for (int i =0; temp != NULL && i< position-1; i++)
    {
        //runner node
            {
                temp = temp->next;
            }
        
    }
    if(temp == NULL || temp-> next == NULL)
            {
                return;
            }
    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void printList(Node *n)
{
    while (n!=NULL)
    {
        std::cout<< n->data<<"  ";
        n = n->next;
    }

}

int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 9); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 6); 
    push(&head, 8); 
  
    std::cout<<"Created Linked List: "; 
    printList(head); 
    deleteNode(&head, 4); 
    std::cout<<"\nLinked List after Deletion at position 4: "; 
    printList(head); 
    return 0; 
} 
