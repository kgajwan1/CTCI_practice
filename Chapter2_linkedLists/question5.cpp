//question 5
//in leetcode too
 //What if digits are not stored in reverse order(i.e 1's digit is at tail)
 //(6--1-->7) + (2-->9-->5) = (9-->1-->2)
#include<bits/stdc++.h>

class Node{
    public:
    int data;
    Node *next;
};

void insertNode(Node **n, int data)
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
        /* code */
        std::cout << n->data<<"-->";
        n = n->next;
    }
    std::cout <<"null";  
}

Node *add_iterative(Node *l1, Node *l2)
{
    if (l1 == nullptr)
    {
        return l2;
    }
    if (l2 == nullptr)
    {
        return l1;
    }
    //output 
    Node *l3 = nullptr;
    // for adding new nodes to tail of list3
    Node *l3_tail = nullptr;

    int value =0;
    int carry =0;
    while (l1 || l2)
    {
        value = carry + (l1 ? l1->data : 0) +  (l2 ? l2->data : 0);
        if (value >9)
        {
            carry = 1;
            value%=10;
        }
        else{
            carry = 0;
        }
        Node *temp = new Node();        
        insertNode(&temp,value);

        if (l3 == nullptr)
        {
             l3 = temp;
        }
        else {
            
             l3_tail-> next = temp;
        }
         l3_tail = temp;
        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }

    }

        if (carry>0)
        {
            l3_tail->next = new Node();
            insertNode(&l3_tail->next,carry); 
        }
    return l3;
}


//recursive implementation, better
Node *sum(Node *l1, Node *l2, int carry)

{
    if (l1 == nullptr && l2 == nullptr && carry ==0)
    {
        return nullptr;
    }
    int value = carry;
    if (l1)
    {
        value += l1->data;
    }
    if (l2)
    {
        value += l2->data;
    }
    Node *resultNode = new  Node();
    insertNode(&resultNode,value%10); 
    resultNode->next = sum( l1 ? (l1->next) : nullptr,
                                    l2 ? (l2->next) : nullptr,
                                    value > 9 ? 1:0 );
    
    return resultNode;
}


//followup case
//all parts here
int length (Node *l1)
{
    int i =0;
    while (l1)
   {
       i++;
       l1 = l1->next;
   }
   return i; 
}

void padding (Node *l1, int padding)
{
    for (int i = 0;i<padding ; i++)
    {
        insertNode(&l1,0);
    }
}

//why &?
Node *add_followup_helper(Node *l1,Node *l2, int &carry)
{
    if (l1 == nullptr && l2 == nullptr && carry ==0)
    {
        return nullptr;
    }
    Node *result = add_followup_helper(l1 ? (l1->next) : nullptr,
                                      l2 ? (l2->next) : nullptr,
                                      carry);
  int value = carry + (l1 ? l1->data : 0 ) + (l2 ? l2->data : 0);
   

  insertNode(&result, value % 10 );
  carry = ( value > 9 ) ? 1 : 0;
  return result;

}

Node *add2(Node *l1,Node *l2)
{
    int length_1 = length (l1);
   
    int length_2 = length (l2);
   

    if (length_1>length_2)
    {
        padding(l2,length_1- length_2);
        //printList(l2);
    }else {
        padding(l1,length_2-length_1);
        //printList(l1);
    }
    int carry =0;
    Node *list3 = add_followup_helper( l1, l2, carry);
    if (carry>0)
    {
        insertNode(&list3,carry);
        printList(list3);
    }
    
    return list3;
}
void deleteList( Node * & head ) {
   Node * nextNode;
   while(head) {
     nextNode = head->next;
     delete(head);
     head = nextNode;
   }
 }

int main()
{
    Node *l1 = nullptr;
    insertNode(&l1,8);
    insertNode(&l1,6);
    insertNode(&l1,1);
    insertNode(&l1,7);
    std::cout << "l1" << " : ";
    printList(l1);
    Node *l2 = nullptr;
    insertNode(&l2,2);
    insertNode(&l2,5);
    insertNode(&l2,9);
    insertNode(&l2,5);
    std::cout <<"\nl2 " << " : ";
    printList(l2);
    Node * list4= sum(l1,l2,0);
    std::cout <<"\nlist4 " << " : ";
    printList(list4);
    Node *l5 = add_iterative(l1,l2);
    std::cout <<"\nlist5 " << " : ";
    printList(l5);
    //deleteList(l1);
    //deleteList(l2);
    deleteList(list4);
    deleteList(l5);    
  
    Node *l6 = add2(l1,l2);
    std::cout <<"\nlist6 " << " : ";
    printList(l6);
}