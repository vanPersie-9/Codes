// A C++ program to remove BST keys outside the given range 
#include<stdio.h> 
#include <iostream> 

using namespace std; 

// A BST node has key, and left and right pointers 
struct node 
{ 
	int key; 
	struct node *left; 
	struct node *right; 
}; 

// Removes all nodes having value outside the given range and returns the root 
// of modified tree 
node* removeOutsideRange(node* root, int min, int max);
// A utility function to create a new BST node with key as given num 
node* newNode(int num) 
{ 
	node* temp = new node; 
	temp->key = num; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to insert a given key to BST 
node* insert(node* root, int key) 
{ 
	if (root == NULL) 
	return newNode(key); 
	if (root->key > key) 
	root->left = insert(root->left, key); 
	else
	root->right = insert(root->right, key); 
	return root; 
} 

// Utility function to traverse the binary tree after conversion 
void inorderTraversal(node* root) 
{ 
	if (root) 
	{ 
		inorderTraversal( root->left ); 
		cout << root->key << " "; 
		inorderTraversal( root->right ); 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	node* root = NULL; 
	root = insert(root, 6); 
	root = insert(root, -13); 
	root = insert(root, 14); 
	root = insert(root, -8); 
	root = insert(root, 15); 
	root = insert(root, 13); 
	root = insert(root, 7); 

	cout << "Inorder traversal of the given tree is: "; 
	inorderTraversal(root); 

	root = removeOutsideRange(root, 13, 13); 

	cout << "\nInorder traversal of the modified tree is: "; 
	inorderTraversal(root); 

	return 0; 
} 


node* removeOutsideRange(node* root, int min, int max)
{
    if(!root)
        return NULL;
    
    root->left = removeOutsideRange(root->left,min,max);
    root->right = removeOutsideRange(root->right,min,max);

    if(root->key < min)
        return root->right;
    if(root->key>max)
        return root->left;
    return root;
}