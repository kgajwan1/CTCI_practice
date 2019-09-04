//lowest common ancestor IN BINARY TREE(NOT SEARCH TREE), sans any data structure

#include <bits/stdc++.h>
class Node{
	public:
	int data;
	Node *left, *right;  
};

Node *newNode(int data)
{
	Node *newNode =new Node;
	newNode->data = data;
	newNode->left=newNode->right = NULL;
	return newNode;
}


bool find(Node *root, int data)
{
	if(root == NULL)
		return false;
	if(root->data == data || find(root->left,data)||find (root->right, data))
		return true;
	return false;
}
Node *findLCAUtil(Node *root, int n1, int n2)
{
	if(root == NULL)
		return NULL;
	if(root->data == n1 || root->data == n2)
		return root;
	Node *left_LCA = findLCAUtil(root->left,n1,n2);
	Node *right_LCA = findLCAUtil(root->right,n1,n2);
	//if both are non null, both nodes are in different sub trees
	if(left_LCA && right_LCA)
		return root;
	return (left_LCA != NULL)? left_LCA: right_LCA; 
}

Node *findLCA(Node *root, int n1, int n2)
{
	Node *LCA = findLCAUtil(root, n1, n2); 
	if(!LCA)
		return NULL;
	if (   (LCA->data != n1 && LCA->data != n2) // n1 & n2 are on different path
        || (LCA->data == n1 && find(LCA, n2)) // n1 lies b/w root and n2
        || (LCA->data == n2 && find(LCA, n1))) {  // n2 lies b/w root and n1
		return LCA; 
    }
	return NULL;
}

int main() 
{ 
	// Let us create binary tree given in the above example 
	Node * root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 
	Node *lca = findLCA(root, 2, 4); 
	if (lca != NULL) 
	std::cout << "LCA(2,4) = " << lca->data; 
	else
	std::cout << "\nKeys are not present "; 

	lca = findLCA(root, 4, 10); 
	if (lca != NULL) 
	std::cout << "nLCA(4, 10) = " << lca->data; 
	else
	std::cout << "\nKeys are not present "; 
	return 0; 
}