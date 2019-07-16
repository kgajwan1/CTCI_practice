//delete middle node from linked list
//it is similar to delete node , except that was for specific positions, which could be entered 
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
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = (*n);
    (*n) = new_node;
}

void deleteNode( Node * node ) {
  if ( node == nullptr || node->next == nullptr ) {
    return;
  }
  Node * nextNode = node->next;
  node->data = nextNode->data;
  node->next = nextNode->next;
  delete nextNode;
}

void printList(Node *n)
{
    while (n!=NULL)
    {
        std::cout<< char(n->data)<<"-->";
        n = n->next;
    }
    std::cout<<"null";
}

int main() 
{ 
    /* Start with the empty list */
   
    Node* head = NULL; 
    //len = 10
    for (int i =5;i>0;i--){
	        push (&head, char('a'+i-1) );
    }
    
    std::cout<<"Created Linked List: "; 
    printList(head); 
    deleteNode(head->next->next); 
    std::cout<<"\nLinked List after Deletion at middle position: "; 
    printList(head); 
    return 0; 
} 
