#include<bits/stdc++.h>
#include "llnode.h"


class btree{
       public:
       btree();
       ~btree();
       void insert(int key);
       node *search (int key);
       void destroy_tree();

       private:
       void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
         
        node *root; 
};




void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, node *leaf)
{
  if(key< leaf->data)
  {
    if(leaf->left!=NULL)
    {
     insert(key, leaf->left);
    }
    else
    {
      leaf->left=new node(key);  
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
    else if (key >= leaf-> data) 
    {
        if(leaf->right != NULL)
        {
            insert (key, leaf->right);
        }
        leaf->right = new node(key); 
        leaf->right->right = NULL;
        leaf->right->left = NULL;
    }
}
btree::btree()
{
  root=NULL;
}

btree::~btree()
{
  destroy_tree();
}

node *btree::search(int key, node *leaf) 
{
    if(leaf != NULL)
    {
        if (key  == leaf->data)
        {
            return leaf;
        }
        else if(key < leaf->data)
        {
            return search(key,leaf->left);
        }
        else if(key > leaf->data)
        {
            return search(key, leaf->right );
        }
    }
    return NULL;
}

node *btree::search (int key)
{
    return search(key,root);
} 
void btree::insert(int key)
{
    if (root != NULL )
    {
        insert(key, root );
    }
    else
    {
        root = new node(key);
        root->left = NULL;
        root-> right = NULL;
    }
}

void btree::destroy_tree()
{
    destroy_tree(root);
} 

int main()
{
    btree btre; 
    btre.insert(50);
    btre.insert(25);
    btre.insert(32);
    btre.insert(12);
    btre.insert(10);
    btre.insert(21);
    btre.insert(69);
    std::cout<< btre.search(21)<<'\n';
    std::cout<< btre.search(32)<<'\n';
    std::cout<< btre.search(69)<<'\n';
    btre.destroy_tree();
}