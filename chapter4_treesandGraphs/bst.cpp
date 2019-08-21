#include<bits/stdc++.h>

class node{
    public:
    int key_value;
    node *right;
    node *left;
};

     
class btree
{
    public:
        btree();
        ~btree();
 
        void insert(int key);
        node *search(int key);
        void destroy_tree();
 
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
         
        node *root;
};

btree::btree()
{
  root=NULL;
}

btree::~btree()
{
  destroy_tree();
}

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
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}


node *btree::search(int key, node *leaf)
{
int count =0;
    count+=1; 
    std::cout<<count;
    
  if(leaf!=NULL)
  {
    
    if(key==leaf->key_value)
      {
      std::cout << "mah dikus\n";
    
      return leaf;
      }
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}


void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}


node *btree::search(int key)
{
  return search(key, root);
}

void btree::destroy_tree()
{
  destroy_tree(root);
}

int main()
{
    btree bt;
    
    bt.insert(50);
    bt.insert(25);
    bt.insert(32);
    bt.insert(12);
    bt.insert(10);
    bt.insert(21);
    bt.insert(69);
    std::cout<< bt.search(21)<<'\n';
    std::cout<< bt.search(32)<<'\n';
    std::cout<< bt.search(69)<<'\n';
    bt.destroy_tree();
}
