
//print all arrays that made the BST
//n! in general, but non viable

#include <bits/stdc++.h>

class node {
    public :
    int data;
    node *left;
    node *right; 
};

node *newNode (int data)
{
    node *n = new node;
    n->data = data;
    n->left =n->right = NULL;
    return n;
}

std::vector<std::vector<int>> findAllSeq(node *n)
{
    //base case
    //null node
    if (n == NULL)
    {
        std::vector<int> seq;
        std::vector<std::vector<int> > v;
        v.push_back(seq);
        return v; 
    } 
    //if left and right are null
    //push back head nodes value

    if(n->left == NULL & n->right == NULL)
    {
        std::vector<int> seq;
        seq.push_back(n->data);
        std::vector<std::vector<int> > v;
        v.push_back(seq);
        return v; 
    }
    //we get both sequences here
    std::vector<std::vector<int>> results;
    std::vector<std::vector<int> > leftSeq  = findAllSeq(n -> left);
    std::vector<std::vector<int> > rightSeq = findAllSeq(n -> right);
    //we need to merge them
    int size = leftSeq[0].size()+rightSeq[0].size() +1;
    std::vector<bool> flags(leftSeq[0].size(),0);
    for (int k = 0; k < rightSeq[0].size(); k++)
        flags.push_back(1);
    
    for (int i = 0;i<leftSeq.size();i++)
        {
            for (int j = 0;j<rightSeq.size();j++){
            do {
                std::vector<int> tmp(size);
                tmp[0] = n -> data;
                int l = 0, r = 0;
                for (int k = 0; k < flags.size(); k++) {
                    tmp[k+1] = (flags[k]) ? rightSeq[j][r++] : leftSeq[i][l++];
                }
                    results.push_back(tmp);
               }
               while (next_permutation(flags.begin(), flags.end()));
            }      
        }
      return results;  
}
node* insert( node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
int main()
{
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    
    std::vector<std::vector<int>> v;
    v = findAllSeq(root);
    
}