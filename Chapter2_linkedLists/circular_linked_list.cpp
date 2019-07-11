//circular linked list
//implement a simple circular linked list
//Circular linked list is a linked list where all nodes are connected to form a circle. There is no NULL at the end. 
//A circular linked list can be a singly circular linked list or doubly circular linked list.

#include<bits/stdc++.h>

class Node{
    public:
    int data ;
    //no nullptr here
    Node *next;
};

//insert at beginning of Linked List
void insertNode(Node **head_ref, int data)
{

    Node *ptr1 = new Node();
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL)
    {
        while(temp->next != *head_ref)
                    temp = temp->next;
            temp->next = ptr1;
        
    }
    else 
    {
        ptr1->next  =ptr1;

    }
        *head_ref = ptr1;

}
//n == head node 
void printList(Node *head)  
{  
    Node *temp = head;  
    if (head != nullptr)
    {
    do
    {  
        std::cout << temp->data << " ";  
        temp = temp->next;  
    } 
    while(temp != head);
    }
}  
int main()  
{  
    /* Initialize lists as empty */
    Node *head = NULL;  
  
    /* Created linked list will be 11->2->56->12 */
    insertNode(&head, 12);  
    insertNode(&head, 56);  
    insertNode(&head, 2);  
    insertNode(&head, 11); 
  
    std::cout << "Contents of Circular Linked List\n ";  
 
    printList(head);  
  
    return 0;  
}  
