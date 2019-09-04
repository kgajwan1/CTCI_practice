#include<bits/stdc++.h>
#include"llnode.h"

//print vector from i to end
void printvec(std::vector<int> &v,int i)
{
    for (int j = i;j< v.size();j++)
    {
        std::cout << v[j]<<'\t';
    }
    std::cout <<'\n';
}

void printKPathutil(node *&root,std::vector<int> path,int k)
{
    if(!root)
    {
        return ;
    }
    int f = 0;
    path.push_back(root->data);
    printKPathutil(root->left, path,k);
    printKPathutil(root->right, path,k);
    for (int j=path.size()-1; j>=0; j--)
    {
        f+= path[j];
        if(f ==k){
            printvec(path,j);
        }
    }
    //remove current element from path
        path.pop_back(); 
}
void printKPath(node *&root,int k)
{
    std::vector<int> path; 
    printKPathutil(root,path,k);
}
int main() 
{ 
    node *root = new node(1); 
    root->left = new node(3); 
    root->left->left = new node(2); 
    root->left->right = new node(1); 
    root->left->right->left = new node(1); 
    root->right = new node(-1); 
    root->right->left = new node(4); 
    root->right->left->left = new node(1); 
    root->right->left->right = new node(2); 
    root->right->right = new node(5); 
    root->right->right->right = new node(2); 
  
    int k = 5; 
    printKPath(root, k); 
  
    return 0; 
} 
