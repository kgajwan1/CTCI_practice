//here
//stack with linked list
#include<bits/stdc++.h>

class NodeStack{
    public:
    int data;
    NodeStack *next;
}; 

NodeStack *newNode(int data)
{
    NodeStack *nodeStack = new NodeStack();
    nodeStack->data = data;
    nodeStack->next = NULL;
    return nodeStack;    
}

int isEmpty(NodeStack *root)
{
    return !root;
}

void push (NodeStack **root, int data)
{
    NodeStack *nodeStack = newNode(data);
    nodeStack->next = *root;
    *root = nodeStack;
    std::cout << data<< " pushed to stack\n ";
}

int pop (NodeStack **root)
{
    if (isEmpty(*root))
        return INT_MIN;
    NodeStack *temp = *root;
    *root = (*root) ->next;
    int popped = temp->data;
    free (temp);
    return popped;

}

int peek (NodeStack *root)
{
    if (isEmpty(root))
    {
        return INT_MIN;
    }
    return root->data;
}

int main() 
{ 
    NodeStack* root = NULL; 
  
    push(&root, 10); 
    push(&root, 20); 
    push(&root, 30); 
  
    std::cout << pop(&root) << " popped from stack\n"; 
  
    std::cout << "Top element is " << peek(root) <<"\n"; 
  
    return 0; 
} 
