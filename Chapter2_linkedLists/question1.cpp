//remove duplicates from unsorted linked list

//reiterating and remove all dups from current node


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
//removed malloc, we can simply allocate new instance of node
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = (*n);
    (*n) = new_node;
}

//naive way
void removeDupe(Node **n)
{
	
   if ( (*n) == nullptr || ((*n) && ((*n)->next == nullptr))) {
		return ;
	}
    Node *temp = *n;
    while(temp) {
		Node * runner = temp;
		while (runner->next != nullptr) {
			if (runner->next->data == temp->data) {
				runner->next = runner->next->next;
			} else {
				runner = runner->next;
			}
		}
		temp = temp->next;
	}
}
//hash map
// Method 2
// space complexity - O(n)
// time complexity - O(n)
void removeDupe2(Node **n)
{
	 if ( (*n) == nullptr || ((*n) && ((*n)->next == nullptr))) {
		return ;
	}

	std::unordered_map<int, int> node_map;
	Node *prev = (*n);
	Node *curr = (*n)->next;
	node_map[(*n)->data]  =1;
	while(curr != nullptr)
	{
		while(curr && node_map.find(curr->data) != node_map.end())
		{
			curr = curr->next;
		}
		prev->next = curr;
		prev = curr;
		if(curr)
		{
			node_map[curr->data] = 1;
			curr = curr->next;
		}
	}
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
  
	push (&head, 4);
	push (&head, 4);
	push (&head, 4);
	
	push (&head, 4);
	push (&head, 4);
	push (&head, 4);
	push (&head, 4);
	push (&head, 4);
	push (&head, 4);

  
    std::cout<<"Created Linked List: "; 
    printList(head); 
     
    std::cout<<"\nLinked List after removal of duplicates method 1: "; 
	removeDupe(&head);
	printList(head); 
	std::cout<<"\nLinked List after removal of duplicates method 2: "; 
	removeDupe2(&head); 
    printList(head); 
    return 0; 
} 
