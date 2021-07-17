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
bool isHeap(struct Node * tree);
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
     cout << isHeap(root)<< endl;
  }
  return 0;
}

int nc;
int count(Node *r)
{
    if(!r)
        return 0;
    return (1+count(r->left) + count(r->right));
}

bool isComplete(Node* r, int i)
{
    if(!r)  
        return 1 ;
    if(i>=nc)
        return 0;
    return (isComplete(r->left, 2*i+1) && isComplete(r->right, 2*i+2) );
}

bool satisfyHeap(Node* r)
{
    if(!r)
        return 1;
    if(!r->left && !r->right)
        return 1;
    if(!r->left)
        return 0;
    if(!r->right)
        return (r->data >= r->left->data);
    
    if(r->data >= r->left->data && r->data>=r->right->data)
        return (satisfyHeap(r->right) && satisfyHeap(r->left));
    return 0;
}


bool isHeap(Node * tree)
{
    if(!tree)
        return 1;
    nc = count(tree);
    if(!isComplete(tree, 0)) 
        return 0;
    if(!satisfyHeap(tree))
        return 0;
    return 1;
}