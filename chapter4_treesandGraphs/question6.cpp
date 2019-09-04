//algorithm to write out next/successor node 
//assume each node has link to its parent
#include<bits/stdc++.h>

//i can use an array too,more space, less time for fetch 
class node {
    public:
    int data;
    node *left, *right;
};

node *newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->left=n->right = nullptr;
} 

node *insert(node *root, int data)
{
    if (root == nullptr)
    {
        return newNode(data);
    }
    if (data< root->data)
    {
        root->left = insert(root->left,data);
    }
    else 
        root->right = insert(root->right, data);
}

node *findmin(node *root)
{
    while (root ->left)
    {
        root = root->left;
    }
    return root;
}

void findsuccessor(node *root, node *&succ, int key )
{
    if (root == nullptr)
    {
        succ = nullptr;
        return;
    }
    if(root->data == key)
    {
        if (root -> right)
            succ = findmin(root ->right);
    }
    else if (key < root->data)
    {
        succ = root;
        findsuccessor(root ->left, succ,key);
    }
    else 
        findsuccessor(root ->right, succ,key);

}

int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	node * root = nullptr;
	for (int key : keys)
		root = insert(root, key);

	// find in-order successor for each key
	for (int key : keys)
	{
		node* prec = nullptr;
		findsuccessor(root, prec, key);

		if (prec != nullptr)
			std::cout << "Successor of node " << key << " is " << prec->data;
		else
			std::cout << "Successor doesn't exists for " << key;

		std::cout << '\n';
	}

	return 0;
}