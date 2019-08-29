//given a binary tree make an algo that makes a linked list of 
//all nodes at all depths
//assuming it is complete binary tree 
//eg if depth = d, number of nodes = d;
//a part of gfg
#include<bits/stdc++.h>

class node{
    public:
    int data;
    node *left, *right, *nextright;

    node(int data)
    {
        this->data= data;
        this->left=this->right=this->nextright = NULL;
    } 
};

void connectRecur(node *p)
{
    //base 
    if(!p)
    {
        return;
    }
    // Set the nextRight pointer for p's left child  
    if(p->left)
    {
        p->left->nextright = p->right;
    }
    if(p->right)
    {
        p->right->nextright = p->nextright ? p->nextright->left : NULL;
    }
    connectRecur(p->left);  
    connectRecur(p->right);    
}

void connect( node *p)
{
    //driver code to call connect recur from root
    p->nextright = NULL;
    connectRecur(p);
}
//not working as yet
void dataout (node *n)
{
    std::cout <<"in data out";
     while (n->nextright)
    {
        std::cout << n->nextright->data;
    }
    std::cout << "-1";
}
int main()
{
     node *root = new node(10);  
    root->left = new node(8);  
    root->right = new node(2);  
    root->left->left = new node(3);  
    
   connect (root);

   std::cout<<"Following are populated nextRight pointers in the tree"
        " (-1 is printed if there is no nextRight)\n";  
    std::cout<<"nextRight of "<<root->data<< " is "
        << (root->nextright? root->nextright->data: -1) <<std::endl;  
    std::cout<<"nextRight of "<<root->left->data<< " is "
        << (root->left->nextright? root->left->nextright->data: -1) <<std::endl; 
    std::cout<<"nextRight of "<<root->right->data<< " is "
        << (root->right->nextright? root->right->nextright->data: -1) <<std::endl; 
    std::cout<<"nextRight of "<< root->left->left->data<< " is "
        << (root->left->left->nextright? root->left->left->nextright->data: -1) <<std::endl; 
    return 0;  
    
//ill try a while loop
}