#include <stdio.h>
#include <stdlib.h> 
struct  node
{
    int data;
    struct node *next;
    struct node *prev;
};

void push(struct node **n, int new_data)
{
    //allocate node
    struct node *new_node =(struct node *) malloc(sizeof(struct node));
    
    //put data in the node
    new_node->data = new_data;
    //make next of new node and null of prev 
    new_node->next = (*n);
    new_node->prev = NULL;
    //change previous of head node to new node 
    if ((*n) !=NULL)
    {
        (*n)->prev = new_node;
    }
    (*n) = new_node;

}

//add a new node to next of old node 
void insertnodeNext(struct node *previous_node, int new_data)
{
    if (previous_node == NULL)
    {
        printf("previous node can not be  null");
        return;
    }
    //allocate a new node
     struct node *new_node = (struct node *)malloc (sizeof(struct node));
    
    //put data in the node
    new_node->data = new_data;
    //Make next of new node as next of prev_node 
    new_node ->next = previous_node->next;

    previous_node->next = new_node;

    new_node->prev = previous_node;
    //if next != null, insert
    if (new_node->next != NULL)  
        new_node->next->prev = new_node;  
}

//append data to node
void append(struct node** head_ref, int new_data)  
{  
    /* 1. allocate node */
    struct node* new_node = (struct node *)malloc( sizeof(struct node));  
  
    struct node* last = *head_ref; /* used in step 5*/
  
    /* 2. put in the data */
    new_node->data = new_data;  
  
    /* 3. This new node is going to be the last node, so  
        make next of it as NULL*/
    new_node->next = NULL;  
  
    /* 4. If the Linked List is empty, then make the new  
        node as head */
    if (*head_ref == NULL) 
    {  
        new_node->prev = NULL;  
        *head_ref = new_node;  
        return;  
    }  
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL)  
        last = last->next;  
  
    /* 6. Change the next of last node */
    last->next = new_node;  
  
    /* 7. Make last node as previous of new node */
    new_node->prev = last;  
  
    return;  
}  

void printList(struct node* node)  
{  
    struct node* last;  
    printf("\nTraversal in forward direction \n");  
    while (node != NULL)  
    {  
        printf("%d",node->data);  
        last = node;  
        node = node->next;  
    }  
  
    printf("\nTraversal in reverse direction \n");  
    while (last != NULL)  
    {  
        printf("%d", last->data);  
        last = last->prev;  
    }  
}  

int main()
{
    /* Start with the empty list */
    struct node* head = NULL;  
  
    // Insert 6. So linked list becomes 6->NULL  
    push(&head, 6);  
  
    // Insert 7 at the beginning. So  
    // linked list becomes 7->6->NULL 
    push(&head, 7);   
    append(&head, 4);  
  
    // Insert 1 at the beginning. So  
    // linked list becomes 1->7->6->NULL  
    push(&head, 1);  
  
    // Insert 4 at the end. So linked  
    // list becomes 1->7->6->4->NULL  
    
  
    // Insert 8, after 7. So linked  
    // list becomes 1->7->8->6->4->NULL  
    insertnodeNext    (head->next, 8);  
  
    printf("Created DLL is: ");  
    printList(head);  
  
    return 0;  
}
