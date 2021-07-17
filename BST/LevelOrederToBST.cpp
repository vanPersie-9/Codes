#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}
Node* constructBst(int arr[], int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}

Node* build(Node* root, int x)
{
    Node* tmp = new Node(x);
    if(!root)
        return tmp;
    if(x<=root->data)
        root->left = build(root->left,x);
    else
        root->right = build(root->right,x);
    return root;
}

Node* constructBst(int arr[], int n)
{
    
    // Code here
    if(!n)
        return NULL;
    Node* root = NULL;
    for(int i=0;i<n;i++)
        root = build(root, arr[i]);
    return root;
}
