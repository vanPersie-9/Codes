#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}
int largestBst(Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    cout<<largestBst(root)<< endl;
  }
  return 0;
}

struct Info
{
    int sz;
    int min;
    int max;
    int ans;
    bool isBST;
};

Info func(Node* root)
{
    if(!root)
        return {0,INT_MAX,INT_MIN,0,true};
    if(!root->left && !root->right)
        return {1,root->data, root->data,1,true};
    
    Info l = func(root->left);
    Info r = func(root->right);
    Info tmp;
    tmp.sz = l.sz+r.sz+1;

    if(l.isBST && r.isBST)
    {
        if(l.max<root->data && r.min>root->data)
        {
            tmp.ans = tmp.sz;
            tmp.isBST = true;
            tmp.max = r.max;
            tmp.min = l.min;

            return tmp;
        }
    }
    tmp.ans = max(l.ans,r.ans);
    tmp.isBST = false;

    return tmp;
}


int largestBst(Node *root)
{
    if(!root)
        return 0;
    Info tmp = func(root);
    return tmp.ans;
}
