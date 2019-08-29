//check if binary tree is balanced or not
/*
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1. 
*/

#include<bits/stdc++.h>

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    
};
int ht(Node * root)
    {
        if(root == NULL) return -1;
    
        int a = ht(root->left);
        //std::cout <<a<<": a\n";
        int b = ht(root->right);
        //std::cout <<b<<": b\n";
        if(a == INT_MAX || b == INT_MAX || std::abs(a - b) > 1) return INT_MAX;
        else return std::max(a,b)+1;
    }
bool isBalanced(Node* root) {
        if (root == NULL)
            {
                return true;
            }
     
            int ans = ht(root);
            if (ans == INT_MAX)
                {
                return 0;
                }
            return 1;
        
    }
Node* newNode(int data) 
{ 
    Node* node = new Node(); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
int main()
{
        int height = 0; 
    Node* root = newNode(1);
    //redo
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->left->left->left = newNode(7); 
    root->left->left->right = newNode(8); 
   // root->right->left->right = newNode(9); 
   // root->right->left->right->left = newNode(10);
    //root->right->left->right->left->left = newNode(11); 
     if (isBalanced(root)) 
        std::cout << "Tree is balanced"; 
    else
        std::cout << "Tree is not balanced"; 
  
    return 0; 
}