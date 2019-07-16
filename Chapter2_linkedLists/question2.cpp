//question 2
//find kth to last element of linked list
//if size is known..it is easy, since kth to last elem is length -k , simply loop list to it
//method 2, use recursion
#include <bits/stdc++.h>

class Node {
    public :
    int data;
    Node *next;
};

void push (Node **n, int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = (*n);
    (*n) = new_node;
}
void printList(Node *n)
{
    while (n != nullptr)
    {
            std::cout<<n->data<<"-->";
            n = n->next; 
    }
    std::cout << "null"<<'\n';
}

void deleteList( Node * & head ) {
  Node * nextNode;
  while(head) {
    nextNode = head->next;
    delete(head);
    head = nextNode;
  }
} 
//assuming length is known
void kth_to_last_simple(Node *n,int length,int position)
{
    if(n == nullptr)
    {
        return;
    }
     Node *temp = n;
    for (int i =0; temp != NULL && i< length-position; i++)
    {
        //runner node
            {
                temp = temp->next;
            }
        
    }
    std::cout<< temp->data<<"  ";

}
Node *kthtoLastHelper(Node *n,int k, int &i)
//un;ess you increase it by address, it wont increment in recursion, therefore node does not move forward
//since i is essentially used to traverse node , we need to increase it through address
{
    if (n == nullptr)
    {
        return nullptr;
    }
    Node *node = kthtoLastHelper(n->next, k, i);
      i++;

    
    //std::cout << i<<" ";
    if ( i == k ) {
    return n;
  }
  return node;

}
Node* kthToLastRecursive(Node *n,int k)
{
    int i =0;
    return kthtoLastHelper(n,k,i);
}

//iterative method
//similar to simple method, but with k 
// we use 2 nodes p1 and p2 and place them k distance away. we then move them towards end 
//at same pace, so whnn p2 hits end, p1 gets to len -k;
Node *kthToLastIterative(Node *n, int k)
{
    if (n == nullptr)
    {
        return nullptr;
    }
    Node  *ptr1 = n;
    Node  *ptr2 = n;
    int i =0;
    while (i<k && ptr1)
    {
        ptr1 = ptr1->next;
       //increment i
        ++i;
    }
    if (i<k)
    {
        return nullptr;
    }
    while (ptr1 != nullptr)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
   return ptr2;
    
}  

int main() 
{ 
    /* Start with the empty list */
    int k,n;
    std::cout<<" Enter length and position";
    std::cin>> n;
    std::cin>> k;
    
    Node* head = NULL; 
    for (int i =0;i<n;i++){
	        push (&head, rand());
    }
    std::cout<<"Created Linked List: "; 
	printList(head); 

    std::cout<<"\n"<< k <<"th to last element: "; 
    kth_to_last_simple(head, n, k );
    //Assuming length is not given
    std::cout << "\n4th node from last (iterative) : ";
    Node *node4 = kthToLastIterative(head, 4);
   if ( node4 != nullptr ) {
    std::cout << node4->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }        
  std::cout << "5th node from last (Recursive) : ";
  Node *node5 = kthToLastRecursive(head, 5);
  if ( node5 != nullptr ) {
    std::cout << node5->data << std::endl;
  } else {
    std::cout << "NULL NODE\n";
  }
    deleteList(head);
    return 0; 
} 
