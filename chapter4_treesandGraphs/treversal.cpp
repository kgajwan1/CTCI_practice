//inorder traversal of BST nodes

#include<iostream>
/*
https://www.geeksforgeeks.org/this-pointer-in-c/
Every object in C++ has access to its own address through an 
important pointer called this pointer. 
The this pointer is an implicit parameter to all member functions. 
Therefore, inside a member function, this may be used to refer to the invoking object.

Friend functions do not have a this pointer, because friends are not members of a class. 
Only member functions have a this pointer.
*/
class node{
    public:
    int data;
    node *curr;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    } 
};

void inOrderTraversal(node *n)
{
    if (n == NULL)
    {
        return;
    }
    //recurse on left child
    inOrderTraversal(n->left);
    //print data
    std::cout<<n->data<<" ";
    //recurse right child
    inOrderTraversal(n->right);
}
void postOrderTraversal(node *n)
{
    if(n == NULL)
    {
        return;
    }
    postOrderTraversal(n->left);
    postOrderTraversal(n->right);
    std::cout << n->data<<" ";
}    

void preOrderTraversal(node *n)
{
    if(n == NULL)
    {
        return;
    }
    std::cout << n->data<<" ";
    preOrderTraversal(n->left);
    preOrderTraversal(n->right);
}
int main()
{
    //driver
    node *root = new node(1); 
    root->left             = new node(2); 
    root->right         = new node(3); 
    root->left->left     = new node(4); 
    root->left->right = new node(5);  
  
    std::cout << "\nPreorder traversal of binary tree is \n"; 
    preOrderTraversal(root); 
    std::cout << '\n';
    std::cout << "\nInorder traversal of binary tree is \n"; 
    inOrderTraversal(root);  
    std::cout << "\nPostorder traversal of binary tree is \n"; 
    postOrderTraversal(root); 
  
    return 0; 
}