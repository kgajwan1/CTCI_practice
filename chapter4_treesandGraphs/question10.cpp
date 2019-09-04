//is t2 subset of t1?
#include<bits/stdc++.h>
#include"llnode.h"

bool areIdentical(node *r1,node *r2)
{
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if(r1 == NULL || r2 == NULL)
    {
        return true;
    }
    return (r1->data == r2->data &&  
            areIdentical(r1->left, r2->left) &&  
            areIdentical(r1->right, r2->right) );  

}

bool isSubtree(node *T, node *S)  
{  
    /* base cases */
    if (S == NULL)  
        return true;  
  
    if (T == NULL)  
        return false;  
  
    /* Check the tree with root as current node */
    if (areIdentical(T, S))  
        return true;  
  
    /* If the tree with root as current  
    node doesn't match then try left  
    and right subtrees one by one */
    return isSubtree(T->left, S) ||  
        isSubtree(T->right, S);  
}  
int main()
{
     node *T = new node(26);  
    T->right         = new node(3);  
    T->right->right = new node(3);  
    T->left         = new node(10);  
    T->left->left     = new node(4);  
    T->left->left->right = new node(30);  
    T->left->right     = new node(6);  

    node *S = new node(10);  
    S->right     = new node(6);  
    S->left     = new node(4);  
    S->left->right = new node(30);  

    if (isSubtree(T, S))  
        std::cout << "Tree 2 is subtree of Tree 1";  
    else
        std::cout << "Tree 2 is not a subtree of Tree 1";  
  
    return 0;
}