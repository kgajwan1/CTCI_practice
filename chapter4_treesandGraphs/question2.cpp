//create a binary search tree from sorted array

//make middle element root node, do recursion for left and right half
#include<bits/stdc++.h>

class node
{
    public:
    int data;
    node *left, *right;
};
//create a new node
struct node *newNode(int item) 
{ 
    node *temp =  new node;
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}
//utility to do preorder traversal 
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

node *sortedArrtoBST(int arr[],int start,int end)
{
    if (start>end)
    {
       // std::cout << "not possible\n";
        return NULL;
    }
    //get middle elem and make it a root 
    int mid = (start + end)/2;
    node *root = newNode(arr[mid]);
    root->left = sortedArrtoBST( arr, start,mid-1);
    root ->right = sortedArrtoBST( arr, mid+1,end);
    return root; 
}
int main()  
{  
    int arr[] = {1, 2, 3, 4, 5, 6, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);  
  
    /* Convert List to BST */
    node *root = sortedArrtoBST(arr, 0, n-1);  
    std::cout << "PreOrder Traversal of constructed BST \n";  
    preOrderTraversal(root);  
  
    return 0;  
}  