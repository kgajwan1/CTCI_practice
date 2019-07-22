//question 6:
//is palindrome?
//1 way done
#include<bits/stdc++.h>
//basics
class Node
{
    public:
    char data;
    Node* next;
};
void insertNode (Node **n , char data)
{
    Node *newNode = new Node();
    newNode->data  = data;
    newNode->next = (*n);
    (*n) = newNode; 
}

void printList (Node *n)
{
    while (n != nullptr)
    {
        std::cout << n->data<< "-->";
        n = n->next;
    }
    std::cout <<"nullptr\n";
}
//create a program to reverse a linked list
void reverse( Node * & head ) {
  if ( head == nullptr  || (head && (head->next == nullptr))){
    return;
  }
  Node * newHead = nullptr;
  Node * nextNode = nullptr;
  while ( head ) {
    nextNode = head->next;
    //this is segfault:
    //std::cout <<nextNode->data<<"->";
    head->next = newHead;
    newHead = head;
    head = nextNode;
  }
  head = newHead;
}


bool helper(Node * &left, Node *right)
{
    if (right == nullptr){
        return true;
    }

    bool isPalindrome = helper(left,right->next);
    if(!isPalindrome){
        return false;
    }
    isPalindrome = (left->data == right->data);

    left = left->next;
    return isPalindrome;


}
bool isPalindromeRecursive(Node *head)
{
    return helper (head,head);
}
int main()
{
    Node* head = nullptr;
    Node* head2 = nullptr;
    insertNode(&head, 'm');
    insertNode(&head, 'a');
    insertNode(&head, 'd');
    insertNode(&head, 'a');
    insertNode(&head, 'm');
    printList(head);
    insertNode(&head2,'h');
    insertNode(&head2,'e');
    insertNode(&head2,'l');
    insertNode(&head2,'l');
    insertNode(&head2,'o');
    printList(head2);
    if ( isPalindromeRecursive(head) ) {
    std::cout << "List is pallindrome list\n";
  } else {
    std::cout << "List  is not a pallindrome list\n";
  }
  reverse(head2);
  printList(head2);

}

