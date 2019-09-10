/*
 Imagine you are reading in a stream of integers. 
 Periodically, you wish to be able to lookup the rank of a number 
 x (the number of values less than or equal to x). 
 lmplementthe data structures and algorithms to support these operations. 
 That is, implement the method track ( int x), which is called when each 
 number is generated, and the method getRankOfNumber(int x), 
 which returns the number of values less than or equal to x (not including x itself). EXAMPLE 
*/

/*
We traverse the tree from root and compare the root values to x.

    If root->data == x, return size of left subtree of root.
    If x data, return getRank(root->left)
    If x > root->data, return getRank(root->right) + size of letSubtree + 1.
*/
#include <bits/stdc++.h>

class TreeNode 
{
    public:
    int data;
    int leftSize; 
    TreeNode *left, *right;
};

TreeNode *newNode (int data)
{
    TreeNode *n = new TreeNode;
    n->data = data;
    n->left = n->right = NULL;
    n->leftSize = 0;
    return n;
} 

TreeNode *insertNode (TreeNode *n, int key)
{
    if (n == NULL)
        return newNode(key);
    if (key < n->data) {
        n->left  = insertNode(n->left, key); 
        n->leftSize++;
    }
    else 
        n->right  = insertNode(n->right, key); 
    
    return n;
}

int getRank(TreeNode* n, int x)
{
    if(n->data == x )
    {
        return n->leftSize;
    }
    if(x< n->data)
    {
        if(n->left == NULL)
        {
            return -1;
        }    
        return getRank(n->left,x);
    }
    else 
    {
        if(n->right == NULL)
        {
            return -1;
        } 
        int rightSize = getRank(n->right, x);   
        return n->leftSize +1 + rightSize;
    }

}


int main()
{
    int arr[] = { 5, 1, 4, 4, 5, 9, 7, 13, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
   
  
    TreeNode* root = NULL; 
    for (int i = 0; i < n; i++) 
        root = insertNode (root, arr[i]); 
   
    int x = 4; 
    std::cout << "Rank of " << x << " in stream is: " 
         << getRank(root, x) << '\n'; 
  
    x = 13; 
    std::cout << "Rank of " << x << " in stream is: "
         << getRank(root, x) << '\n'; 
  
    return 0; 
}