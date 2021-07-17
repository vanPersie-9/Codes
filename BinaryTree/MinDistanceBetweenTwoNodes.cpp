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
int findDist(Node* ,int ,int );
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
     int a,b;
     cin>>a>>b;
     cout<<findDist(root,a,b)<<endl;
  }
  }
  return 0;
}


bool dist(Node* root, int x, int l, int* d)
{
    if(!root)
        return 0;
    
    if(root->data==x)
    {
        *d=l;
        return 1;
    }
    return (dist(root->left,x,l+1,d) || dist(root->right,x,l+1,d));
}

Node* findLCA(Node* root, int a, int b)
{
    if(!root)
        return NULL;
    if(root->data == a || root->data==b)
        return root;
    Node* l = findLCA(root->left,a,b);
    Node* r = findLCA(root->right,a,b);

    if(l && r)
        return root;
    if(l)
        return l;
    return r;
}

int findDist(Node* root, int a, int b)
{
    Node* lca = findLCA(root,a,b);
    int d1,d2,d3;
    int a1 = dist(root, a, 0, &d1);
    int a2 = dist(root, b, 0, &d2);
    int a3 = dist(root, lca->data, 0, &d3);

    return d1+d2-2*d3;
}