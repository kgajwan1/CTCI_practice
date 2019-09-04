//implement binary tree from scratch
// You are implementing a binary tree class from scratch which, in addition to insert,
// find, and delete, has a method getRandomNode() which returns a random node from the tree. 
//All nodes should be equally likely to be chosen.
// Design and implement an algorithm for getRandomNode, and explain how you would implement 
//the rest of the methods. 
#include <bits/stdc++.h>

class node {
    public: 
    int data;
    int child;
    node *left;
    node *right;
};

node *newNode (int data)
{
    node *n = new node;
    n->data = data;
    n->left= NULL;
    n->right = NULL;
    n->child =0;
    return n;
}

int getElem(node *n)
{
    if (!n)
        return 0;
    return getElem(n->right)+getElem(n->left) +1;
//get elem count
}

void insertnewNode (node *&n)
{
    if(!n)
        return ;
    n->child    = getElem(n)-1;
    insertnewNode(n->left);
    insertnewNode(n->right);
}
int children(node *root)
{
    if(!root)
        return 0;
    return root->child+1;
}

int randomNodeUtil(node* root, int count)
{
    if (!root) 
        return 0; 
    if (count== children(root->left))
        return root->data;
    if(count < children(root->left))
        return randomNodeUtil(root->left,count);
    return randomNodeUtil(root->right, 
              count - children(root->left) - 1); 
}
int getRandom(node *n)
{
    srand(time(0)); 
  
    int count = rand() % (n->child + 1); 
    return randomNodeUtil(n, count); 
}
int main() 
{ 
    // Creating Above Tree 
    node* root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->right = newNode(40); 
    root->left->right = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    insertnewNode(root); 
  
    std::cout << "A Random Node From Tree : "
         << getRandom(root) << std::endl; 
  
    return 0; 
} 