#include <bits/stdc++.h> 
using namespace std; 
  
  
/* A binary tree node has data, pointer to left child  
and a pointer to right child */
class Node  
{  
    public: 
    int data;  
    Node *left;  
    Node *right;  
};  
  
// A utility function to create a node  
Node* newNode (int data)  
{  
    Node* temp = new Node(); 
    temp->data = data;  
    temp->left = temp->right = NULL;  
    return temp;  
}  

int ind=0;
Node* build(int n, int pre[], int min, int max)
{
    if(ind>=n)
        return NULL;
    Node* tmp = NULL;
    int x = pre[ind];

    if(x>min && x<max)
    {
        tmp = newNode(x);
        ind++;
        if(ind < n)
        {
            tmp->left = build(n,pre,min,x);
            tmp->right = build(n,pre,x,max);
        }
    }
    return tmp;
}

Node* constructTree(int pre[], int n)
{
    if(!n)
        return NULL;
    ind=0;
    Node* root = build(n, pre, INT_MIN, INT_MAX);
    return root;
}

void printInorder (Node* node)  
{  
    if (node == NULL)  
        return;  
    printInorder(node->left);  
    cout << node->data << " ";  
    printInorder(node->right);  
}  
  
// Driver code  
int main ()  
{  
    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );  
  
    Node *root = constructTree(pre, size);  
  
    cout << "Inorder traversal of the constructed tree: \n";  
    printInorder(root);  
  
    return 0;  
}  