//check if binary tree is bst
#include<bits/stdc++.h>

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    } 
};

bool isBSTUtil(Node* root, Node *&prev) 
{ 
    // traverse the tree in inorder fashion and  
    // keep track of prev node 
    if (root) 
    { 
        if (!isBSTUtil(root->left, prev)) 
          return false; 
   
        // Allows only distinct valued nodes  
        if (prev != NULL && root->data <= prev->data) 
          return false;   
        prev = root; 
        return isBSTUtil(root->right, prev); 
    } 
   
    return true; 
} 
  
bool isBST(Node *root) 
{ 
   Node *prev = NULL; 
   return isBSTUtil(root, prev); 
} 
  

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right     = new Node(5); 
    root->left->left = new Node(1); 
    root->left->right = new Node(4); 
  
    if (isBST(root)) 
        std::cout << "Is BST"; 
    else
        std::cout << "Not a BST\n"; 
   
    Node *root2 = new Node(4);  
    root2->left = new Node(2);  
    root2->right = new Node(5);  
    root2->left->left = new Node(1);  
    root2->left->right = new Node(3); 
    
    if (isBST(root2)) 
        std::cout << "Is BST"; 
    else
        std::cout << "Not a BST";  
    return 0; 

}